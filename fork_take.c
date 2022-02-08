/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_take.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:17:26 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/07 15:11:00 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	fork_take(struct s_fork *fork, int philo, int hand)
{
	bool	result;

	philo = philo * 2 + hand;
	pthread_mutex_lock(&fork->mutex);
	if (fork->value == false || fork->holder == philo)
	{
		fork->value = true;
		fork->holder = philo;
		result = true;
	}
	else
	{
		result = false;
	}
	pthread_mutex_unlock(&fork->mutex);
	return (result);
}
