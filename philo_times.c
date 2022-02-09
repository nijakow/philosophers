/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_times.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:10:37 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/09 13:18:34 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static unsigned long	philo_next_base(struct s_philo *philo)
{
	return ((philo->rounds * philo->philos->stats.round_time)
				+ (philo->flank * philo->philos->stats.time_to_eat));
}

unsigned long	philo_next_eat(struct s_philo *philo)
{
	return (philo_next_base(philo));
}

unsigned long	philo_next_sleep(struct s_philo *philo)
{
	return (philo_next_base(philo) + philo->philos->stats.time_to_eat);
}

unsigned long	philo_next_think(struct s_philo *philo)
{
	return (philo_next_base(philo)
			+ philo->philos->stats.time_to_eat
			+ philo->philos->stats.time_to_sleep);
}
