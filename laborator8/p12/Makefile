CC = gcc
CFLAGS = -Wall -g
LIBS = -lm
TARGET = p12  # The name of your executable

# The default rule: compiles all .c files in this folder
all: $(TARGET)

$(TARGET): *.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f $(TARGET)