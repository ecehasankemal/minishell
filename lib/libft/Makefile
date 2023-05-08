NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = $(shell find . ! -name "ft_lst*.c" -name "ft_*.c")
BONUS = $(shell find . -name "ft_lst*.c")
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)


all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) *.o
	@echo "\n$(shell tput setaf 10) $@ built ✅ $(shell tput sgr0)\n"
bonus: $(OBJ) $(BONUS_OBJ)
	@ar rc $(NAME) *.o
	@echo "\n$(shell tput setaf 10) $@ built ✅$(shell tput sgr0)\n"
clean:
	@/bin/rm -f  *.o
	@echo "\n$(shell tput setaf 11) object files removed 👋$(shell tput sgr0)\n"
fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\n$(shell tput setaf 11) executables removed 👋$(shell tput sgr0)\n"

re: fclean all

.PHONY: all bonus clean fclean re
