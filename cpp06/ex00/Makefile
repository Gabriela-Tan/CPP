NAME =		convert
CC =		c++
CFLAGS = 	-Wall -Wextra -Werror -std=c++98

SRC = 		ScalarConverter.cpp \
		main.cpp

all: $(NAME)

$(NAME): 
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "run ./convert [value]"

clean:
	@rm -f $(NAME)
	@echo "Cleaning successful"

fclean:
	@rm -f $(NAME)
	@echo "All generated files are deleted"


re: fclean all
	@echo "Remake completed"

.PHONY: all clean fclean re