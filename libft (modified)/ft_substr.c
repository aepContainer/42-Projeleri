/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:29:04 by apalaz            #+#    #+#             */
/*   Updated: 2023/12/15 16:00:00 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, t_ui start, size_t len)
{
	char	*rtrn;
	size_t	i;
	size_t	cpystart;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	cpystart = (size_t) start;
	if (i < cpystart)
		return (ft_strdup(""));
	if (i - cpystart < len)
		len = i - (size_t) cpystart;
	rtrn = (char *) malloc(len + 1);
	if (!rtrn)
		return (NULL);
	i = -1;
	while (s[cpystart] && ++i < len)
	{
		rtrn[i] = s[cpystart];
		cpystart++;
	}
	if (!s[cpystart])
		i++;
	rtrn[i] = 0;
	return (rtrn);
}
