/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:25:38 by apalaz            #+#    #+#             */
/*   Updated: 2023/12/15 16:01:28 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static long	ft_atoi_part2(char *str, short sign)
{
	long	rtrn;
	short	state;
	int		i;

	rtrn = 0;
	state = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_isspace(str[i]))
			state = 1;
		if (!ft_isdigit(str[i]) || (state && ft_isdigit(str[i])))
			return ((long) __INT_MAX__ + 1);
		rtrn = (rtrn * 10) + (str[i] - 48);
	}
	rtrn *= sign;
	if (rtrn > __INT_MAX__ || rtrn < (-1 * __INT_MAX__ - 1))
		return ((long) __INT_MAX__ + 1);
	return (rtrn);
}

int	ft_atoi(char *str)
{
	long	rtrn;
	short	sign;

	if (!str[0])
		return (0);
	rtrn = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	rtrn = ft_atoi_part2(str, sign);
	if (rtrn == (long) __INT_MAX__ + 1)
		return (0);
	return ((int) rtrn);
}
