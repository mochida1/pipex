/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   me.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:01:18 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/24 16:34:42 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int main (void)
{
	char *args = "CMD '123 456'";
	int		i;
	int		flag;
	char	quote_type;

	printf(">>%s\n", args);
	i = 0;
	quote_type = 0;
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
	printf("<<%s\n", args);
	return (0);
}

/* int main (int argc, char* argv[]) // imprime argv's
{
	int i;

	printf("ARGC: %d\n",argc);
	i = 0;

	while (argv[i])
	{
		printf("ARGV[%d]: >>%s<<\n",i, argv[i]);
		i++;
	}
	return (0);
}
 */