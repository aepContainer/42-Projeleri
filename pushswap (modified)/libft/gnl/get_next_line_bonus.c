/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:58:05 by apalaz            #+#    #+#             */
/*   Updated: 2024/01/16 15:57:11 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_next_line_b(int fd)
{
	static char		*line_with_ol[10000];
	char			*line_wout_ol;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line_with_ol[fd] = get_line_wol(fd, line_with_ol[fd]);
	if (!line_with_ol[fd])
		return (0);
	line_wout_ol = get_line_wout(line_with_ol[fd]);
	line_with_ol[fd] = get_buff(line_with_ol[fd]);
	return (line_wout_ol);
}
