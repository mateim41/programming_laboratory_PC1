CC = clang
CFLAGS = -Wall -g
TARGET = p11  # The name of your executable

# The default rule: compiles all .c files in this folder
all: $(TARGET)

$(TARGET): *.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)