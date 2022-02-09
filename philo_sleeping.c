/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:09:04 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/09 14:00:14 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_start_sleeping(struct s_philo *philo)
{
	pthread_mutex_lock(&philo->philos->mutex);
	if (!philo->philos->has_someone_died)
		printf("%lu %u is sleeping\n",
			clock_now(&philo->philos->clock), philo->num);
	pthread_mutex_unlock(&philo->philos->mutex);
	philo->next_event = philo_next_think(philo);
	philo_drop_forks(philo);
	philo->state = STATE_SLEEPING;
}
