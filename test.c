/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:52:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/19 13:49:55 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	double	d;

	// d = 199999.9964567;
	d = 0.00000294;
	ft_put_double(d, -1);
	write(1, "\n", 1);
	return (0);
}
