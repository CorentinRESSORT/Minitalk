SERVER = server
CLIENT = client

SRCSS = server.c \
		source/ft_bzero.c \
		source/ft_itoa.c \
		source/ft_memset.c \
		source/ft_strlen.c

SRCSSO = server.o \
		source/ft_bzero.o \
		source/ft_itoa.o \
		source/ft_memset.o \
		source/ft_strlen.o

SRCC = client.c

SRCCO = client.o 

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./include

OBJSS = $(SRCSS:.c=.c)

OBJSC = $(SRCC:.c=.c)

all 	: $(SERVER) $(CLIENT)

server : $(OBJSS)
	$(CC) -o $(SERVER) $(INCLUDES) $(SRCSS)

client : $(OBJSC)
	$(CC) -o $(CLIENT) $(INCLUDES) $(SRCC)

clean	:
	rm -rf $(SRCSSO)
	rm -rf $(SRCCO)

fclean : clean
	rm -rf $(SERVER) $(CLIENT)

re	: fclean all