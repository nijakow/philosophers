/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:27:39 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/08 17:49:35 by enijakow         ###   ########.fr       */
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

static void	philo_main(struct s_philo *philo, unsigned long time)
{	
	while ((!philo->philos->has_someone_died)
		&& philo->state != STATE_FINISHED)
	{
		if (time >= philo->next_event)
		{
			philo_main_decision(philo, time);
		}
		usleep(50);
		time = clock_now(&philo->clock);
	}
}

void	*philo_launch(void *void_philo)
{
	unsigned long	time;
	struct s_philo	*philo;
	unsigned int	wait_mul;

	philo = void_philo;
	wait_mul = philo->num % 2;
	if (philo->num == 0 && philo->philos->table_size % 2)
		wait_mul = 2;
	time = clock_now(&philo->clock);
	philo->last_event = time;
	philo->next_event = time + wait_mul * philo->philos->stats.time_to_eat / 2;
	usleep(wait_mul * philo->philos->stats.time_to_eat * 500);
	philo_main(philo, time);
	if (philo->has_forks)
		philo_drop_forks(philo);
	return (NULL);
}
