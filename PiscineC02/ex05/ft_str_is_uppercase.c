/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:14:39 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/22 13:45:40 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if ((!(str[x] >= 'A' && str[x] <= 'Z')))
			return (0);
		x++;
	}
	return (1);
}

/*int     main(void)
{
        int     a;
        char    prueba1[] = "HOLA";
        char    prueba2[] = "hola123";
        char    prueba3[] = "";

        a = ft_str_is_uppercase(prueba1);
        printf("%d\n", a);
        a = ft_str_is_uppercase(prueba2);
        printf("%d\n", a);
        a  = ft_str_is_uppercase(prueba3);
        printf("%d\n", a);
}*/
