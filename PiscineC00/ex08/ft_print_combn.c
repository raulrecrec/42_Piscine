/* ************************************************************************** */
/*                                                                          */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:48:14 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/14 17:57:35 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(int *numbers, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(numbers[i] + '0');
		i++;
	}
}

void	ft_update_numbers(int *numbers, int n)
{
	int	i;
	int	j;

	i = n - 1;
	while (i >= 0 && numbers[i] == 9 - (n - 1 - i))
		i--;
	numbers[i]++;
	j = i + 1;
	while (j < n)
	{
		numbers[j] = numbers[j - 1] + 1;
		j++;
	}
}

void	ft_print_combn(int n)
{
	int	numbers[10];
	int	i;

	if (n <= 0 || n >= 10)
		return ;
	i = 0;
	while (i < n)
	{
		numbers[i] = i ;
		i++;
	}
	while (numbers[0] <= 10 - n)
	{
		ft_print_numbers(numbers, n);
		if (numbers[0] == 10 - n)
			break ;
		ft_putchar(',');
		ft_putchar(' ');
		ft_update_numbers(numbers, n);
	}
}
