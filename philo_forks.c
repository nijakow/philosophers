/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:51:32 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/08 18:40:43 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_take_fork(struct s_philo *philo, unsigned int fork)
{
	fork_take(philos_get_fork(philo->philos, fork));
	pthread_mutex_lock(&philo->philos->mutex);
	if (!philo->philos->has_someone_died)
		printf("%lu %u has taken a fork\n",
			clock_now(&philo->philos->clock),
			philo->num);
	pthread_mutex_unlock(&philo->philos->mutex);
}

static void	philo_drop_fork(struct s_philo *philo, unsigned int fork)
{
	fork_drop(philos_get_fork(philo->philos, fork));
}

bool	philo_take_forks(struct s_philo *philo)
{
	if (philo->philos->table_size <= 1)
		return (false);
	philo_take_fork(philo, philo->num + (philo->num % 2));
	philo_take_fork(philo, philo->num + !(philo->num % 2));
	philo->has_forks = true;
	return (true);
}

void	philo_drop_forks(struct s_philo *philo)
{
	philo_drop_fork(philo, philo->num + ((philo->num % 2) == 0));
	philo_drop_fork(philo, philo->num + ((philo->num % 2) != 0));
	philo->has_forks = false;
}
