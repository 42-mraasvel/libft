/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:52:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/20 14:06:05 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	char	*strings;
	char	*str = "abcdef";

	strings = ft_join_n_strings(6, "1", "2", "3", "4", "56", str);
	if (strings == NULL)
		return (-1);
	printf("%s\n", strings);
	free(strings);
	return (0);
}
