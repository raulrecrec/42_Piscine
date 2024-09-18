/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:59:09 by rexposit          #+#    #+#             */
/*   Updated: 2024/09/17 16:12:33 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (!((str[x] >= 'A' && str[x] <= 'Z')))
		{
			if ((!(str[x] >= 'a' && str[x] <= 'z')))
				return (0);
		}
		x++;
	}
	return (1);
}

/*int	main(void)
{
	int	a;
	char 	prueba1[] = "Á";
	char	prueba2[] = "g";
	char	prueba3[] = "1";
        char    prueba4[] = "ñ";

	a = ft_str_is_alpha(prueba1);
	printf("%d\n", a);
	a = ft_str_is_alpha(prueba2);
        printf("%d\n", a);
        a  = ft_str_is_alpha(prueba3);
        printf("%d\n", a);
        a  = ft_str_is_alpha(prueba4);
        printf("%d\n", a);
}*/
