##
## EPITECH PROJECT, 2023
## B-CCP-400-MPL-4-1-panoramix-marlon.pegahi
## File description:
## Makefile
##

SRC = src/main.c \
		src/alpha_majmin.c \
		src/linked_string/linked_string.c \
		src/linked_string/linked_string_bis.c \
		src/my_revstr.c

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra -Werror

CPPFLAGS = -I./include

TARGET = FASTAtools

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
