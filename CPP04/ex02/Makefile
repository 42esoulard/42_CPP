
SRCS		= main.cpp AssaultTerminator.cpp TacticalMarine.cpp Squad.cpp

OBJS		= ${SRCS:.cpp=.o}

INC_DIR		= .
INCLUDES	= ISpaceMarine.hpp ISquad.hpp AssaultTerminator.hpp TacticalMarine.hpp Squad.hpp

CPP			= clang++
CFLAGS		= -Wall -Wextra -Werror

NAME		= Squad


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
