#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cli_parser.h"
#include "error_codes.h"
#include "game.h"

/**
 * @brief parse command line parameters. Check their validity and return appropriate error. If everything is correct, fill game object with data
 * 
 * @param argc number of command line arguments
 * @param argv array of command line arguments
 * @param game pointer to game object that we want to fill with data
 */
void cli_parse(int argc, char *argv[], Game *game) {

  if (argc < 2) {
    printf("No command line parameters given \n");
    exit(INTERNAL_ERROR);
  }
  
  if (strcmp(argv[1], "name") == 0) {
    printf("%s", "GROUP_E");
    exit(PROGRAM_SUCCESS);
  }

  game->phase = read_phase(argc, argv);
  if (game->phase == PLACEMENT) {
    game->amazons = read_amazons(argc, argv);
  } else {
    game->amazons = 0;
  }

  if (game->phase == PLACEMENT) {
    if (argc >= 5) {
      strncpy(game->input_file_name, argv[3], 64);
      strncpy(game->output_file_name, argv[4], 64);
    } else {
      printf("Insufficient amount of parameters \n");
      printf("Please make sure that input and output filenames are provided \n");
      exit(INTERNAL_ERROR);
    }
  } else if (game->phase == MOVEMENT) {
    if (argc >= 4) {
      strncpy(game->input_file_name, argv[2], 64);
      strncpy(game->output_file_name, argv[3], 64);
    } else {
      printf("Insufficient amount of parameters \n");
      printf("Please make sure that input and output filenames are provided \n");
      exit(INTERNAL_ERROR);
    }
  }

}

/**
 * @brief reads phase of the game from command line parameters
 * 
 * @param argc number of command line parameters
 * @param argv array of command line parameters
 * @return EPhase, enum describing which phase of the game are we in
 */
EPhase read_phase(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Not enough parameters \n");
    printf("program failed to read the phase of the game \n");
    exit(INTERNAL_ERROR);
  }

  char *param = argv[1];
  char *rest = param;
  char *param_name = strtok_r(rest, "=", &rest);
  EPhase phase;

  if (strcmp(param_name, "phase") == 0) {
    char *param_val = strtok_r(rest, "=", &rest);
    if (strcmp(param_val, "placement") == 0) { phase = PLACEMENT; }
    else if (strcmp(param_val, "movement") == 0) { phase = MOVEMENT; }
    else {
      printf("Phase parameter not specified correctly \n");
      printf("Phase should be either 'placement' or 'movement' but got '%s' \n", param_val);
      exit(INTERNAL_ERROR);
    }
  } else {
    printf("Incorrect first parameter. Expected 'phase' but got '%s' \n", param_name);
    exit(INTERNAL_ERROR);
  }

  return phase;
}

/**
 * @brief read amount of amazons from the command line parameters
 * 
 * @param argc number of command line paramaters
 * @param argv array of command line parameters
 * @return int amount of amazons that we can place
 */
int read_amazons(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Not enough parameters \n");
    printf("Program failed to read amount of amazons \n");
    exit(INTERNAL_ERROR);
  }

  char *param = argv[2];
  char *rest = param;
  char *param_name = strtok_r(rest, "=", &rest);
  int amazons;

  if (strcmp(param_name, "amazons") == 0) {
    char *param_val = strtok_r(rest, "=", &rest);
    amazons = atoi(param_val);
    if (amazons < 1) {
      printf("Provided amount of amazons (%d) is not correct \n", amazons);
      exit(INTERNAL_ERROR);
    }
  } else {
    printf("Invalid second parameter. Expected 'amazons' but got '%s' \n", param_name);
    exit(INTERNAL_ERROR);
  }

  return amazons;
}