/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:53:28 by apalaz            #+#    #+#             */
/*   Updated: 2023/12/15 16:00:36 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*rtrn;
	size_t	lens1;

	if (!s)
		return (NULL);
	lens1 = ft_strlen(s);
	rtrn = (char *) malloc(lens1 + 1);
	if (!rtrn)
		return (NULL);
	rtrn = (char *) ft_memmove(rtrn, s, lens1 + 1);
	return (rtrn);
}
