CC := clang
CFLAGS := -std=c23 -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wshadow -Werror -g 
TARGET := vector
SRC := main.c vector.c
OBJ := $(SRC:.c=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(OBJ) $(TARGET)
