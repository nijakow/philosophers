/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_get_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:12:34 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/07 17:40:20 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct s_fork	*philos_get_fork(struct s_philos *philos,
					unsigned int fork)
{
	return (&philos->entries[fork % philos->table_size].fork);
}
