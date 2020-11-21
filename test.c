/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:52:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/21 17:01:04 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	dbl_exponent(double nbr)
{
	int	e;

	e = 0;
	while (nbr < 1 && nbr > -1)
	{
		nbr *= 10;
		e--;
	}
	while (nbr >= 10 || nbr <= -10)
	{
		nbr /= 10;
		e++;
	}
	return (e);
}

int	main(void)
{
	unsigned long long nbr;
	char *result;

	nbr = 1;
	result = ft_llutoa(nbr, 5);
	printf("result: %s\n", result);
	free(result);
	return (0);
}
