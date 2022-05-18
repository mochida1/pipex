/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:43:18 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/18 14:37:34 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

char	*ft_strdup(const char *s1)
{
	int		l;
	char	*c;
	int		i;

	i = 0;
	l = ft_strlen(s1) + 1;
	if (!(c = malloc(l * (sizeof(char)))))
		return (0);
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
