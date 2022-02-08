/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:23:25 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/06 15:30:24 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_create(struct s_fork *fork)
{
	pthread_mutex_init(&fork->mutex, NULL);
	fork->value = false;
	fork->holder = -1;
}
