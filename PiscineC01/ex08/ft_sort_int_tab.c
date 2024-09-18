/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:38:21 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/20 12:06:10 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	x;
	int	y;
	int	aux;

	x = 0;
	while (x < size - 1)
	{
		y = 0;
		while (y < size - 1)
		{
			if (tab[y] > tab[y + 1])
			{
				aux = tab[y];
				tab[y] = tab[y + 1];
				tab[y + 1] = aux;
			}
			y++;
		}
		x++;
	}
}

/*int	main(void)
{
	int	tab[5] = { 2, 1, 5, 3, 4 };
	int	size = 5;
	int	a;

	a = 0;
	ft_sort_int_tab(tab, size);
	while (a <= size - 1)
	{
		printf("%d", tab[a]);
		a++;
	}
}*/
