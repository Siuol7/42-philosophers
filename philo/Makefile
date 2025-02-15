NAME			:= philo
CC				:= cc
RM				:= rm -rf
CFLAGS			:= -Wall -Wextra -Werror

#INCLUDE
INCLUDE			:=  -I ./include
MAIN			:= ./main
SRCS			:= ./srcs


PARSING			:=	parsing
EXECUTION		:=	execution
MINILIB			:=  minilibrary
MONITOR			:=	monitor
ROUTINE			:=	routine

MAIN_C			:=	main.c				\
					utilities.c			\

PARSING_C		:=	av_management.c		\

EXECUTION_C		:=	run.c				\
					set_up.c			\

MINILIB_C		:=	minilibft.c			\
					minilibft2.c		\
					minimutex.c			\
					miniutils.c			\

MONITOR_C		:=	monitor.c			\

ROUTINE_C		:=	eats.c				\
					routine.c			\
					routine_control.c	\

SRCS			:= 	$(addprefix $(MAIN)/,				$(MAIN_C))		\
					$(addprefix	$(SRCS)/$(PARSING)/,	$(PARSING_C))	\
					$(addprefix $(SRCS)/$(MINILIB)/,	$(MINILIB_C))	\
					$(addprefix $(SRCS)/$(EXECUTION)/,	$(EXECUTION_C))	\
					$(addprefix $(SRCS)/$(MONITOR)/,	$(MONITOR_C))	\
					$(addprefix $(SRCS)/$(ROUTINE)/,	$(ROUTINE_C))	\

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
		@cc $(CFLAGS) $(OBJS) -o $(NAME)
		@touch .philo

# Clean target
clean:
	@$(RM) $(OBJS) $(OBJS_BN) .philo

# Fclean target
fclean:
		@$(RM) $(OBJS) $(OBJS_BN) .philo $(NAME)
		@echo "____________________________Finished____________________________"

# Rebuild target
re: fclean all


.PHONY: all clean fclean re