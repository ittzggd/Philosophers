/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:52:29 by hejang            #+#    #+#             */
/*   Updated: 2022/08/17 20:29:34 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

long long	ft_time(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (time);
}

long long	ft_print(t_philo *philo, int state)
{
	long long	to_time;
	long long	timestamp;
	long long	current_time;

	if (philo->data->end_flag == TRUE)
		return (FALSE);
	pthread_mutex_lock(&(philo->data->time_mutex));
	if (philo->data->end_flag == TRUE)
	{
		pthread_mutex_unlock(&(philo->data->time_mutex));
		return (FALSE);
	}
	current_time = ft_time();
	timestamp = current_time - philo->data->info.start_time;
	if (state == FORK)
		printf("%lld\t[philo%d] has taken a fork\n", timestamp, philo->philo_num);
	else if (state == EATING)
		printf("%lld\t[philo%d] is eating\n", timestamp, philo->philo_num);
	else if (state == SLEEPING)
		printf("%lld\t[philo%d] is sleeping\n", timestamp, philo->philo_num);
	else if (state == THINKING)
		printf("%lld\t[philo%d] is thinking\n", timestamp, philo->philo_num);
	else if (state == DIED)
		printf("%lld\t[philo%d] is died\n", timestamp, philo->philo_num);
	pthread_mutex_unlock(&(philo->data->time_mutex));
	return (current_time);
}