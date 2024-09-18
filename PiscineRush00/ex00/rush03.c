/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:03:29 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/10 19:43:42 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_char(int x, int y, int width, int height)
{
	if (height == 0 || height == y - 1)
	{
		if (width == 0)
			ft_putchar('A');
		else if (width == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else if (width == 0 || width == x -1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	height;
	int	width;

	height = 0;
	while (height < y)
	{
		width = 0;
		while (width < x)
		{
			print_char(x, y, width, height);
			width++;
		}
		ft_putchar('\n');
		height++;
	}
}
