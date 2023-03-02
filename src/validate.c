/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:57:22 by ranascim          #+#    #+#             */
/*   Updated: 2023/03/02 13:16:51 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_integer(char **argv)
{
	int		i;
	char	*c;

	i = 1;
	while (argv[i])
	{
		c = ft_itoa(ft_atoi(argv[i]));
		if (ft_strncmp(c, argv[i], ft_strlen(argv[i])))
			i++;
		else
		{
			free(c);
			return (1);
		}
		free(c);
	}
	return (0);
}

int	is_duplicate(int argc, char **argv)
{
	int		i;
	int		j;
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
