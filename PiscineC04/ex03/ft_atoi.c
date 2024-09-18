/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:42:12 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/29 18:03:50 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(char *str)
{
	int	res;
	int	sig;

	res = 0;
	sig = 1;
	while (space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sig = -sig;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sig * res);
}

/*int main() 
{
    char str[] = " ---+--+1234ab567";
    printf("%d\n", ft_atoi(str));
    return 0;
}*/
