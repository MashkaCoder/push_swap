/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:46:18 by chasimir          #+#    #+#             */
/*   Updated: 2021/09/21 17:24:49 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search_mid(int *arr, int argc)
{
	int	min;
	int	max;
	int	mid;

	min = arr[0];
	max = arr[argc - 2];
	mid = arr[(argc - 1) / 2];
	return (mid);
}

void	sort_arr(int *arr, int argc)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*make_arr(t_ab *stack, int argc)
{
	int			i;
	int			*arr;
	t_spisochek	*tmp;

	i = 0;
	tmp = stack->a;
	arr = malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (NULL);
	while (i < argc - 1)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sort_arr(arr, argc);
	return (arr);
}
