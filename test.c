/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:52:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/27 17:43:53 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static void	free_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings[i] != NULL)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

static int	print_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings[i] != NULL)
	{
		if (fprintf(stdout, "%d: %s\n", i + 1, strings[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	split_compare(const char *src, char *set)
{
	static int	cnt;
	char		**strings;

	cnt++;
	strings = ft_split_set(src, set);
	if (strings == NULL)
	{
		fprintf(stderr, "Fail at test |%d|\n", cnt);
		return (-1);
	}
	free_strings(strings);
	fprintf(stderr, "Success at test |%d|\n", cnt);
	return (0);
}

int	main(void)
{
	split_compare("255.255.255.255 25", ". ");
	return (0);
}
