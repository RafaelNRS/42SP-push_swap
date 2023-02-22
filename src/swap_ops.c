/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:29:23 by ranascim          #+#    #+#             */
/*   Updated: 2023/02/22 21:48:30 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void swap(t_stack **stack)
{
	int value_tmp;
	int index_tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;
	value_tmp = (*stack)->value;
	index_tmp = (*stack)->index;
	(*stack)->value = (*stack)->next->value;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->value = value_tmp;
	(*stack)->next->index = index_tmp;
}

void sa(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void sb(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
