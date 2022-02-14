/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thinking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:09:33 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/14 14:04:31 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_start_thinking(struct s_philo *philo, unsigned long time)
{
	pthread_mutex_lock(&philo->philos->mutex);
	if (!philo->philos->has_someone_died)
		printf("%lu %u is thinking\n", time, philo->num + 1);
	pthread_mutex_unlock(&philo->philos->mutex);
	philo->state = STATE_THINKING;
	philo->next_event = philo_next_eat(philo);
}
