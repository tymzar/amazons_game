#ifndef LIBMOVEMENT_H_INCLUDED
#define LIBMOVEMENT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Variables.h"
#include "Libavailable.h"
#include "Libinteractive.h"

/**
 * @brief Function takes amazon place coordinates from user and passes it to move_amazon or af player stood on horse automatically goes threw.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board.
 * @return EArtifact - which indicates the artifact found on the current field.
 */

EArtifact move_amazon(Game *game);
/**
 * @brief Function ask the user for coordinates and places an arrow on the board.
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board, current_player.
 * 
 *  @note Position p included in game structure holds amazons coordinates.
 * 
 * @note Field board holds player's ID, value of a treasure and type of artifact.
 */
void shootArrow(Game *game) ;

/**
 * @brief Function adds score to the current_player's score.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board, pAmazon, current_player.
 * 
 * @note We are using pAmazon as a position that we want to move to. 
 * 
 * @note Field board holds player's ID, value of a treasure and type of artifact.
 */
void throw_spear(Game *game);

/**
 * @brief Function that controls the flow of the game, checks which artifact is currently played by the player.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: current_player.
 */
void init_movement(Game *game);

/**
 * @brief add value to players scoreboard.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: current_player.
 */

void add_score(Game *game);



#endif