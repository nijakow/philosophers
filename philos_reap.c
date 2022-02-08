/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_reap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:33:42 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/08 18:41:29 by enijakow         ###   ########.fr       */
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
	bool			running;
	unsigned int	x;
	struct s_philo	*philo;

	usleep((philos->stats.time_to_die / 2) * 1000);
	running = true;
	while (!did_someone_die(philos) && running)
	{
		running = false;
		x = 0;
		while (x < philos->table_size)
		{
			philo = &philos->entries[x].philo;
			if (philo->state != STATE_FINISHED)
			{
				running = true;
				philo_maybe_die(philo, clock_now(&philo->philos->clock));
			}
			x = x + 1;
		}
		usleep(50);
	}
}
