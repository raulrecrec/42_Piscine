/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:43:04 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/25 13:05:29 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] >= 'a' && str[x] <= 'z')
			str[x] = str[x] - 32;
		x++;
	}
	return (str);
}

/*int     main(void)
{
        char    prueba1[] = "Hola";
        char    prueba2[] = "hola";
        char    prueba3[] = "";

        ft_strupcase(prueba1);
        printf("%s\n", prueba1);
        ft_strupcase(prueba2);
        printf("%s\n", prueba2);
        ft_strupcase(prueba3);
        printf("%s\n", prueba3);
}*/
