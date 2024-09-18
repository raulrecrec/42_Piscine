/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:13:25 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/20 12:07:22 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	rest;

	div = *a / *b;
	rest = *a % *b;
	*a = div;
	*b = rest;
}

/*int	main(void)
{
	int	a;
	int	b;

	a = 10;
	b = 3;

	ft_ultimate_div_mod(&a, &b);

	printf("El valor de *a es: %d\n", a);
	printf("El valor de *b es: %d\n", b);
}*/
