SRCS = push_swap.c ft_split.c ft_atoi.c helpers.c moves_swap.c moves_rrotate.c moves_rotate.c moves_push.c sorting_algorithm.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = ${SRCS:.c=.o}
NAME = libswap.a
HEADER = push_swap.h
ARCHIVE = ar rcs
RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${ARCHIVE} ${NAME} ${OBJS}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all