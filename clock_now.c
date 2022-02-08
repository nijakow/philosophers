/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock_now.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:20:36 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/07 17:37:36 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	clock_now(struct s_clock *clock)
{
	struct timeval	tv;
	unsigned long	diff;

	gettimeofday(&tv, NULL);
	diff = tv.tv_sec;
	diff *= 1000000;
	diff += tv.tv_usec;
	return ((diff - clock->timestamp_created) / 1000);
}
