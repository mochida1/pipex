/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:33:27 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/24 17:01:56 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*make_splitting_easier(char *args)
{
	int		i;
	int		flag;
	char	quote_type;

	i = 0;
	quote_type = 0;
	flag = 0;
	while (args[i])
	{
		if ((args[i] == '"' || args[i] == '"') && !flag)
		{
			flag = 1;
			quote_type = args[i];
		}
		else if (args[i] == quote_type && flag)
		{
			flag = 0;
		}
		else if (args[i] == ' ' && flag)
			args[i] = 1;
		i++;
	}
	return (args);
}

// char	*unmake_splitting_easier(char *args)
// {
// 	args[i]
// }