/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:38:18 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/09 13:40:42 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_create(struct s_philo *philo,
			struct s_philos *philos,
			unsigned int num)
{
	philo->philos = philos;
	philo->num = num;
	philo->state = STATE_THINKING;
	philo->rounds = 0;
	philo->times_eaten = 0;
	philo->has_forks = false;
	if (philo->philos->stats.flanks == 3 && philo->num == (philo->philos->table_size - 1))
		philo->flank = 2;
	else
		philo->flank = philo->num % 2;
}
