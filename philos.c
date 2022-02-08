/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:47:25 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/08 19:10:49 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos_create(struct s_philos *philos)
{
	unsigned int	x;

	pthread_mutex_init(&philos->mutex, NULL);
	clock_create(&philos->clock);
	philos->start_time = 0;
	philos->matrix_start = false;
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

	x = 0;
	while (x < philos->table_size)
	{
		philo_start(&philos->entries[x].philo);
		x = x + 1;
	}
	philos->start_time = clock_now(&philos->clock);
	philos->matrix_start = true;
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
