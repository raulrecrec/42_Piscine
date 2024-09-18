/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:33:16 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/26 17:44:25 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] >= 'A' && str[x] <= 'Z')
			str[x] = str[x] + 32;
		x++;
	}
	x = 0;
	while (str[x] != '\0')
	{
		if ((str[x] < 'A' && (str[x] > '9' || str[x] < '0'))
			|| (str[x] > 'Z' && str[x] < 'a') || str[x] > 'z')
		{
			if (str[x + 1] >= 'a' && str[x + 1] <= 'z')
				str[x + 1] = str[x + 1] - 32;
		}
		x++;
	}
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	return (str);
}

/*int     main(void)
{
        char    prueba1[] = "salut, comment tu vas ? 42mots 
        quarante-deux; cinquante+et+un";
        ft_strcapitalize(prueba1);
        printf("%s\n", prueba1);
}*/
