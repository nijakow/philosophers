/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:08:34 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/08 16:39:58 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_start_eating(struct s_philo *philo, unsigned long time)
{
	philo_take_forks(philo);
	time = clock_now(&philo->clock);
	philo->state = STATE_EATING;
	philo->last_event = time;
	philo->next_event += philo->philos->stats.time_to_eat;
	pthread_mutex_lock(&philo->philos->mutex);
	if (!philo->philos->has_someone_died)
		printf("%lu %d is eating\n", time, philo->num);
	pthread_mutex_unlock(&philo->philos->mutex);
	philo->rounds++;
}
