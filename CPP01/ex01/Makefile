
SRCS		= ex01.cpp

OBJS		= ${SRCS:.cpp=.o}

CPP			= clang++
CFLAGS		= -Wall -Wextra -Werror

NAME		= memLeak


.c.o:		${SRCS}
			${CPP} ${CFLAGS} -c $^ -o ${<:.c=.o}

all:		${NAME}

leaks: 		${NAME}
			valgrind ./memLeak

${NAME}:	${OBJS}
			${CPP} ${CFLAGS} -o ${NAME} ${OBJS}

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re :		fclean all
