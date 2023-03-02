/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:01:47 by ranascim          #+#    #+#             */
/*   Updated: 2023/03/02 12:14:58 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <push_swap.h>

struct	s_stack {
	int				value;
	int				index;
	struct s_stack	*next;
};

typedef struct s_stack	t_stack;

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

t_stack	*get_last(t_stack *stack);
t_stack	*get_last_but_one(t_stack *stack);
int		is_sorted(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_four_five(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
int		is_integer(char **argv);
int		is_duplicate(int argc, char **argv);
t_stack	*create_new_stack(int value);
void	add_at_bottom(t_stack **stack, t_stack *new);
t_stack	*initialize_stack(char **argv);
int		get_stack_size(t_stack *stack);
void	fill_indexes(t_stack **stack);
void	print_stack(t_stack **stack);

#endif
