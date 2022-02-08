/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:19:27 by enijakow          #+#    #+#             */
/*   Updated: 2022/01/21 13:55:55 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clock_create(struct s_clock *clock)
{
	struct timeval	tv;
	unsigned long	diff;

	gettimeofday(&tv, NULL);
	diff = tv.tv_sec;
	diff *= 1000000;
	diff += tv.tv_usec;
	clock->timestamp_created = diff;
}
