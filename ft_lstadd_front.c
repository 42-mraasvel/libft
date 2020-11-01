/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 14:47:43 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/28 18:44:23 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == 0)
		return ;
	if (*lst == 0 && new != 0)
	{
		*lst = new;
		return ;
	}
	if (new == 0 || *lst == 0)
		return ;
	new->next = *lst;
	*lst = new;
}
