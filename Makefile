SRCS = push_swap.c split_string.c converter.c helpers.c moves_swap.c \
       moves_rrotate.c moves_rotate.c moves_push.c small_algorithm.c large_algorithm.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = ${SRCS:.c=.o}
NAME = push_swap
HEADER = push_swap.h
RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all