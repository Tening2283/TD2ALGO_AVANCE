

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = src/main.c src/exercice1.c src/exercice2.c src/exercice3.c src/exercice4.c src/exercice5.c src/exercice6.c src/exercice7.c src/exercice8.c
OBJ = $(SRC:.c=.o)
EXEC = programme

all: $(EXEC)

$(EXEC): $(SRC)
    $(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
    rm -f $(EXEC) $(OBJ)

run: $(EXEC)
    ./$(EXEC)