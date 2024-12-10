/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:36:31 by apalaz            #+#    #+#             */
/*   Updated: 2023/12/15 16:00:18 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(t_ui, char))
{
	char	*rtrn;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	rtrn = (char *) malloc(slen + 1);
	if (!rtrn)
		return (NULL);
	i = -1;
	while (s[++i])
		rtrn[i] = f((t_ui) i, s[i]);
	rtrn[i] = 0;
	return (rtrn);
}
