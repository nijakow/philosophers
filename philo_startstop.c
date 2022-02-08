/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_startstop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:51:02 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/07 17:51:13 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_start(struct s_philo *philo)
{
	pthread_create(&philo->thread, NULL, philo_main, philo);
}

void	philo_join(struct s_philo *philo)
{
	pthread_join(philo->thread, NULL);
}
