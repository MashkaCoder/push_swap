/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:47:07 by chasimir          #+#    #+#             */
/*   Updated: 2021/09/21 15:14:39 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search_min(t_spisochek **head, int size)
{
	int			i;
	int			n;
	t_spisochek	*tmp;

	i = 0;
	tmp = *head;
	n = tmp->value;
	while (i < size)
	{
		if (n > tmp->value)
			n = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (n);
}

int	search_max(t_spisochek	**head, int size)
{
	int			i;
	int			n;
	t_spisochek	*tmp;

	i = 0;
	tmp = *head;
	if (!*head)
		return (0);
	n = tmp->value;
	while (i < size)
	{
		if (n < tmp->value)
			n = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (n);
}

void	sort3(t_ab	*stack)
{
	int			min;
	int			max;
	t_spisochek	*tmp;

	tmp = stack->a;
	min = search_min(&stack->a, stack->a_size);
	max = search_max(&stack->a, stack->a_size);
	while (sort_check(&stack->a))
	{
		if (tmp->value == max)
			rotate_check(stack, 'a'), tmp = stack->a;
		if (tmp->value < tmp->next->value && tmp->next->value == max)
			reverse_rotate_check(stack, 'a'), tmp = stack->a;
		if (tmp->value > tmp->next->value && tmp->next->value == min)
			swap_check(stack, 'a'), tmp = stack->a;
	}
}

void	sort5(t_ab *stack)
{
	int			min;
	int			max;

	min = search_min(&stack->a, stack->a_size);
	max = search_max(&stack->a, stack->a_size);
	while (stack->a_size != 3)
	{
		if (stack->a->value == max || stack->a->value == min)
			rotate_check(stack, 'a');
		else
			push_check(stack, 'b');
	}
	sort3(stack);
	reverse_rotate_check(stack, 'a');
	if (stack->b->value < stack->b->next->value)
		swap_check(stack, 'b');
	while (stack->b)
	{
		while ((stack->b->value > stack->a->value)
			 || stack->a->prev->value > stack->b->value)
			reverse_rotate_check(stack, 'a');
		push_check(stack, 'a');
	}
	while (sort_check(&stack->a))
		reverse_rotate_check(stack, 'a');
}

void	sort(t_ab *stack, int argc)
{
	if (argc == 3)
		swap_check(stack, 'a');
	else if (argc == 4)
		sort3(stack);
	else if (argc <= 6)
		sort5(stack);
	else if (argc > 6)
		sort_max(stack, argc);
}
