/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:13:50 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/08 16:35:47 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	setup_stats(struct s_stats *stats, int argc, char **argv)
{
	bool	result;

	if (argc < 5 || argc > 6)
		return (false);
	result = ft_atoi(argv[1], &stats->philo_count)
		&& ft_atoi(argv[2], &stats->time_to_die)
		&& ft_atoi(argv[3], &stats->time_to_eat)
		&& ft_atoi(argv[4], &stats->time_to_sleep);
	if (argc == 6)
		result = result && ft_atoi(argv[5], &stats->steps);
	else
		stats->steps = -1;
	return (result);
}

int	main(int argc, char *argv[])
{
	struct s_philos	philos;

	if (setup_stats(&philos.stats, argc, argv))
	{
		philos_create(&philos);
		philos_start(&philos);
		philos_reap(&philos);
		philos_join(&philos);
		philos_destroy(&philos);
	}
	else
	{
		write(2, "Error!\n", 7);
	}
	return (0);
}
