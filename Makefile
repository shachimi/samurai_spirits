BIN=samurai-spirit
OBJS=src/board/board.o src/card/brigand.o src/players/player.o    	\
src/samurai/samurai.o src/village/village.o src/village/farm.o 		\
src/village/family.o

LIBS=
CFLAGS=-Wall -Wextra -Werror
CC=g++

all: $(BIN)

%.o: %.c
	$(CC) -g $(CFLAGS) -c $^ -Isrc -o $@

%.o: %.cc
	$(CC) -g $(CFLAGS) -c $^ -Isrc -o $@

$(BIN): $(OBJS) src/main.o
	$(CC) -g $(CFLAGS) $^ -Isrc -o $@

tags:
	@etags -o TAGS `find . -name '*.[hc][hc]'`

clean:
	@find . -name '*.o' -delete -print
	@find . -name '*_flymake.*' -delete -print

.phony:
	clean check tags
