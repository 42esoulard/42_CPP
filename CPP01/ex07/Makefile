
SRCS		= main.cpp

OBJS		= ${SRCS:.cpp=.o}

CPP			= clang++
CFLAGS		= -Wall -Wextra -Werror

NAME		= replace


.c.o :		${SRCS}
			${CPP} ${CFLAGS} -c $^ -o ${<:.c=.o}

all :		${NAME}

${NAME} :	${OBJS}
			${CPP} ${CFLAGS} -o ${NAME} ${OBJS}

test :		all
			./replace main.cpp std "RICK ASTLEY"

clean :
			rm -f ${OBJS} *.replace

fclean :	clean
			rm -f ${NAME}

re :		fclean all
