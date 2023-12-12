# Makefile for compiling cec.c using gcc and executing kissat

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -pedantic

# Source file
SOURCE = cec.c

# Output file
OUTPUT = cec

# Default target
all: $(OUTPUT)

# Rule to create the executable
$(OUTPUT): $(SOURCE)
    $(CC) $(CFLAGS) -o $(OUTPUT) $(SOURCE)

# Target to compare input files and generate output
cmp:
    ./$(OUTPUT) ../gates/$(input1).circ ../gates/$(input2).circ >> output.txt

# Target to run kissat
run_kissat:
    cd ../../kissat/build && ./kissat ../../tp_verif_massoc-master/C/output.txt

# Clean target to remove generated files
clean:
    rm -f $(OUTPUT)
