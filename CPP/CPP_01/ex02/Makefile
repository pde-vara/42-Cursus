

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp
TARGET := brain

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

fclean: clean
	@echo "=clean"

re: fclean all




