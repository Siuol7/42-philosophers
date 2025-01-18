NAME			:= philo
CC				:= cc
RM				:= rm -rf
CFLAGS			:= -Wall -Wextra -Werror

#INCLUDE
INCLUDE				:=  -I ./includes
MAIN				:= ./main
MANDATORY			:= ./srcs/mandatory
BONUS				:= ./srcs/bonus


PARSING				:= parsing
#EXECUTION			:= execution
ERROR				:= error

MAIN_C				:=	main.c				\
						utilities.c

PARSING_C			:=	av_management.c		\

EXECUTION_C			:=	game_operation.c	\
						graphic.c			\
						display_image.c		\
						game_control.c		\
						game_end.c

ERROR_C				:= error_handling.c

SRCS				:= 	$(addprefix $(MAIN)/,					$(MAIN_C))			\
						$(addprefix	$(MANDATORY)/$(PARSING)/,	$(PARSING_C))		\
						#$(addprefix $(MANDATORY)/$(EXECUTION)/,	$(EXECUTION_C))		\
						#$(addprefix $(MANDATORY)/$(ERROR)/,		$(ERROR_C))

#BONUS				:=

OBJS				:= $(SRCS:.c=.o)

#OBJS_BN			:= $(BONUS:.c=.o)

#Default Target
all:	mandatory

#Compiling Rule
%.o:	%.c
	@echo "Compiling..."
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

#Create source library
mandatory : .mandatory
.mandatory: $(OBJS)
		@cc $(OBJS) -o $(NAME)
		@touch .mandatory

# Create bonus lib
bonus : .bonus
.bonus : $(OBJS_BN)
		@cc $(OBJS_BN) -o $(NAME)
		@touch .bonus

# Clean target
clean:
	@$(RM) $(OBJS) $(OBJS_BN) .mandatory .bonus

# Fclean target
fclean:
		@echo "----------------------------Cleaning----------------------------"
		@$(RM) $(OBJS) $(OBJS_BN) .bonus .mandatory $(NAME)
		@echo "----------------------------Finished----------------------------"

# Rebuild target
re: fclean all


.PHONY: all clean fclean re