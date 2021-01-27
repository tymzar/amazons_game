#ifndef GAME_H
#define GAME_H

#include "board.h"

#define MAX_PLAYERS 8

typedef struct {
  char name[16];
  int id;
  int points;
} Player;

typedef enum {
  PLACEMENT,
  MOVEMENT,
} EPhase;

typedef struct {
  Board board;
  EPhase phase;
  Player players[MAX_PLAYERS];
  int amazons;
  int num_players;
  char input_file_name[64];
  char output_file_name[64];
} Game;

Game create_game(int argc, char *argv[]);

int count_our_amazons(Game *game);

void place_amazon_randomly(Game *game);

int get_our_id(Game *game);

#endif // GAME_H