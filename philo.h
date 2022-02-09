/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:14:00 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/09 13:09:48 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>
# include <pthread.h>

int				ft_atoi(char *str, int *v);

struct			s_philos;

struct s_stats
{
	int	philo_count;
	int	time_to_sleep;
	int	time_to_eat;
	int	time_to_die;
	int	steps;
	int flanks;
	int round_time;
};

struct s_clock
{
	unsigned long	timestamp_created;
};

void			clock_create(struct s_clock *clock);
void			clock_destroy(struct s_clock *clock);
unsigned long	clock_now(struct s_clock *clock);

struct s_fork
{
	pthread_mutex_t	mutex;
	bool			value;
	int				holder;
};

void			fork_create(struct s_fork *fork);
void			fork_destroy(struct s_fork *fork);
void			fork_take(struct s_fork *fork);
void			fork_drop(struct s_fork *fork);

enum e_philo_state
{
	STATE_SLEEPING,
	STATE_EATING,
	STATE_THINKING,
	STATE_DEAD,
	STATE_FINISHED
};

struct s_philo
{
	pthread_t			thread;
	struct s_philos		*philos;
	unsigned int		num;
	unsigned int		flank;
	enum e_philo_state	state;
	unsigned long		last_eat;
	unsigned long		last_event;
	unsigned long		next_event;
	int					rounds;
	bool				has_forks;
};

void			philo_create(struct s_philo *philo,
					struct s_philos *philos,
					unsigned int num);
void			philo_destroy(struct s_philo *philo);
void			philo_destroy(struct s_philo *philo);
void			philo_change_state(struct s_philo *philo,
					enum e_philo_state state);
void			philo_start_eating(struct s_philo *philo,
					unsigned long time);
void			philo_stop_eating(struct s_philo *philo);
void			philo_start_thinking(struct s_philo *philo,
					unsigned long time);
void			philo_stop_thinking(struct s_philo *philo);
void			philo_start_sleeping(struct s_philo *philo);
void			philo_stop_sleeping(struct s_philo *philo);
bool			philo_take_forks(struct s_philo *philo);
void			philo_drop_forks(struct s_philo *philo);
bool			philo_maybe_die(struct s_philo *philo, unsigned long time);
void			*philo_launch(void *philo);
void			philo_start(struct s_philo *philo);
void			philo_join(struct s_philo *philo);

struct s_philos_entry
{
	struct s_fork	fork;
	struct s_philo	philo;
};

struct s_philos
{
	struct s_clock			clock;
	unsigned long			start_time;
	pthread_mutex_t			mutex;
	bool					matrix_start;
	bool					has_someone_died;
	struct s_stats			stats;
	struct s_philos_entry	*entries;
	unsigned int			table_size;
};

void			philos_create(struct s_philos *philos);
void			philos_destroy(struct s_philos *philos);
void			philos_start(struct s_philos *philos);
void			philos_join(struct s_philos *philos);
struct s_fork	*philos_get_fork(struct s_philos *philos,
					unsigned int fork);
void			philos_reap(struct s_philos *philos);

#endif
