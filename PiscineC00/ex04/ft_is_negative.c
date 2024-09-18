/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:04:19 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/14 17:21:52 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	negative_char;
	char	positive_char;

	negative_char = 'N';
	positive_char = 'P';
	if (n < 0)
	{
		write(1, &negative_char, 1);
	}
	else
	{
		write(1, &positive_char, 1);
	}
}
