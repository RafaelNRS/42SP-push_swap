/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:50:57 by ranascim          #+#    #+#             */
/*   Updated: 2023/02/22 23:03:25 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rotate(t_stack **stack)
{
	t_stack *stack_tmp;
	t_stack *stack_last;

	if ((*stack)->next)
	{
		stack_tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		stack_last = get_last(*stack);
		stack_tmp->next = NULL;
		stack_last->next = stack_tmp;
		stack_tmp->prev = stack_last;
	}
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
