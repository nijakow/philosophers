/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_reap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:33:42 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/08 17:04:26 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	did_someone_die(struct s_philos *philos)
{
	bool	value;

	pthread_mutex_lock(&philos->mutex);
	value = philos->has_someone_died;
	pthread_mutex_unlock(&philos->mutex);
	return (value);
}
/*
static void	make_someone_die(struct s_philos *philos)
{
	pthread_mutex_lock(&philos->mutex);
	philos->has_someone_died = true;
	pthread_mutex_unlock(&philos->mutex);
}
*/

void	philos_reap(struct s_philos *philos)
{
	unsigned int	x;
	struct s_philo	*philo;

	while (!did_someone_die(philos))
	{
		x = 0;
		while (x < philos->table_size)
		{
			philo = &philos->entries[x].philo;
			philo_maybe_die(philo, clock_now(&philo->clock));
			x = x + 1;
		}
	}
}
