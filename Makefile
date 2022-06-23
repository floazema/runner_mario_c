##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

EXEC	= my_runner

PROG	= 	myrunner.c			\
			score.c				\
			gravitycolision.c	\
			background.c		\
			init.c				\
			map.c				\
			jump.c

CSFML	=	-lcsfml-graphics -lcsfml-system		\
			-lcsfml-window -lcsfml-audio

LIB	=	libmy.a

SRC	=	lib/my/my_putchar.c		\
		lib/my/my_put_nbr.c		\
		lib/my/my_putstr.c		\
		lib/my/my_strcat.c		\
		lib/my/my_strcpy.c		\
		lib/my/my_strdup.c		\
		lib/my/my_revstr.c		\
		lib/my/my_strlen.c		\
		lib/my/my_itoa.c

OBJ	=	$(SRC:.c=.o)


all: 	$(LIB)
	gcc -o $(EXEC) $(PROG) $(CSFML) -I include/ -L ./ -lmy

$(LIB):	 $(OBJ)
	ar rc $(LIB) $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f *~
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ)
	rm -f ./lib/$(LIB)
	rm -f $(EXEC)

re: fclean all
