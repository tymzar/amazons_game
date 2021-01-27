#include "Libavailable.h"
#include "Variables.h"
#include <stdio.h>
#include "Libinteractive.h"
#include <math.h>


int is_move_possible(Game *game)
 {
    for(int i = 1; i< 11; i++){
        for(int j = 1; j< 11; j++){

            game->p.x = i;
            game->p.y = j;

            if(game->board[game->p.y][game->p.x].playerID == game->current_player){
                if(can_amazon_move(game)){
                    return 1;
                }
            }
        }
    }
    return 0;
}



int can_amazon_move(Game *game) {
    // takes coordinates of amazon on the board
    // and returns whether it can move
    int can_move = 0;
    if (game->board[game->p.y-1][game->p.x-1].playerID == 0) { can_move = 1; }
    if (game->board[game->p.y][game->p.x-1].playerID   == 0) { can_move = 1; }
    if (game->board[game->p.y][game->p.x+1].playerID   == 0) { can_move = 1; }
    if (game->board[game->p.y-1][game->p.x+1].playerID == 0) { can_move = 1; }
    if (game->board[game->p.y-1][game->p.x].playerID   == 0) { can_move = 1; }
    if (game->board[game->p.y+1][game->p.x].playerID   == 0) { can_move = 1; }
    if (game->board[game->p.y+1][game->p.x-1].playerID == 0) { can_move = 1; }
    if (game->board[game->p.y+1][game->p.x+1].playerID == 0) { can_move = 1; }

    return can_move;
}



int is_diagonall(Game *game){
    int xCor = abs(game->p.x - game->pAmazon.x);
    int yCor = abs(game->p.y - game->pAmazon.y);

    return (xCor == yCor) ? 1 : 0;
}


int is_path_clear(Game *game, ERoadType type) {
    
    // type is trip of amazon verticall(1), horizontall(2), diagonall (3)
    switch(type)
    {
        case VERTICALL:
            if((game->pAmazon.y - game->p.y) < 0){
                for(int i=game->pAmazon.y; i<game->p.y; i++){
                    if(game->board[i+1][game->pAmazon.x].playerID!=0){
                        printf("There is an obstacle on the path\n");
                        return 0;
                    }
                }
            }else{
                for(int i=game->p.y; i<game->pAmazon.y; i++){
                    if(game->board[i][game->pAmazon.x].playerID!=0){
                        printf("There is an obstacle on the path\n");
                        return 0;
                    }
                }
            }
            break;
        case HORIZONTALL:
            if((game->pAmazon.x - game->p.x) < 0){
                for(int i=game->pAmazon.x; i<game->p.x; i++){
                    if(game->board[game->pAmazon.y][i+1].playerID!=0){
                        printf("There is an obstacle on the path\n");
                        return 0;
                    }
                }
            }else{
                for(int i=game->p.x; i < game->pAmazon.x; i++){
                    if(game->board[game->pAmazon.y][i].playerID!=0){
                        printf("There is an obstacle on the path\n");
                        return 0;
                    }
                }
            }
            break;
        case DIAGONALL:
            if((game->pAmazon.x - game->p.x) < 0){
                if((game->pAmazon.y - game->p.y) < 0){
                    
                    for(int i=game->pAmazon.x; i < game->p.x; i++){
                        int temp = 1;
                        if(game->board[game->pAmazon.y+temp][game->pAmazon.x+temp].playerID!=0){
                            printf("There is an obstacle on the path\n");
                            return 0;
                        }
                        temp++;
                    }
                }else{
                    for(int i=game->pAmazon.x; i < game->p.x; i++){
                        int temp = 1;
                        if(game->board[game->pAmazon.y-temp][game->pAmazon.x+temp].playerID!=0){
                            printf("There is an obstacle on the path\n");
                            return 0;
                        }
                        temp++;
                    }  
                }   
            }else{
                if((game->pAmazon.y - game->p.y) < 0){
                    for(int i=game->p.x; i < game->pAmazon.x; i++){
                        int temp = 1;
                        if(game->board[game->pAmazon.y+temp][game->pAmazon.x-temp].playerID!=0){
                            printf("There is an obstacle on the path\n");
                            return 0;
                        }
                        temp++;
                    }  
                }else{
                    for(int i=game->p.x; i < game->pAmazon.x; i++){
                        int temp = 1;
                        if(game->board[game->pAmazon.y-temp][game->pAmazon.x-temp].playerID!=0){
                            printf("There is an obstacle on the path\n");
                            return 0;
                        }
                        temp++;
                    }
                }
            }
            break;
    }
  
    return 1;

}

int can_amazon_move_here(Game *game) {
    // cheack vertically, horizontally, diagonally from amazon if amazon can move and of the field is free
    if(game->p.x == game->pAmazon.x){
        return is_path_clear(game,(ERoadType)1);
        }
    if(game->p.y == game->pAmazon.y){
        return is_path_clear(game,(ERoadType)2);
        }
    if(is_diagonall(game)){
        return is_path_clear(game,(ERoadType)3);
    }  
    
    printf("Amazon can only shoot vertically, horizontally and diagonally\n");

    return 0;
}


int can_amazon_throw_spear_here(Game *game) {
    // cheack vertically, horizontally, diagonally from amazon if amazon can move and of the field is free
    if(game->p.x == game->pAmazon.x){
        if(game->board[game->p.y][game->p.x].playerID == 0){
            return 1;
        }    
    }
    if(game->p.y == game->pAmazon.y){
        if(game->board[game->p.y][game->p.x].playerID == 0){
            return 1;
        } 
    }
    if(is_diagonall(game)){
        if(game->board[game->p.y][game->p.x].playerID == 0){
            return 1;
        } 
    }  
    
    printf("Amazon can only shoot vertically, horizontally and diagonally\n");

    return 0;
}

int can_place_here(Game *game) {
    if (game->p.x < 1 || game->p.y < 1) 
    {
        printf("Under boundries\n");
        return 0; 
        }
    if (game->p.x > BOARD_SIZE || game->p.y > BOARD_SIZE)  {
        printf("Over boundries\n");
        return 0; 
        }
    if (game->board[game->p.y][game->p.x].playerID != 0) {
        printf("Field is occupied\n");
        return 0; 
        }
        printf("Sucessful placement\n");
      return 1;
}
