/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:33:27 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/25 21:59:30 by hmochida         ###   ########.fr       */
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
		if ((args[i] == '\"' || args[i] == '\'') && !flag)
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

char	**unmake_splitting_easier(char **ret)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ret[i])
	{
		while (ret[i][j])
		{
			if (ret[i][j] == 1)
				ret[i][j] = ' ';
			j++;
		}
		j = 0;
		i++;
	}
	return (ret);
}

static char	check_trim(char *ret_i)
{
	int		i;
	int		flag;
	char	quote_type;

	i = 0;
	quote_type = 0;
	flag = 0;
	while (ret_i[i] && flag < 2)
	{
		if (ret_i[i] == quote_type && flag)
			flag++;
		if ((ret_i[i] == '\'' || ret_i[i] == '\"') && (flag == 0))
		{
			flag++;
			quote_type = ret_i[i];
		}
		i++;
	}
	if (flag >= 2)
		return (quote_type);
	return (0);
}

static char	*trimzor(char *str, char c)
{
	int		i[3];
	char	*ret;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	ret = malloc (sizeof (char) * ft_strlen(str) - 1);
	while (str[i[0]])
	{
		if (str[i[0]] == c)
		{
			i[0]++;
			i[2]++;
		}
		else
			ret[i[1]++] = str[i[0]++];
	}
	ret[i[1]] = '\0';
	return (ret);
}

char	**trim_all_quote_pairs(char **ret)
{
	int		i;
	char	quote;
	char	*temp;

	i = 0;
	quote = check_trim(ret[i]);
	while (ret[i])
	{
		quote = check_trim(ret[i]);
		if (quote)
		{
			temp = trimzor(ret[i], quote);
			free (ret[i]);
			ret[i] = temp;
		}
		else
			i++;
	}
	return (ret);
}
