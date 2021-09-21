/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:36:15 by chasimir          #+#    #+#             */
/*   Updated: 2021/09/21 16:09:39 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_spisochek
{
	int					value;
	int					elem_score;
	struct s_spisochek	*next;
	struct s_spisochek	*prev;
}	t_spisochek;

typedef struct s_ab
{
	struct s_spisochek	*a;
	struct s_spisochek	*b;
	int					a_size;
	int					b_size;
}	t_ab;

t_spisochek	*create(int data);
void		add_ellement_end(t_spisochek **a, t_spisochek *new);
void		push_check(t_ab *stack, char c);
void		swap_check(t_ab *stack, char c);
void		rotate_check(t_ab *stack, char c);
void		reverse_rotate_check(t_ab *stack, char c);

long int	ft_atoi(const char *str);
void		sort(t_ab *stack, int argc);
int			sort_check(t_spisochek **head);

int			search_max(t_spisochek	**head, int size);
int			search_min(t_spisochek **head, int size);

void		sort_max(t_ab *stack, int argc);

int			check_rev_sort(t_ab *stack, char c);
int			*make_arr(t_ab *stack, int argc);
int			search_mid(int *arr, int argc);
int			mod(int num);
void		rot_and_push_ba(t_ab *stack, t_spisochek *min_score, int position);
void		forw_or_rev(t_ab *stack);
void		push_to_b(t_ab *stack, int min, int max, int mid);
int			calc_rot_a(t_ab *stack, int value);

#endif
