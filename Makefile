CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = my_mastermind
SRCS = my_mastermind.c secretcode.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

my_mastermind.o: my_mastermind.c secretcode.h
	$(CC) $(CFLAGS) -c $< -o $@

secretcode.o: secretcode.c secretcode.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
