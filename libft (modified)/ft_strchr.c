/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:50:55 by apalaz            #+#    #+#             */
/*   Updated: 2023/12/19 17:31:04 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NULL (void *) 0

char	*ft_strchr(const char *s, int c)
{
	char	*rtrn;
	int		i;

	if (!s)
		return (NULL);
	rtrn = (char *) s;
	i = -1;
	while (rtrn[++i])
		if (rtrn[i] == (char) c)
			return (rtrn + i);
	if (rtrn[i] == (char) c)
		return (rtrn + i);
	return (NULL);
}
