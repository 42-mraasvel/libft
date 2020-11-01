/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 13:37:56 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/29 11:10:53 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	strrset(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != 0)
		i++;
	i--;
	while (i > 0 && ft_isset(s1[i], set) == 1)
		i--;
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*dest;

	i = 0;
	if (set == 0 || s1 == 0)
		return (0);
	while (s1[i] != 0 && ft_isset(s1[i], set) == 1)
		i++;
	len = strrset(&s1[i], set) + 1;
	dest = (char*)malloc((len + 1) * sizeof(char));
	if (dest == 0)
		return (0);
	dest[len] = 0;
	j = 0;
	while (j < len && len > 0)
	{
		dest[j] = s1[j + i];
		j++;
	}
	return (dest);
}
