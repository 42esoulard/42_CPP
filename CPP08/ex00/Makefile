
SRCS		= main.cpp customException.cpp

OBJS		= ${SRCS:.cpp=.o}

INC_DIR		= .
INCLUDES	= easyfind.hpp customException.hpp

CPP			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME		= easyFind


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
