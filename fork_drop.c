/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_drop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:20:50 by enijakow          #+#    #+#             */
/*   Updated: 2022/01/17 15:29:53 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_drop(struct s_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->value = false;
	pthread_mutex_unlock(&fork->mutex);
}
