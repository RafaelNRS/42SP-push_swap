/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:53:48 by ranascim          #+#    #+#             */
/*   Updated: 2023/03/02 13:24:50 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	free_stacks(t_stack **stack)
{
	t_stack	*tmp;

	while ((*stack))
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
	}
	stack = NULL;
}

void	sort(t_stack **stack_a, int stack_size)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (stack_size <= 5)
		sort_four_five(stack_a, &stack_b);
	else
		radix_sort(stack_a, &stack_b);
}

void	sort_stack(t_stack **stack_a, int stack_size)
{
	if (is_sorted(stack_a))
		return ;
	else if (stack_size == 2)
		sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else
		sort(stack_a, stack_size);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	int		stack_size;

	if (! is_integer(argv) || ! is_duplicate(argc, argv))
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	stack_a = initialize_stack(argv);
	stack_size = get_stack_size(stack_a);
	fill_indexes(&stack_a);
	sort_stack(&stack_a, stack_size);
	free_stacks(&stack_a);
	return (0);
}
