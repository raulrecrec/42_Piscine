/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:48:43 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/24 18:55:03 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		x;
	char	*hex;
	char	aux;

	hex = "0123456789abcdef";
	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] < ' ' || str[x] > '~')
		{
			write(1, "\\", 1);
			aux = hex[(unsigned char)str[x] / 16];
			write(1, &aux, 1);
			aux = hex[(unsigned char)str[x] % 16];
			write(1, &aux, 1);
		}
		else
			write(1, &str[x], 1);
		x++;
	}
}

/*int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
}*/
