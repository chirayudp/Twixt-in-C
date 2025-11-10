# Compiler and flags
CC = gcc
CFLG = -Wall -Wextra -std=c11

# Object files
OBG = interface.o game.o
# Final executable name
TARG = run
	
# Default rule
$(TARG): $(OBG)
	$(CC) $(CFLG) $(OBG) -o $(TARG)

# Generic rule for compiling .c into .o
%.o: %.c
	$(CC) $(CFLG) -c $< -o $@

# Clean up
clean:
	rm -f $(OBG) $(TARG)
