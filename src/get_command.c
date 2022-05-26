/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:25:03 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/25 20:45:16 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_command(char **args, int index)
{
	char	**ret;

	args[index] = make_splitting_easier(args[index]);
	ret = ft_split(args[index], ' ');
	ret = unmake_splitting_easier(ret);
	ret = trim_all_quote_pairs(ret);
	return (ret);
}
