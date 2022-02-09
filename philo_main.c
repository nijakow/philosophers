/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:27:39 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/09 13:36:02 by enijakow         ###   ########.fr       */
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
		time = clock_now(&philo->philos->clock);
	}
}

void	*philo_launch(void *void_philo)
{
	unsigned long	time;
	struct s_philo	*philo;
	unsigned int	wait_mul;

	philo = void_philo;
	while (!philo->philos->matrix_start)
		usleep(50);
	if (philo->num % 2 == 0)
		wait_mul = 0;
	else if (philo->num % 2 == 1)
		wait_mul = philo->philos->stats.time_to_eat / 2;
	wait_mul = philo->num % 2;
	time = philo->philos->start_time;
	philo->last_eat = time;
	philo->last_event = time;
	philo->next_event = philo_next_eat(philo);
	philo_main(philo, time);
	if (philo->has_forks)
		philo_drop_forks(philo);
	return (NULL);
}
