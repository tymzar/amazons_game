#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_parser.h"
#include "error_codes.h"
#include "game.h"

/**
 * @brief load game state from file. Name of the file is stored inside the game structure
 * 
 * @param game pointer to game object
 */
void load_game_state(Game *game) {
  FILE *file = fopen(game->input_file_name, "r");
  if (file == NULL) {
    printf("Cannot open game state file \"%s\" \n", game->input_file_name);
    exit(INPUT_FILE_ERROR);
  }

  read_board_size(file, &game->board);
  initialize_board(file, &game->board);
  read_player_info(file, game);

  fclose(file);
}

/**
 * @brief reads size of board specified in the file
 * 
 * @param file pointer to file buffer from which we want to load the size
 * @param board pointer to board structure
 */
void read_board_size(FILE *file, Board *board) {
  rewind(file);
  char line[MAX_LINE_WIDTH];
  fgets(line, MAX_LINE_WIDTH, file);
  char *token;
  char *rest = line;
  token = strtok_r(rest, " ", &rest);
  board->height = atoi(token);
  token = strtok_r(rest, " ", &rest);
  board->width = atoi(token);
}

/**
 * @brief reads part of the file describing the board state and turns it into array of string tokens describing fields
 * 
 * @param file pointer to file buffer
 * @param height height of the board
 * @param width width of the board
 * @param tokens array to which we want to load the tokens
 */
void tokenize_board_file(FILE *file, int height, int width, char tokens[][4]) {
  rewind(file);
  char line[MAX_LINE_WIDTH];
  char *token;
  // read first line but ignore the contents so that we skip to the board state
  fgets(line, MAX_LINE_WIDTH, file);
  // loop through lines with board state information
  for (int row = 0; row < height; row++) {
    fgets(line, MAX_LINE_WIDTH, file);
    char *rest = line;
    for (int column = 0; column < width; column++) {
      token = strtok_r(rest, " ", &rest);
      strcpy(tokens[row * width + column], token);
    }
  }
}

/**
 * @brief loads information about players from file to game object
 * 
 * @param file pointer to file buffer
 * @param game pointer to game object
 */
void read_player_info(FILE *file, Game *game) {
  rewind(file);
  char line[MAX_LINE_WIDTH];
  // skip to the part of the file which stores player info
  for (int row = 0; row < game->board.height + 1; row++) {
    fgets(line, MAX_LINE_WIDTH, file);
  }

  // Load player information from the file
  char *token;
  int index = 0;
  while (fgets(line, MAX_LINE_WIDTH, file)) {
    char *rest = line;
    token = strtok_r(rest, " ", &rest);
    strcpy(game->players[index].name, token);
    token = strtok_r(rest, " ", &rest);
    game->players[index].id = atoi(token);
    token = strtok_r(rest, " ", &rest);
    game->players[index].points = atoi(token);
    index++;
  }
  game->num_players = index;

  // Check if our team is present on the list
  int present = 0;
  for (int i = 0; i < game->num_players; i++) {
    if (strcmp(game->players[i].name, "GROUP_E") == 0) present = 1;
  }
  // if not present, add to player list
  if (!present) {
    strcpy(game->players[index].name, "GROUP_E");
    game->players[index].id = index+1;
    game->players[index].points = 0;
    game->num_players += 1;
  }
}

/**
 * @brief save current game state to file
 * 
 * @param game pointer to game object
 */
void write_game_state(Game *game) {
  FILE *file = fopen(game->output_file_name, "w");

  fprintf(file, "%d %d\n", game->board.height, game->board.width);

  for (int row = 1; row <= game->board.height; row++) {
    for (int column = 1; column <= game->board.width; column++) {
      Position p = { .x=column, .y=row };
      Field *f = get_field(game->board, p);
      char token[4];
      field_to_token(*f, token);
      fprintf(file, "%s", token);
      if (column < game->board.width) fprintf(file, " ");
    }
    fprintf(file, "\n");
  }

  for (int index = 0; index < game->num_players; index++) {
    if (index == game->num_players-1) {
      fprintf(file, "%s %d %d",
        game->players[game->num_players-1].name,
        game->players[game->num_players-1].id,
        game->players[game->num_players-1].points
      );
    } else {
      fprintf(file, "%s %d %d\n",
        game->players[index].name,
        game->players[index].id,
        game->players[index].points
      );
    }
  }

  fclose(file);
}