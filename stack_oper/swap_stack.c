/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:47:18 by chasimir          #+#    #+#             */
/*   Updated: 2021/09/21 13:38:54 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_spisochek **head)
{
	t_spisochek	*second;
	int			tmp;

	tmp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = tmp;
}

void	swap_check(t_ab *stack, char c)
{
	if (c == 'a' && stack->a && stack->a->next)
	{
		swap(&stack->a);
		write(1, "sa\n", 3);
	}
	if (c == 'b' && stack->b && stack->b->next)
	{
		swap(&stack->b);
		write(1, "sb\n", 3);
	}
	if (c == 's' && stack->a && stack->a->next && stack->b && stack->b->next)
	{
		swap(&stack->a);
		swap(&stack->b);
		write(1, "ss\n", 3);
	}
}
