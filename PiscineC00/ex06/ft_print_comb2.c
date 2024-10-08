/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:56:43 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/12 16:26:21 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			write(1, &((char){a / 10 + '0'}), 1);
			write(1, &((char){a % 10 + '0'}), 1);
			write(1, " ", 1);
			write(1, &((char){b / 10 + '0'}), 1);
			write(1, &((char){b % 10 + '0'}), 1);
			if (a != 98 || b != 99)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
