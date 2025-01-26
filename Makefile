SRCS = mandatory/push_swap.c mandatory/split_string.c mandatory/converter.c mandatory/helpers.c mandatory/moves_swap.c mandatory/error_free.c \
       mandatory/moves_rrotate.c mandatory/moves_rotate.c mandatory/moves_push.c mandatory/small_algorithm.c mandatory/large_algorithm.c

BONUS_SRCS = bonus/checker_bonus.c bonus/converter_bonus.c bonus/error_free_bonus.c \
             bonus/isdigit_strncmp_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c \
             bonus/helpers_bonus.c bonus/moves_push_bonus.c bonus/moves_rotate_bonus.c \
             bonus/moves_rrotate_bonus.c bonus/moves_swap_bonus.c bonus/split_string_bonus.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJS = ${SRCS:.c=.o}
NAME = push_swap
HEADER = mandatory/push_swap.h
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
BONUS_NAME = checker
BONUS_HEADER = bonus/checker_bonus.h

all: ${NAME}

${NAME}: ${OBJS}
	@echo "Linking objects into ${NAME}"
	@${CC} ${OBJS} -o ${NAME}

bonus: ${BONUS_NAME}

${BONUS_NAME}: ${BONUS_OBJS}
	@echo "Linking objects into ${BONUS_NAME}"
	@${CC} ${BONUS_OBJS} -o ${BONUS_NAME}

mandatory/%.o: mandatory/%.c ${HEADER}
	@echo "Compiling source: $<"
	@${CC} ${CFLAGS} -c $< -o $@

bonus/%.o: bonus/%.c ${BONUS_HEADER}
	@echo "Compiling source: $<"
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "Removing all object file"
	@${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	@echo "Removing ${NAME} & ${BONUS_NAME}"
	@${RM} ${NAME} ${BONUS_NAME}

re: fclean all