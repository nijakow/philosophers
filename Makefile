# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 10:08:48 by enijakow          #+#    #+#              #
#    Updated: 2022/02/07 17:54:55 by enijakow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./philo

HEADERS = \
philo.h

SOURCES = \
clock_create.c \
clock_destroy.c \
clock_now.c \
fork_create.c \
fork_destroy.c \
fork_drop.c \
fork_take.c \
ft_atoi.c \
main.c \
philo_create.c \
philo_death.c \
philo_destroy.c \
philo_eating.c \
philo_forks.c \
philo_main.c \
philo_sleeping.c \
philo_startstop.c \
philo_thinking.c \
philos_get_fork.c \
philos.c

BONUS_SOURCES = \


CFLAGS = -Wall -Wextra -Werror
LDFLAGS = 


OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
BONUS_OBJECTS = $(patsubst %.c, %.o, $(BONUS_SOURCES))


%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<


$(NAME): $(OBJECTS) $(HEADERS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(NAME)

bonus: $(OBJECTS) $(BONUS_OBJECTS) $(HEADERS)
	$(CC) $(BONUS_OBJECTS) -o $(NAME)

all: $(NAME)

clean:
	- $(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	- $(RM) $(NAME)

re: fclean all

norm:
	norminette $(SOURCES) $(BONUS_SOURCES) $(HEADERS)
