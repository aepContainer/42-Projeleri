/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:30:32 by apalaz            #+#    #+#             */
/*   Updated: 2023/12/15 15:59:29 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*rtrn;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	rtrn = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!rtrn)
		return (0);
	len1 = -1;
	while (s1[++len1])
		rtrn[len1] = s1[len1];
	len2 = -1;
	while (s2[++len2])
		rtrn[len1 + len2] = s2[len2];
	rtrn[len1 + len2] = 0;
	if (s1)
		free(s1);
	return (rtrn);
}
