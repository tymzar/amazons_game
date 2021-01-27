#ifndef LIBINTERACTIVE_H_INCLUDED
#define LIBINTERACTIVE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Variables.h"

/**
 * @brief Function which generates the board and randomly sets artifacts and treasures.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board.
 * 
 * @note Field board included in game structure holds player's ID, value of a treasure and type of artifact.
 * 
 * @warning Randomly choosen values and artifacts have adjusted suitable frequency.
 */
void generate_board(Game *game);
/**
 * @brief Function prints generated board.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board, g_scores.
 * @note Field board included in game structure holds player's ID, value of a treasure and type of artifact.
 * @note int g_scores displays held in the structure amount of points collected by the current player.
 */
void present_board_state(Game *game);
/**
 * @brief Function switches between players.
 * 
 * @param current_player we use a pointer to get to the value.
 * @note Function switch_player is always called by a different function which takes the game structure.
 */
void switch_player(int *current_player);
/**
 * @brief Function places an amazon.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board.
 * @param player current player's ID which is switched by switch_player function.
 * 
 */
void place_amazon(Game *game, int player);
/**
 * @brief One of the leading functions, it asks the user about amount of amazons and coordinates on which the player places the amazons.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board, p.
 * 
 * @note Field board included in game structure holds player's ID, value of a treasure and type of artifact.
 * 
 * @note Position p included in game structure holds amazons coordinates.
 */
void init_placement(Game *game);


    

#endif
