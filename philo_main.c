/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:27:39 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/08 16:49:15 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_main_decision(struct s_philo *philo, unsigned long time)
{
	if ((philo->rounds >= philo->philos->stats.steps)
		&& philo->philos->stats.steps >= 0)
	{
		philo->state = STATE_FINISHED;
	}
	else if (philo->state == STATE_SLEEPING)
	{
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

void	*philo_main(void *void_philo)
{
	struct s_philo	*philo;
	unsigned long	time;

	philo = void_philo;
	usleep(((philo->num) % 2) * philo->philos->stats.time_to_eat * 1000);
	time = clock_now(&philo->clock);
	philo->last_event = time;
	philo->next_event = time;
	while ((!philo->philos->has_someone_died)
		&& philo->state != STATE_FINISHED)
	{
		if (philo_maybe_die(philo, time))
			;
		else if (time >= philo->next_event)
		{
			philo_main_decision(philo, time);
		}
		usleep(50);
		time = clock_now(&philo->clock);
	}
	if (philo->has_forks)
		philo_drop_forks(philo);
	return (NULL);
}
