/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:35:02 by hejang            #+#    #+#             */
/*   Updated: 2022/07/21 17:48:04 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include "./philo.h"

 void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(number * size);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, (number * size));
	return (ptr);
}

int	ft_atoi(const char *str)
{
	long long int	n;
	int	negative;

	n = 0;
	negative = 1;
	if (*str == '-')
		negative = negative * (-1);
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (ERROR);
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		n = (n * 10) + (*str - '0');
		str++;
	}
	if ((n * negative) > INT_MAX)
		return (ERROR);
	else if ((n * negative) < INT_MIN)
		return (ERROR);
	if ((*str <= '0' || *str >= '9') && *str != '\0')
		return (ERROR);
	return ((n * negative));
}