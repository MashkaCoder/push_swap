/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:46:57 by chasimir          #+#    #+#             */
/*   Updated: 2021/09/21 13:38:45 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_spisochek **to, t_spisochek **from)
{
	t_spisochek	*tmp_from;

	tmp_from = NULL;
	if ((*from) != (*from)->next)
	{
		tmp_from = (*from)->next;
		tmp_from->prev = (*from)->prev;
		(*from)->prev->next = tmp_from;
	}
	if (!(*to))
	{
		(*from)->next = *from;
		(*from)->prev = *from;
	}
	else
	{
		(*from)->next = *to;
		(*to)->prev->next = *from;
		(*from)->prev = (*to)->prev;
		(*to)->prev = *from;
	}
	*to = *from;
	*from = tmp_from;
}

void	push_check(t_ab *stack, char c)
{
	if (c == 'a' && stack->b)
	{
		push(&stack->a, &stack->b);
		stack->a_size++;
		stack->b_size--;
		write(1, "pa\n", 3);
	}
	if (c == 'b' && stack->a)
	{
		push(&stack->b, &stack->a);
		stack->a_size--;
		stack->b_size++;
		write(1, "pb\n", 3);
	}
}
