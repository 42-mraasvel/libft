/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_first_of.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 16:15:21 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/10/31 16:23:01 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*find_first_of(char *s, int (*is_function)(int))
{
	while (*s != '\0' && !is_function(*s))
	{
		++s;
	}
	return (s);
}
