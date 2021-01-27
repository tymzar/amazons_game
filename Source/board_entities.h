#ifndef BOARD_ENTITIES_H
#define BOARD_ENTITIES_H

/// This file contains structures used in autonomous game.

/**
 * @brief enum variable containing all possible types of artifacts on the board
 * 
 */
typedef enum {
  NONE = 0,
  HORSE = 1,
  BROKEN_ARROW = 2,
  SPEAR = 3,
} EArtifact;

/**
 * @brief structure describing fields on the board
 * 
 */
typedef struct {
  int value;
  EArtifact artifact;  
  int player_id;
} Field;

/**
 * @brief structure describing coordinates on the board
 * 
 */
typedef struct {
  int x;
  int y;
} Position;

#endif // BOARD_ENTITIES_H