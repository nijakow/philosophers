/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:38:18 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/08 18:39:51 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_create(struct s_philo *philo,
			struct s_philos *philos,
			unsigned int num)
{
	philo->philos = philos;
	philo->num = num;
	philo->state = STATE_SLEEPING;
	philo->rounds = 0;
	philo->has_forks = false;
}
