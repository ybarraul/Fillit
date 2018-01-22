# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: asiaux <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/22 16:54:19 by asiaux       #+#   ##    ##    #+#        #
#    Updated: 2018/01/17 15:15:22 by ybarraul    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit
FLAG = -Werror -Wall -Wextra
SRC_PATH = srcs
HEADER_PATH = includes
SRC = srcs/c0_init__exit_close.c srcs/c1_verif_tet.c srcs/c2_move_tet.c \
		srcs/c3_size_tet.c 	srcs/c4_der_tet.c srcs/check_all.c srcs/main.c \
		srcs/print_tet.c srcs/solve.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
		@gcc $(FLAG) -c $^ -o $@ -I $(HEADER_PATH)
		@echo "Creation de $@"

$(NAME): $(OBJ)
		@gcc $(FLAG) -o $(NAME) $(OBJ)
		@echo "Compilation de Fillit"

clean:
		@rm -f $(OBJ)
		@echo "Nettoyage des .o"

fclean: clean
		@rm -f $(NAME)
		@echo "Suppression de fillit"

re: fclean all
