SRC		= get_next_line \
		get_next_line_utils \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC)))

HEADERS	= ./

NAME	= gnl.a

CC		= gcc

AR		= ar rc

RM		= rm -f

LIB		= ranlib

FLAGS	= -Wall -Wextra -Werror

all:	${NAME}

.c.o:
		${CC} ${FLAGS} -c -I ${HEADERS} -o $@ $<

${NAME}: ${OBJS}
		${AR} $@ $^

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
