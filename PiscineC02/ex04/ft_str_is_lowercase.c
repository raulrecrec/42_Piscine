/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:07:34 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/22 13:50:53 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if ((!(str[x] >= 'a' && str[x] <= 'z')))
			return (0);
		x++;
	}
	return (1);
}

/*int	main(void)
{
	int	a;
	char 	prueba1[] = "hola";
	char	prueba2[] = "hola123";
	char	prueba3[] = "";

	a = ft_str_is_lowercase(prueba1);
	printf("%d\n", a);
	a = ft_str_is_lowercase(prueba2);
        printf("%d\n", a);
        a  = ft_str_is_lowercase(prueba3);
        printf("%d\n", a);
}*/
