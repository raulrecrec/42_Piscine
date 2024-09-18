/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:00:30 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/27 14:25:36 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	x;
	unsigned int	leng_dest;
	unsigned int	leng_src;

	x = 0;
	leng_dest = 0;
	leng_src = 0;
	while (dest[leng_dest] != '\0' && leng_dest < size)
		leng_dest++;
	while (src[leng_src] != '\0')
		leng_src++;
	if (size <= leng_dest)
		return (size + leng_src);
	while (src[x] != '\0' && leng_dest + x < size - 1)
	{
		dest[leng_dest + x] = src[x];
		x++;
	}
	if ((leng_dest + x) < size)
		dest[leng_dest + x] = '\0';
	return (leng_dest + leng_src);
}

/*int 	main(void) 
{
    char dest[20] = "Hola, ";
    char *src = "Mundo!";
    unsigned int size = 20;

    unsigned int result = ft_strlcat(dest, src, size);

    printf("Resultado: %s\n", dest);
    printf("Longitud total: %u\n", result);
}*/
