
SRCS		= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJS		= ${SRCS:.cpp=.o}

INC_DIR		= .
INCLUDES	= Weapon.hpp HumanA.hpp HumanB.hpp

CPP			= clang++
CFLAGS		= -Wall -Wextra -Werror

NAME		= Violence


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
