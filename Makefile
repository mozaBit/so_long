S = src
B = bonus
I = inc
O = obj

SRC = $(wildcard $(S)/*.c)
SRC_BONUS = $(wildcard $(B)/*.c)
OBJ = $(patsubst $(S)/*.c,$(O)/%.o,$(SRC))

CC  = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -I $(I)
RM = rm -f
RMDIR = rm -rf
NAME = so_long
NAME_B = so_long_bonus
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
GNL = get_next_line/gnl.a

all : $(NAME)

bonus : $(NAME_B)

$(O):
		@mkdir -p $@

$(OBJ): | $(O)

$(O)/%.o : $(S)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(O)/%.o : $(B)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(GNL) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $@

$(NAME_B): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(GNL) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $@

cleanobj:
		$(RM) $(wildcard $(O)/*.o)

cleanobjdir: cleanobj
		$(RMDIR) $(O)

clean: cleanobjdir

fclean: clean
		$(RM) $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re
