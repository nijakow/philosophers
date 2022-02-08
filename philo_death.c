/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:55:15 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/08 18:17:29 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_die(struct s_philo *philo)
{
	pthread_mutex_lock(&philo->philos->mutex);
	if (!philo->philos->has_someone_died)
	{
		if (!philo->philos->has_someone_died)
			printf("%lu %u died\n", clock_now(&philo->clock), philo->num);
		philo->philos->has_someone_died = true;
	}
	pthread_mutex_unlock(&philo->philos->mutex);
}

bool	philo_maybe_die(struct s_philo *philo, unsigned long time)
{
	if (time > philo->last_eat + philo->philos->stats.time_to_die)
	{
		philo_die(philo);
		return (true);
	}
	return (false);
}
