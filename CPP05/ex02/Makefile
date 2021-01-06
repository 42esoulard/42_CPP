
SRCS		= main.cpp customException.cpp Bureaucrat.cpp Form.cpp \
				ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp

OBJS		= ${SRCS:.cpp=.o}

INC_DIR		= .
INCLUDES	= customException.hpp Bureaucrat.hpp Form.hpp \
				ShrubberyCreationForm.hpp RobotomyRequestForm.hpp \
				PresidentialPardonForm.hpp

CPP			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME		= Bureaucrat


.c.o:		${SRCS} ${INCLUDES}
			${CPP} ${CFLAGS} -I ${INC_DIR} -c $^ -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} ${INCLUDES}
			${CPP} ${CFLAGS} -o ${NAME} ${OBJS}

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME} MyLoveForBobRoss_shrubbery

re :		fclean all
