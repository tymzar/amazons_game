#include <stdlib.h>
#include <stdio.h>

#include "board_entities.h"
#include "board.h"
#include "file_parser.h"

/**
 * @brief read board info from specified file buffer into board data structure
 * 
 * @param file file buffer to file from which you want to read the data
 * @param board pointer to board structure
 */
void initialize_board(FILE *file, Board *board) {
  char tokens[board->height * board->width * 4][4];
  tokenize_board_file(file, board->height, board->width, tokens);
  board->fields = (Field*) malloc(sizeof(Field) * board->height * board->width);
  for (int row = 0; row < board->height; row++) {
    for (int column = 0; column < board->width; column++) {
      board->fields[row * board->width + column] = field_from_token(tokens[row * board->width + column]);
    }
  }
}

/**
 * @brief creates data structure describing the field from string of characters loaded from file
 * 
 * @param token char array describing field from which we want load the data
 *    first char describes amount of treasure (number expected)
 *    second char describes artifact (number expected)
 *    third char describes player id (number expected)
 *    last character is reserved for \0 character
 * @return Field data structure containing information about a field
 */
Field field_from_token(char token[4]) {
  Field field;
  field.value = (int)(token[0] - '0');
  field.artifact = (EArtifact)(token[1] - '0');
  field.player_id = (int)(token[2] - '0');
  return field;
}

/**
 * @brief serializes data structure describing the field into array of characters (token) which can be written to file
 * 
 * @param field data structure describing field that we will use to generate the token
 * @param token pointer to array of char to which we will save the token
 */
void field_to_token(Field field, char token[4]) {
  token[0] = field.value + '0';
  token[1] = (int)(field.artifact) + '0';
  token[2] = field.player_id + '0';
}

// get pointer to field using 1 based counting
/**
 * @brief Get pointer to field on given position coordinates
 * @note we are using 1 based counting for position
 * @param board struct containing board info
 * @param position struct containing info about position
 * @return pointer to field on the board, NULL if field doesnt exist
 */
Field *get_field(Board board, Position position) {
  int is_out_of_bounds= position.x > board.width ||
                        position.x < 1 ||
                        position.y > board.height ||
                        position.y < 1;
  if (is_out_of_bounds) {
    // printf("Position provided to get field is out of bounds \n");
    // printf("x: %d, y: %d \n", position.x, position.y);
    return NULL;
  }
  int x = position.x - 1;
  int y = position.y - 1;
  return &(board.fields[y * board.width + x]);
}
