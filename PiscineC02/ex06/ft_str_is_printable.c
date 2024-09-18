/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:32:21 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/22 13:49:56 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if ((!(str[x] >= ' ' && str[x] <= '~')))
			return (0);
		x++;
	}
	return (1);
}

/*int     main(void)
{
        int     a;
        char    prueba1[] = "Hola";
        char    prueba2[] = "holaÇ";
        char    prueba3[] = "";

        a = ft_str_is_printable(prueba1);
        printf("%d\n", a);
        a = ft_str_is_printable(prueba2);
        printf("%d\n", a);
        a = ft_str_is_printable(prueba3);
        printf("%d\n", a);
}*/
