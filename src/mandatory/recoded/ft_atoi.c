/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:56:28 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/10/31 16:36:03 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	negative;

	nptr = find_first_not_of((char *)nptr, ft_isspace);
	if (*nptr == '+' || *nptr == '-')
	{
		negative = (*nptr == '-');
		++nptr;
	}
	nbr = 0;
	while (ft_isdigit(*nptr))
	{
		nbr = (nbr * 10) + (*nptr - '0');
		++nptr;
	}
	if (negative)
		return (-nbr);
	return (nbr);
}
