NAME		= bureaucrat

SRCS		= Bureaucrat.cpp \
			  Intern.cpp \
			  ShrubberyCreationForm.cpp \
			  RobotomyRequestForm.cpp \
			  PresidentialPardonForm.cpp \
			  Form.cpp \
			  main.cpp
OBJS		= $(SRCS:.cpp=.opp)

COMPILER	= c++
FLAGS		= -Wall -Werror -Wextra -std=c++98

%.opp:		%.cpp
			$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(COMPILER) $(OBJS) -o $(NAME)

all:		$(NAME)

re:			fclean all

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

.PHONY: all re clean fclean
