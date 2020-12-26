
SRCS		= megaphone.cpp

OBJS		= ${SRCS:.cpp=.o}

CPP			= clang++
CFLAGS		= -Wall -Wextra -Werror

NAME		= megaphone


.c.o:		${SRCS}
			${CPP} ${CFLAGS} -c $^ -o ${<:.cpp=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CPP} ${CFLAGS} -o ${NAME} ${OBJS}

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re :		fclean all
