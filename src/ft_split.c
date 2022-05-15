/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:32:21 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/15 16:28:52 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

static int count_words(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] && s[i] == c)
		i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				i++;
			}
			count++;
		}
	}
	return (count);
}
//01234

static char *copy_split(char *s, char c)
{
	char *split;
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	split = malloc (i * sizeof (char) + 1);
	while (j <= i)
	{
		split[j] = s[j];
		j++;
	}
	return (split);
}

/*
splits a string into a vector of strings, using c as separator.
*/
char **ft_split(char *s, char c)
{
	char **result;
	int word_count;
	int i;
	int j;

	word_count = count_words(s, c);
	result = malloc ((sizeof (char *) * word_count) + 1);
	result[word_count] = NULL;
	i = 0;
	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		else if (*s)
		{
			result[j] = copy_split(s, c);
			while (*s && *s != c)
				s++;
		}

	}
	return (result);
}
