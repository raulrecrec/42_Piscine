/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:28:49 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/25 13:07:16 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] >= 'A' && str[x] <= 'Z')
			str[x] = str[x] + 32;
		x++;
	}
	return (str);
}

/*int     main(void)
{
        char    prueba1[] = "HOLA";
        char    prueba2[] = "hoLa";

        ft_strlowcase(prueba1);
        printf("%s\n", prueba1);
        ft_strlowcase(prueba2);
        printf("%s\n", prueba2);
}*/
