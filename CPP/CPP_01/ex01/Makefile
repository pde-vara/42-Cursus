
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp Zombie.cpp zombieHorde.cpp
TARGET := zombieHorde

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

fclean: clean
	@echo "=fclean"

re: fclean all
