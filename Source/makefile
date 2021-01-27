CC=gcc
CFLAGS=-I.
DEPS_AUTONOMOUS = board_entities.h Variables.h
OBJ_AUTONOMOUS = main_autonomous.o board.o file_parser.o game.o cli_parser.o
OBJ_INTERACTIVE = main_interactive.o Libavailable.o Libinteractive.o Libmovement.o

.PHONY: default
default: autonomous ;

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

autonomous: $(OBJ_AUTONOMOUS)
	$(CC) -o $@ $^ $(CFLAGS)


interactive: $(OBJ_INTERACTIVE)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o *~