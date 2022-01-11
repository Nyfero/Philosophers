# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 14:07:19 by gsap              #+#    #+#              #
#    Updated: 2022/01/11 14:05:24 by gsap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# valgrind --tool=helgrind

# Colors
GREY = \e[90m
RED = \e[91m
GREEN = \e[92m
YELLOW = \e[93m
BLUE = \e[34m
PURPLE = \e[95m
CYAN = \e[96m
END = \e[39m

NAME = philo

CC = clang

CFLAGS = -g -Wall -Wextra -Werror -pthread

RM = rm -rf

SRCS_PATH = srcs

#ft_eat.c ft_sleep.c

SRCS = $(addprefix $(SRCS_PATH)/,main.c ft_error.c ft_init.c ft_utils.c \
ft_create_threads.c ft_display.c)

OBJS_PATH = objs/

OBJS = $(patsubst $(SRCS_PATH)%.c,	$(OBJS_PATH)%.o, $(SRCS))

INC = inc/

# rules
all: $(NAME)

exec: all
	@valgrind --tool=helgrind ./$(NAME) 15 100 100 100 100 ; true

$(NAME): $(OBJS_PATH) $(OBJS)
	@ echo "$(BLUE)\n		*** Make $(NAME) ***\n$(END)"
	@ $(CC) $(CFLAGS) $(OBJS_PATH)/*.o -o $(NAME)
	@ echo "$(GREEN)\n		---$(NAME) created ---\n$(END)"

$(OBJS_PATH):
	@ mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC)/$(NAME).h
	@ $(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	@ $(RM) $(OBJS_PATH)
	@ echo "$(PURPLE)\n		*** Clean objects ***\n$(END)"

fclean: clean
	@ $(RM) $(NAME)
	@ echo "$(RED)\n		*** Remove $(NAME) ***\n$(END)"

re: fclean all

.PHONY: all clean fclean re exec
