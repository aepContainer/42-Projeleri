/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:58:02 by apalaz            #+#    #+#             */
/*   Updated: 2024/01/15 17:03:30 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "stdlib.h"

char	ctrl_nl(char *str)
{
	t_ui	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

t_ui	ft_strlen(char *str)
{
	t_ui	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*rtrn;
	int		len1;
	int		len2;

	if (!s1)
	{
		s1 = (char *) malloc(1);
		*s1 = 0;
	}
	if (!s1 || !s2)
		return (0);
	len1 = (int) ft_strlen(s1);
	len2 = (int) ft_strlen(s2);
	rtrn = malloc(len1 + len2 + 1);
	if (!rtrn)
		return (0);
	len1 = -1;
	while (s1[++len1])
		rtrn[len1] = s1[len1];
	len2 = -1;
	while (s2[++len2])
		rtrn[len1 + len2] = s2[len2];
	rtrn[len1 + len2] = 0;
	free(s1);
	return (rtrn);
}