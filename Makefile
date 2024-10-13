CC = gcc
SRC = src
BIN = bin
CFLAGS = -g -Wall -Wextra -Wshadow -Wconversion -Wunreachable-code -fsanitize=address -fsanitize=undefined
LFLAGS = -g -lcurses -fsanitize=address -fsanitize=undefined
AFLAGS = -fverbose-asm -masm=intel
TARGET = chess

SRCS = ...

all: mkdir asm obj elf

# create bin directory
mkdir:
	mkdir -p $(BIN)

# produce assembly code in bin directory
asm:
	$(CC) $(AFLAGS) -S $(SRC) -o $(BIN)/$(TARGET).s

# produce object file in bin directory
obj:
	$(CC) $(CFLAGS) -c $(SRC) -o $(BIN)/$(TARGET).o

# produce executable in bin directory from object file
elf:
	$(CC) $(BIN)/$(TARGET).o -o $(BIN)/$(TARGET) $(LFLAGS)

# run the executable
run:
	./$(BIN)/$(TARGET)

# clean up
clean:
	rm -rf $(BIN)
