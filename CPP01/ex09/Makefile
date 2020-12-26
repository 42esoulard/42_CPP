
SRCS		= main.cpp Logger.cpp

OBJS		= ${SRCS:.cpp=.o}

INC_DIR		= .
INCLUDES	= Logger.hpp

CPP			= clang++
CFLAGS		= -Wall -Wextra -Werror

NAME		= DearDiary


.c.o:		${SRCS} ${INCLUDES}
			${CPP} ${CFLAGS} -I ${INC_DIR} -c $^ -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} ${INCLUDES}
			${CPP} ${CFLAGS} -o ${NAME} ${OBJS}

clean :
			rm -f ${OBJS} *.log

fclean :	clean
			rm -f ${NAME}

re :		fclean all
