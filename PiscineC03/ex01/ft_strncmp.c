/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:29:49 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/27 17:54:17 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	x;

	x = 0;
	if (n == 0)
		return (0);
	while (s1[x] == s2[x] && s1[x] != '\0' && s2[x] != '\0' && x < n)
		x++;
	if (x == n)
		return (0);
	return (s1[x] - s2[x]);
}

/*int	main(void)
{
	char s1[] = "Hel";
	char s2[] = "Hello";

	printf("%d", ft_strncmp(s1, s2, 5));
}*/
