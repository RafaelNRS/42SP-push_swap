/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:53:48 by ranascim          #+#    #+#             */
/*   Updated: 2023/02/23 00:32:52 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int is_integer(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strncmp(ft_itoa(ft_atoi(argv[i])), argv[i], ft_strlen(argv[i])))
			return (0);
		i++;
	}
	return 1;
}

int	is_duplicate(int argc, char **argv)
{
	int	i;
	int	j;
	size_t	max;

	i = 1;
	while (i <= argc)
	{
		j = i + 1;
		while (j < argc)
		{
			max = 0;
			if (ft_strlen(argv[j]) > max)
				max = ft_strlen(argv[j]);
			if (ft_strlen(argv[i]) > max)
				max = ft_strlen(argv[i]);
			if (! ft_strncmp(argv[i], argv[j], max))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack *get_last(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void g_leave(int exit_code)
{
	exit(exit_code);
}

t_stack *create_new_stack(int value)
{
	t_stack *stack;
	
	stack = malloc(sizeof(t_stack));
	stack->value = value;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

void add_at_bottom(t_stack **stack, t_stack *new)
{
	t_stack *last;

	if (!new)
	{
		return ;
	}
	if (!*stack)
	{
		(*stack) = new;
		return ;
	}
	last = get_last(*stack);
	last->next = new;
	new->prev = last;
}

t_stack *initialize_stack(char **argv) 
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	i = 1;
	while (argv[i])
	{
		add_at_bottom(&stack_a,create_new_stack(ft_atoi(argv[i])));
		i++;
	}
	return stack_a;
}

int get_stack_size(t_stack *stack)
{
	int i;

	i = 1;
	while (stack && stack->next != NULL)
	{
		//ft_printf("%d\n",stack->value);
		stack = stack->next;
		i++;
	}
	//ft_printf("%d\n",stack->value);
	//ft_printf("Stack size: %d\n",i);
	return (i);
}

int get_stack_size_radix(t_stack *stack)
{
	int i;

	i = 0;
	while (stack && stack->next != NULL)
	{
		i++;
		stack = stack->next;
	}
	if (i > 0 && stack->next == NULL)
		i++;
	return (i);
}

void	print_stack(t_stack **stack)
{
	t_stack *stack_tmp;

	stack_tmp = *stack;
	while (stack_tmp && stack_tmp->next != NULL)
	{
		ft_printf("Value: %d - Index: %d\n",stack_tmp->value,stack_tmp->index);
		stack_tmp = stack_tmp->next;
	}
	if (stack_tmp)
		ft_printf("Value: %d - Index: %d\n",stack_tmp->value,stack_tmp->index);
}

void	fill_indexes(t_stack **stack)
{
	t_stack *s1;
	t_stack *s2;

	s1 = (*stack);
	while (s1)
	{
		s1->index = 1;
		s2 = (*stack);
		while (s2)
		{
			if (s1->value > s2->value)
				s1->index++;
			s2 = s2->next;
		}
		s1 = s1->next;
	}
	//print_stack(stack);
	//printf("END - FILL INDEX\n");
}

int is_sorted(t_stack **stack)
{
	t_stack *stack_tmp;

	stack_tmp = *stack;
	while (stack_tmp->next != NULL)
	{
		if (stack_tmp->value > stack_tmp->next->value)
			return (0);
		stack_tmp = stack_tmp->next;
	}
	return (1);
}

void sort_three(t_stack **stack)
{
	int	max_index;
	t_stack	*stack_tmp;
	
	stack_tmp = *stack;
	max_index = stack_tmp->index;
	while (stack_tmp)
	{
		if (stack_tmp->index > max_index)
			max_index = stack_tmp->index;
		stack_tmp = stack_tmp->next;	
	}
	//print_stack(stack);
	if ((*stack)->index == max_index)
		ra(stack);
	else if ((*stack)->next->index == max_index)
		rra(stack);
	//print_stack(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

int get_max_number(t_stack *stack)
{
	int max_num;
	
	max_num = stack->index;
	while(stack && stack->next != NULL)
	{
		if (stack->index > max_num)
			max_num = stack->index;
		stack = stack->next;
	}
	return (max_num);
}

int get_max_bits(int n)
{
	int max_bits;
	
	max_bits = 0;
	while (n)
	{
		max_bits++;
		n >>= 1;
	}
	return (max_bits);
}

void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	//int	size_a;
	int size_b;
	int max_num;
	//int max_bits;
	int i;
	int j;

	max_num = get_stack_size_radix(*stack_a);
	//max_bits = get_max_bits(max_num);
	i = 0;
	while (!is_sorted(stack_a))
	{
		j = 0;
		while (j < max_num)
		{
			//printf("j = %d, max_num = %d, i = %d, max_bits = %d\n",j,max_num,i,max_bits);
			if (((*stack_a)->index >> i) & 1)
			{	
				//printf("Will do ra\n");
				//print_stack(stack_a);
				ra(stack_a);
			}
			else
			{
				//printf("Will do pb\n");
				//print_stack(stack_a);
				pb(stack_a, stack_b);
			}
			j++;
		}
		i++;
		size_b = get_stack_size_radix(*stack_b);
		//printf("Stack B:\n");
		//print_stack(stack_b);
		//printf("Size_b: %d\n",size_b);
		while (size_b > 0)
		{
			pa(stack_a, stack_b);
			size_b--;
		}
		//print_stacks(stack_a, stack_b);
		//printf("Stack A:\n");
		//print_stack(stack_a);
		//printf("Stack B:\n");
		//print_stack(stack_b);

	}
}

void sort(t_stack **stack_a)
{
	t_stack *stack_b;

	stack_b = NULL;
	radix_sort(stack_a, &stack_b);
}

void order_stack(t_stack **stack_a, int stack_size)
{
	if (is_sorted(stack_a))
		return ;
	else if (stack_size == 2)
		sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else
		sort(stack_a);
	//print_stack(stack_a);
}

int main(int argc, char *argv[]) 
{
	t_stack *stack_a;
	int stack_size;

	//printf("%d\n",argc);
	if (! is_integer(argv) || ! is_duplicate(argc,argv))
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	stack_a = initialize_stack(argv);
	stack_size = get_stack_size(stack_a);
	fill_indexes(&stack_a);
	order_stack(&stack_a, stack_size);

	return (0);
}