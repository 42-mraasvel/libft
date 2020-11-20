/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:52:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/20 10:03:31 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	double	d;
	char	*string;
	int pow;

	d = 0.000345;
	pow = ft_get_tenth_exp(d);
	printf("e: %.8e\n%d\n", d, pow);
	ft_putdouble_sn(d, 8);
	free(string);
	return (0);
}
