
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

TARGET := zombie

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

re: clean all
