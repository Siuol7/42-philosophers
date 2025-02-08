NAME			:= philo
CC				:= cc
RM				:= rm -rf
CFLAGS			:= -Wall -Wextra -Werror

#INCLUDE
INCLUDE			:=  -I ./include
MAIN			:= ./main
SRCS			:= ./srcs


PARSING			:= parsing
#EXECUTION		:= execution
MINILIB			:=  minilibrary
ERROR			:= error

MAIN_C			:=	main.c				\
						utilities.c

PARSING_C		:=	av_management.c		\

EXECUTION_C		:=

ERROR_C			:=

MINILIB_C		:=	minilibft.c

SRCS			:= 	$(addprefix $(MAIN)/,				$(MAIN_C))		\
						$(addprefix	$(SRCS)/$(PARSING)/,	$(PARSING_C))	\
						$(addprefix $(SRCS)/$(MINILIB)/,	$(MINILIB_C))	\
						#$(addprefix $(SRCS)/$(EXECUTION)/,	$(EXECUTION_C))		\
						#$(addprefix $(SRCS)/$(ERROR)/,		$(ERROR_C))

OBJS			:= $(SRCS:.c=.o)

#Default Target
all:	philo

#Compiling Rule
%.o:	%.c
	@echo "Compiling..."
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

#Create source library
philo : .philo
.philo: $(OBJS)
		@cc $(OBJS) -o $(NAME)
		@touch .philo

# Clean target
clean:
	@$(RM) $(OBJS) $(OBJS_BN) .philo

# Fclean target
fclean:
		@echo "----------------------------Cleaning----------------------------"
		@$(RM) $(OBJS) $(OBJS_BN) .philo $(NAME)
		@echo "----------------------------Finished----------------------------"

# Rebuild target
re: fclean all


.PHONY: all clean fclean re