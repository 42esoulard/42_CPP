
SRCS		= main.cpp AWeapon.cpp PlasmaRifle.cpp PowerFist.cpp \
				Character.cpp Enemy.cpp RadScorpion.cpp SuperMutant.cpp

OBJS		= ${SRCS:.cpp=.o}

INC_DIR		= .
INCLUDES	= wasteland.h AWeapon.hpp PlasmaRifle.hpp PowerFist.hpp \
				Character.hpp Enemy.hpp RadScorpion.hpp SuperMutant.hpp

CPP			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME		= Wasteland


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
