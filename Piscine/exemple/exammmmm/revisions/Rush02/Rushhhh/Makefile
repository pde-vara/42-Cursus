CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = rush-02
MAIN = truc.c
SOURCE = *.c
OBJECTS = $(SOURCE:.c=.o)
RM = rm -f 

.c.o: 
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $< $(MAIN) -o $(NAME) 

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)
	

