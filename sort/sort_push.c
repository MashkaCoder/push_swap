/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:46:50 by chasimir          #+#    #+#             */
/*   Updated: 2021/09/20 22:46:51 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_b(t_ab *stack, int min, int max, int mid)
{
	while (stack->a_size > 2)
	{
		if (stack->a->value > mid && stack->a->value != min
			&& stack->a->value != max)
		{
			push_check(stack, 'b');
			rotate_check(stack, 'b');
		}
		else if (stack->a->value <= mid && stack->a->value != min
			&& stack->a->value != max)
			push_check(stack, 'b');
		else
			rotate_check(stack, 'a');
	}
	if (stack->a->value == min)
		rotate_check(stack, 'a');
}
