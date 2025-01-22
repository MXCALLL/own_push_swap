SRCS = mandatory/push_swap.c mandatory/split_string.c mandatory/converter.c mandatory/helpers.c \
       mandatory/moves_swap.c mandatory/error_free.c mandatory/small_algorithm.c mandatory/large_algorithm.c \
	   mandatory/moves_rrotate.c mandatory/moves_rotate.c mandatory/moves_push.c

BONUS_SRCS = bonus/checker_bonus.c bonus/converter_bonus.c bonus/error_free_bonus.c \
             bonus/ft_strncmp_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c \
             bonus/helpers_bonus.c bonus/moves_push_bonus.c bonus/moves_rotate_bonus.c \
             bonus/moves_rrotate_bonus.c bonus/moves_swap_bonus.c bonus/split_string_bonus.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJS = ${SRCS:.c=.o}
NAME = push_swap
HEADER = push_swap.h
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
BONUS_NAME = checker
BONUS_HEADER = bonus/checker_bonus.h

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

bonus: ${BONUS_NAME}

${BONUS_NAME}: ${BONUS_OBJS}
	${CC} ${BONUS_OBJS} -o ${BONUS_NAME}

%.o: %.c ${HEADER} ${BONUS_HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME} ${BONUS_NAME}

re: fclean all