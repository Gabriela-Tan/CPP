NAME =		Polymorphism
CC =		c++
CFLAGS = 	-Wall -Wextra -Werror -std=c++98

SRC = 		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		main.cpp

all: $(NAME)

$(NAME): 
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "run ./Polymorphism"

clean:
	@rm -f $(NAME)
	@echo "Cleaning successful"

fclean:
	@rm -f $(NAME)
	@echo "All generated files are deleted"


re: fclean all
	@echo "Remake completed"

.PHONY: all clean fclean re