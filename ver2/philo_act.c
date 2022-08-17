/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:32:24 by hejang            #+#    #+#             */
/*   Updated: 2022/08/17 20:28:10 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	philo_act(t_philo *philo, int state, long long start_time)
{
	long long	current_time;
	long long	diff;
	long long	time_to_wait;

	if (state == EATING)
		time_to_wait = philo->data->info.time_to_eat;
	else if (state == SLEEPING)
		time_to_wait = philo->data->info.time_to_sleep;
	diff = 0;
	while (time_to_wait > diff)
	{
		current_time = ft_time();
		diff = current_time - start_time;
		usleep(100);
	}
}