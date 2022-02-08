/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:51:32 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/07 18:28:34 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_take_fork(struct s_philo *philo, unsigned int fork, int hand)
{
	while (!fork_take(philos_get_fork(philo->philos, fork), philo->num, hand))
	{
		usleep(500);
		if (philo_maybe_die(philo, clock_now(&philo->clock)))
			return (false);
	}
	pthread_mutex_lock(&philo->philos->mutex);
	if (!philo->philos->has_someone_died)
		printf("%lu %u has taken a fork\n",
			clock_now(&philo->clock),
			philo->num);
	pthread_mutex_unlock(&philo->philos->mutex);
	return (true);
}

static void	philo_drop_fork(struct s_philo *philo, unsigned int fork)
{
	fork_drop(philos_get_fork(philo->philos, fork));
}

bool	philo_take_forks(struct s_philo *philo)
{
	philo->has_forks = philo_take_fork(philo,
			philo->num + ((philo->num % 2) == 0), 0)
		&& philo_take_fork(philo,
			philo->num + ((philo->num % 2) != 0), 1);
	return (philo->has_forks);
}

void	philo_drop_forks(struct s_philo *philo)
{
	philo_drop_fork(philo, philo->num + ((philo->num % 2) == 0));
	philo_drop_fork(philo, philo->num + ((philo->num % 2) != 0));
	philo->has_forks = false;
}
