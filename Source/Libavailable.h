#ifndef Libavailable_H_INCLUDED
#define Libavailable_H_INCLUDED
#include "Variables.h"

/**
 * @brief Function checks whether the move is possible.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board, p.
 * 
 * @returns int which is giving result 0 if there are no free fields next to the amazon and 1 if there is.
 */
int is_move_possible(Game *game);
/**
 * @brief Function that checks all fields next to the amazon and returns whether the amazon can move.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board, p.
 * 
 * @note - We are using p as position of amazon and current_player as active player ID. 
 * 
 * @note Field board included in game structure holds player's ID, value of a treasure and type of artifact.
 * 
 * @returns int which is giving result 0 if there are no free fields next to the amazon and 1 if there is.
 */
int can_amazon_move(Game *game);
/**
 * @brief Function that checks whether the amazon wants to move in diagonall direction.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board, p, pAmazon.
 * 
 * @note We are using p as position of amazon and current_player as active player ID. 
 * 
 * @note We are using pAmazon as a position that we want to move to. 
 * 
 * @note Field board holds player's ID, value of a treasure and type of artifact.
 * 
 * @returns int which is giving result 0 if false and 1 if true.
 */

int is_diagonall(Game *game);
/**
 * @brief Function detects which direction the amazon wants to one.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board, p, pAmazon.
 * 
 * @param type structure which holds which type of road the amazon will take(verticall,diagonall,horizontall)
 * 
 * @note We are using p as position of amazon and current_player as active player ID. 
 * 
 * @note We are using pAmazon as a position that we want to move to. 
 * 
 * @note Field board holds player's ID, value of a treasure and type of artifact.
 * 
 * @returns int which is giving result 0 if false and 1 if true.
 */

int is_path_clear(Game *game, ERoadType type);
/**
 * @brief Function that checks in what direction amazon wants to move.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: p, pAmazon.
 * 
 * @note We are using p as position of amazon and current_player as active player ID. 
 * 
 * @note We are using pAmazon as a position that we want to move to. 
 * 
 * @returns int which is giving result 0 if none of them and is_path_clear() function if one of them.
 */
int can_amazon_move_here(Game *game);
/**
 * @brief Function that checks in what direction amazon wants to move.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board, p, pAmazon.
 * 
 * @note We are using p as position of amazon and current_player as active player ID. 
 * 
 * @note We are using pAmazon as a position that we want to move to. 
 * 
 * @note Field board holds player's ID, value of a treasure and type of artifact.
 * 
 * @returns int which is giving result 0 if throw is impossible and 1 if possible.
 */

int can_amazon_throw_spear_here(Game *game);
/**
 * @brief Function that checks whether the player can place amazon on choosen spot.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board, p.
 * 
 * @note We are using p as position of amazon and current_player as active player ID. 
 * 
 * @note Field board holds player's ID, value of a treasure and type of artifact.
 * 
 * @returns int which is giving result 0 if placement is impossible and 1 if possible.
 */
int can_place_here(Game *game);
#endif