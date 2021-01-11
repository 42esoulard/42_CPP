
SRCS		= main.cpp 

OBJS		= ${SRCS:.cpp=.o}

INC_DIR		= .
INCLUDES	= identify.h Base.hpp ClassA.hpp ClassB.hpp ClassC.hpp

CPP			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME		= Identify


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
