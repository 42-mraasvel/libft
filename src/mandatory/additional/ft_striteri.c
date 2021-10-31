/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 14:43:45 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/10/31 14:58:19 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
New function with the latest libft
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*ptr;

	ptr = s;
	while (*ptr)
	{
		f(ptr - s, ptr);
		++ptr;
	}
}
