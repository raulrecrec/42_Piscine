/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:18:13 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/23 13:43:21 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (src[y] != '\0')
		y++;
	if (size > 0)
	{
		while (src[x] != '\0' && x < size - 1)
		{
			dest[x] = src[x];
			x++;
		}
		dest[x] = '\0';
	}
	return (y);
}

/*int 	main(void) 
{
	char src[] = "es una prueba";
	char dest[20] = "Esto";
	unsigned int x;

	x = ft_strlcpy(dest, src, 20);
	printf("Destino: %s\n", dest);
	printf("Longitud: %d\n", x);
}*/
