/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:00:16 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/27 12:58:45 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	x;
	int	y;

	x = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[x] != '\0')
	{
		y = 0;
		while (str[x + y] == to_find[y] && to_find[y] != '\0')
			y++;
		if (to_find[y] == '\0')
			return (str + x);
		x++;
	}
	return ((char *) 0);
}

/*int main() {
    char str[] = "Hola mundo";
    char *to_find = "mundo";

    printf("%s\n", ft_strstr(str, to_find));
}*/
