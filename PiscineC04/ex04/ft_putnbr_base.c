/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:17:50 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/29 17:11:23 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_valid(char *base)
{
	int	x;
	int	y;

	x = 0;
	while (base[x] != '\0')
	{
		if (base[x] == '+' || base[x] == '-' || base[x] < ' ' || base[x] > '~')
			return (0);
		y = x + 1;
		while (base[y] != '\0')
		{
			if (base[x] == base[y])
				return (0);
			y++;
		}
		x++;
	}
	return (x > 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		leng_base;
	long	c;
	char	aux;

	c = nbr;
	if (!base_valid(base))
		return ;
	leng_base = 0;
	while (base[leng_base] != '\0')
		leng_base++;
	if (c < 0)
	{
		write(1, "-", 1);
		c = -c;
	}
	if (c >= leng_base)
		ft_putnbr_base(c / leng_base, base);
	aux = base[c % leng_base];
	write(1, &aux, 1);
}

/*int	main(void)
{
	int	nbr = -21474883648;
	char	base[] = "0123456789ABCDEF";
	
	ft_putnbr_base(nbr, base);
}*/	
