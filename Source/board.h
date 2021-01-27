#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include <stdio.h>

#include "board_entities.h"

typedef struct {
  Field *fields;
  int height;
  int width;
} Board;

void initialize_board(FILE *file, Board *board);

Field field_from_token(char token[4]);

void field_to_token(Field field, char token[4]);

Field *get_field(Board board, Position position);

#endif // BOARD_H