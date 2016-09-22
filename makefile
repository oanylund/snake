IDIR=include
CC=gcc
CFLAGS= -std=c99 -I$(IDIR)

ODIR=obj

_DEPS = list.h snake.h statemachine.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o list.o snake.o statemachine.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

snake: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

rebuild: clean snake

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
