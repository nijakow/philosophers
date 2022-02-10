/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:27:39 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/10 17:38:38 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_main_decision(struct s_philo *philo, unsigned long time)
{
	if ((philo->times_eaten >= philo->philos->stats.steps)
		&& philo->philos->stats.steps >= 0)
	{
		philo->state = STATE_FINISHED;
	}
	else if (philo->state == STATE_SLEEPING)
	{
		philo->rounds++;
		philo_start_thinking(philo, time);
	}
	else if (philo->state == STATE_THINKING)
	{
		philo_start_eating(philo, time);
	}
	else if (philo->state == STATE_EATING)
	{
		philo_start_sleeping(philo);
	}
}

static bool	did_someone_die(struct s_philos *philos)
{
	bool	value;

	pthread_mutex_lock(&philos->mutex);
	value = philos->has_someone_died;
	pthread_mutex_unlock(&philos->mutex);
	return (value);
}

static void	philo_main(struct s_philo *philo, unsigned long time)
{	
	while (!did_someone_die(philo->philos)
		&& philo->state != STATE_FINISHED)
	{
		if (time >= philo->next_event)
		{
			philo_main_decision(philo, time);
		}
		usleep(50);
		time = clock_now(&philo->philos->clock);
		philo_maybe_die(philo, time);
	}
}

void	*philo_launch(void *void_philo)
{
	unsigned long	time;
	struct s_philo	*philo;

	philo = void_philo;
	pthread_mutex_lock(&philo->philos->start_mutex);
	pthread_mutex_unlock(&philo->philos->start_mutex);
	time = philo->philos->start_time;
	philo->last_eat = time;
	philo->last_event = time;
	philo->next_event = philo_next_eat(philo);
	philo_main(philo, time);
	if (philo->has_left_fork || philo->has_right_fork)
		philo_drop_forks(philo);
	return (NULL);
}
