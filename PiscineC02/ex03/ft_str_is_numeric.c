/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:47:19 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/21 21:07:02 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (!(str[x] >= '0' && str[x] <= '9'))
		{
			return (0);
		}
		x++;
	}
	return (1);
}

int	main(void)
{
	int	a;
	char 	prueba1[] = "A";
	char	prueba2[] = "1";
	char	prueba3[] = "!";

	a = ft_str_is_numeric(prueba1);
	printf("%d\n", a);
	a = ft_str_is_numeric(prueba2);
        printf("%d\n", a);
        a  = ft_str_is_numeric(prueba3);
        printf("%d\n", a);
}
