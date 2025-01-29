CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilib/libft -fsanitize=address -g
NAME = pipex

SRCS = srcs/main.c \
\
	srcs/exec/path.c \
	srcs/exec/exec.c \
\
	srcs/utils/tab.c \
\
	srcs/error/error.c \
\
	srcs/pipe/pipe.c \
	srcs/pipe/file.c \

OBJS = ${SRCS:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

lib/libft/libft.a:
	make -C lib/libft

${NAME}: lib/libft/libft.a ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME} -L./lib/libft -lft


fclean: clean
		rm -rf ${NAME}
		make fclean -C lib/libft

clean:
		rm -rf ${OBJS}
		make clean -C lib/libft

re:	fclean all

.PHONY: all clean fclean re