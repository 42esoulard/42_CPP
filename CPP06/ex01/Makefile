
SRCS		= main.cpp 

OBJS		= ${SRCS:.cpp=.o}

INC_DIR		= .
INCLUDES	=

CPP			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME		= Serialize


.c.o:		${SRCS} ${INCLUDES}
			${CPP} ${CFLAGS} -I ${INC_DIR} -c $^ -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} ${INCLUDES}
			${CPP} ${CFLAGS} -o ${NAME} ${OBJS}

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME} 

re :		fclean all
