/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   me.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:01:18 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/18 21:49:23 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int main (int argc, char* argv[])
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
