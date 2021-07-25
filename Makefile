TARGET = philo
CFLAGS = -o2 -g3 -Wall -Werror -Wextra
#LFLAGS = -L
LIBS = -lpthread
CC = gcc
RM = rm -f

SRCS = g_test.c    check_arguments.c get_arguments.c utils.c \
       free_mem.c  pthread_utils.c   philo_start.c

OBJS = $(SRCS:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(LIBS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean :
	$(RM) $(OBJS) 

fclean : clean
	$(RM) $(TARGET)

re : fclean all
