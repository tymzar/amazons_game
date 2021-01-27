#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libinteractive.h"
#include "Variables.h"
#include "Libavailable.h"
#include "Libmovement.h"



void generate_board(Game *game) {
    printf("Generating game board...\n");

    // To define limits of the significant artifacts
    // it is first row == border
    int arrArtifact[10] = {0,0,0,0,0,1,2,2,3,3};
    
    int arrValue[17] = {5,4,4,3,3,2,2,2,1,1,1,1,0,0,0,0,0};

   
    for (int column = 0; column < INTERNAL_BOARD_SIZE; column++) {
        game->board[0][column].playerID = 9;
    }
    for(int row = 1; row <= BOARD_SIZE; row++){
        game->board[row][0].playerID = 9; // it is first column = border
        for(int column = 1; column <= BOARD_SIZE; column++) {

            game->board[column][row].value = arrValue[rand()%17]; // Assigning random value from 0 - 5 
            game->board[column][row].artifact = arrArtifact[rand() % 10]; // Assigning random value from 0 - 4
            game->board[column][row].playerID = 0; // Assigning 0 because all fields are unoccupied
        }
        game->board[row][INTERNAL_BOARD_SIZE-1].playerID = 9; // it is last column = border
    }
    // it is last row = border
    for (int column = 0; column < INTERNAL_BOARD_SIZE; column++) {
        game->board[INTERNAL_BOARD_SIZE-1][column].playerID = 9;
    }

    printf("Board generated!\n");
}

void present_board_state(Game *game) {
    // print the state of the board in console
    for(int row = 0; row <= BOARD_SIZE; row++) {
        for(int column = 0; column <= BOARD_SIZE; column++) {
            if(row == 0) {
                if(column == 0) { printf("| %d ", column); }
                else { printf("|   %d   ", column); }
            } else if(column == 0 && row !=0) {
                if(row == 10) {
                    printf("| %d", row);
                } else if(row < 10) {
                    printf("| %d ", row);
                } else {
                    printf("| %d ", row);
                }
            }
            if (row > 0 && column > 0) {
                printf("| %d %d %d ", game->board[row][column].value, game->board[row][column].artifact, game->board[row][column].playerID);
            }
        }
        if(row == 0) { 
            printf("|\n");
        } else {
            printf(" |\n");
        }        
    }
    printf("Score: Player1 - %d, Player2 - %d\n", game->g_scores[0], game->g_scores[1]);
}

void switch_player(int *current_player) 
{
    if (*current_player == 1)
    { 
        *current_player = 2;
    }
    else{ 
        *current_player = 1;
    }
}

void place_amazon(Game *game, int player) {
  game->board[game->p.y][game->p.x].playerID = player;
  game->board[game->p.y][game->p.x].value = 0;
  game->board[game->p.y][game->p.x].artifact = 0;
}

void init_placement(Game *game) {
    
    int amazons = 0;
    int player_id = 1;
    generate_board(game);

    present_board_state(game);

    printf("Input amount of the amazons: ");

   while(scanf("%d", &amazons)==0){
       printf("\nNon-numeric input detected. Input a number.\n");
       scanf(" %*s ");
       printf("Input amount of the amazons: ");
     }
   
    for (int i = 0; i < amazons*2 ; i++) {
        
        position p = { .x=0, .y=0 };
        while (1) {
            present_board_state(game);
            printf("Player %d, input coordinates for amazon.\n", player_id);
            printf("Cordinate X: ");

            while(scanf("%d", &game->p.x)==0){
                printf("\nNon-numeric input detected. Input a number.\n");
                scanf(" %*s ");
                printf("Coordinate X: ");
            }
            printf("Coordinate Y: ");
            while(scanf("%d", &game->p.y)==0){
                printf("\nNon-numeric input detected. Input a number.\n");
                scanf(" %*s ");
                printf("Coordinate Y: ");
            }
            if (can_place_here(game)) break;
        }
        place_amazon(game, player_id);
        
        switch_player(&player_id);
    }
}
