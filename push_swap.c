/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:36:01 by chasimir          #+#    #+#             */
/*   Updated: 2021/09/21 17:28:25 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_ab *stack)
{
	t_spisochek	*head_a;
	t_spisochek	*head_b;

	head_a = NULL;
	head_b = NULL;
	stack->a = NULL;
	stack->b = NULL;
	stack->a_size = 0;
	stack->b_size = 0;
}

int	double_check(t_spisochek **head, long int n, int size)
{
	int			i;
	t_spisochek	*tmp;

	i = 0;
	tmp = *head;
	while (i < size)
	{
		if (tmp->value == n)
			return (1);
		tmp = tmp->next;
		i++;
	}
	if (n > 2147483647 || n < -2147483648)
		return (1);
	return (0);
}

int	sort_check(t_spisochek **head)
{
	t_spisochek	*tmp;
	t_spisochek	*last;

	tmp = *head;
	last = (*head)->prev;
	if (!(*head))
		return (-1);
	while (tmp != last)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	long int	n;
	t_ab		stack;
	t_spisochek	*tmp;

	i = 1;
	create_stack(&stack);
	if (argc > 1)
	{
		while (argv[i])
		{
			n = ft_atoi(argv[i]);
			tmp = create(n);
			if (!tmp || double_check(&stack.a, n, stack.a_size))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			add_ellement_end(&stack.a, tmp);
			stack.a_size = i, i++;
		}
		if (sort_check(&stack.a))
			sort(&stack, argc);
	}
	exit(EXIT_SUCCESS);
}
