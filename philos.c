/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:47:25 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/09 16:50:04 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos_create(struct s_philos *philos)
{
	unsigned int	x;

	pthread_mutex_init(&philos->mutex, NULL);
	pthread_mutex_init(&philos->start_mutex, NULL);
	clock_create(&philos->clock);
	philos->start_time = 0;
	philos->has_someone_died = false;
	philos->table_size = philos->stats.philo_count;
	philos->entries = malloc(sizeof(struct s_philos_entry)
			* philos->table_size);
	if (philos->entries != NULL)
	{
		x = 0;
		while (x < philos->table_size)
		{
			philo_create(&philos->entries[x].philo, philos, x);
			fork_create(&philos->entries[x].fork);
			x = x + 1;
		}
	}
}

void	philos_destroy(struct s_philos *philos)
{
	unsigned int	x;

	pthread_mutex_destroy(&philos->mutex);
	pthread_mutex_destroy(&philos->start_mutex);
	clock_destroy(&philos->clock);
	if (philos->entries != NULL)
	{
		x = 0;
		while (x < philos->table_size)
		{
			philo_destroy(&philos->entries[x].philo);
			fork_destroy(&philos->entries[x].fork);
			x = x + 1;
		}
	}
}

void	philos_start(struct s_philos *philos)
{
	unsigned int	x;

	pthread_mutex_lock(&philos->start_mutex);
	x = 0;
	while (x < philos->table_size)
	{
		philo_start(&philos->entries[x].philo);
		x = x + 1;
	}
	philos->start_time = clock_now(&philos->clock);
	pthread_mutex_unlock(&philos->start_mutex);
}

void	philos_join(struct s_philos *philos)
{
	unsigned int	x;

	x = 0;
	while (x < philos->table_size)
	{
		philo_join(&philos->entries[x].philo);
		x = x + 1;
	}
}
