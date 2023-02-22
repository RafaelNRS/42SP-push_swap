/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:22:17 by ranascim          #+#    #+#             */
/*   Updated: 2023/02/22 21:45:44 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rev_rotate(t_stack **stack)
{
	t_stack *stack_tmp;
	t_stack *stack_last;
	t_stack *stack_blast;

	stack_last = get_last(*stack);
	stack_blast = stack_last->prev;
	
	stack_tmp = (*stack);
	*stack = stack_last;
	(*stack)->next = stack_tmp;
	stack_tmp->prev = (*stack);
	(*stack)->prev = NULL;
	stack_blast->next = NULL;	
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
