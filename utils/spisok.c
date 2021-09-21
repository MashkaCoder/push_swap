/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spisok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:46:15 by chasimir          #+#    #+#             */
/*   Updated: 2021/09/21 13:37:13 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_spisochek	*create(int data)
{
	t_spisochek	*tmp;

	tmp = (t_spisochek *)malloc(sizeof(t_spisochek));
	if (!tmp)
		return (0);
	tmp->value = data;
	tmp->next = tmp;
	tmp->prev = tmp;
	return (tmp);
}

void	add_ellement_end(t_spisochek **a, t_spisochek *new)
{
	t_spisochek	*tmp;

	tmp = *a;
	if (!*a)
		*a = new;
	if (tmp)
	{
		new->next = tmp;
		new->prev = tmp->prev;
		tmp->prev->next = new;
		tmp->prev = new;
	}
}
