/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:16:06 by enijakow          #+#    #+#             */
/*   Updated: 2022/02/10 17:34:30 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "philo.h"

static int	ft_atoi_isspace(int c)
{
	return ((c == ' ')
		|| (c == '\t')
		|| (c == '\n')
		|| (c == '\r')
		|| (c == '\v')
		|| (c == '\f'));
}

static int	ft_atoi_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

static void	ft_atoi_skipspace(char **str)
{
	while (ft_atoi_isspace(**str))
		(*str)++;
}

static void	ft_atoi_primer(char **str, int *sign)
{
	*sign = 1;
	ft_atoi_skipspace(str);
	if (**str == '+')
		(*str)++;
}

int	ft_atoi(char *str, int *v)
{
	long	value;
	int		sign;

	value = 0;
	ft_atoi_primer(&str, &sign);
	if (!ft_atoi_isdigit(*str))
		return (0);
	while (ft_atoi_isdigit(*str))
	{
		value = (value * 10) + (*str - '0');
		str++;
	}
	if ((value * sign) < INT_MIN || (value * sign) >= INT_MAX)
		return (0);
	*v = value * sign;
	ft_atoi_skipspace(&str);
	return (*str == '\0');
}
