/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:59:33 by hejang            #+#    #+#             */
/*   Updated: 2022/08/04 21:40:41 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include "./philo.h"

 void	ft_print(t_philo *philo, int state)
 {
	long long	to_time;
	long long	timestamp;

	pthread_mutex_lock(&(philo->data->time_mutex));
	to_time = ft_time(philo);
	timestamp = to_time - philo->data->info->start_time;
	// printf("//%d, time : %lld//\n", philo->philo_num, timestamp);
	if(state == FORK)
		printf("%lld\t[philo%d] has taken a fork\n",timestamp, philo->philo_num);
	else if(state == EATING)
		printf("%lld\t[philo%d] is eating\n", timestamp, philo->philo_num);
	else if(state == SLEEPING)
		printf("%lld\t[philo%d] is sleeping\n", timestamp, philo->philo_num);
	else if(state == THINKING)
		printf("%lld\t[philo%d] is thinking\n", timestamp, philo->philo_num);
	else if(state == DIED)
		printf("%lld\t[philo%d] is died\n", timestamp, philo->philo_num);
 	pthread_mutex_unlock(&(philo->data->time_mutex));
 }