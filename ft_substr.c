/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 19:54:14 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/30 13:14:50 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*create_empty_string(void)
{
	char	*dest;

	dest = (char*)malloc(1 * sizeof(char));
	if (dest == 0)
		return (0);
	dest[0] = 0;
	return (dest);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	if (ft_strlen(s) <= start)
		return (create_empty_string());
	while (s[start + i] != 0)
		i++;
	if (i < len)
		substr = (char*)malloc(i + 1);
	else
		substr = (char*)malloc(len + 1);
	if (substr == 0)
		return (0);
	if (i < len)
		ft_strlcpy(substr, &s[start], i + 1);
	else
		ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}
