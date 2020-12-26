
SRCS		= main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp NinjaTrap.cpp

OBJS		= ${SRCS:.cpp=.o}

INC_DIR		= .
INCLUDES	= ClapTrap.hpp FragTrap.hpp ScavTrap.hpp NinjaTrap.hpp

CPP			= clang++
CFLAGS		= -Wall -Wextra -Werror

NAME		= NinjaTrap


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
