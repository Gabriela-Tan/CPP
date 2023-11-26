NAME =		Violence
CC =		c++
CFLAGS = 	-Wall -Wextra -Werror -std=c++98

SRC = 		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp \
		main.cpp

all: $(NAME)

$(NAME): 
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "run ./Violence"

clean:
	@rm -f $(NAME)
	@echo "Cleaning successful"

fclean:
	@rm -f $(NAME)
	@echo "All generated files are deleted"


re: fclean all
	@echo "Remake completed"

.PHONY: all clean fclean re