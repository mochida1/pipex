/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 04:59:21 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/13 23:42:04 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t len;

	len = (size_t)ft_strlen(s) * sizeof(char);
	write(fd, s, len);
}
