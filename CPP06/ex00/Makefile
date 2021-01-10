
SRCS		= main.cpp customException.cpp Convert.cpp

OBJS		= ${SRCS:.cpp=.o}

INC_DIR		= .
INCLUDES	= customException.hpp Convert.hpp

CPP			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME		= Convert


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
