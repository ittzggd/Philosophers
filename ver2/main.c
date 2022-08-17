/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:10:53 by hejang            #+#    #+#             */
/*   Updated: 2022/08/17 15:58:20 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 5 || argc == 6)
	{
		data = ft_calloc(1, sizeof(t_data));
		init(argc, argv, data);
		create_philo(data);
	}
	else
	{
		printf(" ./philo number_of_philo time_to_die time_to_eat");
		printf(" time_to_sleep number_of_times_each_philo_must_eat\n");
	}
}