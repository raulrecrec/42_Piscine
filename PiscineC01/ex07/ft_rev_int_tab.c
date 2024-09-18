/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:39:16 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/20 12:09:08 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	x;
	int	y;
	int	aux1;
	int	aux2;

	x = 0;
	y = size - 1;
	while (x < size / 2)
	{
		aux1 = tab[x];
		aux2 = tab[y];
		tab[x] = aux2;
		tab[y] = aux1;
		x++;
		y--;
	}
}

/*int	main(void)
{
	int	tab[5] = { 1, 2, 3, 4, 5 };
	int	size = 5;
	int	a;

	a = 0;
	ft_rev_int_tab(tab, size);
	while (a <= size - 1)
	{	
		printf("%d", tab[a]);
		a++;
	}
}*/
