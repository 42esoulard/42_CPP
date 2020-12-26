
SRCS		= main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp

OBJS		= ${SRCS:.cpp=.o}

INC_DIR		= .
INCLUDES	= ClapTrap.hpp FragTrap.hpp ScavTrap.hpp

CPP			= clang++
CFLAGS		= -Wall -Wextra -Werror

NAME		= ClapTrap


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
