/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:13:03 by vpoka             #+#    #+#             */
/*   Updated: 2025/02/18 20:24:20 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Converts a string to an integer.
 *
 * This function takes a string `nptr` and converts it to an integer.
 *
 * @param nptr The string to be converted.
 * @return The converted integer value.
 */
int	mod_atoi(const char *nptr)
{
	long int		result;
	long int		max;
	int				sign;

	sign = 1;
	max = 2147483648;
	result = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (ft_isdigit(*nptr) && result <= max)
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	if ((result > max) || (result > max - 1 && sign > 0))
		return (0);
	return (sign * result);
}

/* #include <stdio.h>
int	main(void)
{
	char *n = "   2147483649";
	printf("%d\n", mod_atoi(n));
} */
