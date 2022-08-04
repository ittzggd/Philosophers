/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:59:06 by hejang            #+#    #+#             */
/*   Updated: 2022/08/04 21:54:34 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./philo.h"


 void	philo_act(t_philo *philo, int state)
 {
	long long	start_time;
	long long	current_time;
	long long	diff;
	long long	time_to_wait;
	
	start_time = ft_time(philo);
	if(state == EATING)
		time_to_wait = philo->data->info->time_to_eat;
	else if(state == SLEEPING)
		time_to_wait = philo->data->info->time_to_sleep;
	// printf("%d's time to eat %lld\n", philo->philo_num, time_to_eat);
	diff = 0;
	while(time_to_wait >= diff)
	{
		
		current_time = ft_time(philo);
		diff = current_time - start_time;
		usleep(100);
	}
 }

void	wait_philo(t_data *data, int idx)
{

	while(1)
	{
		if(data->info->number_of_philo - 1  == idx)
		{
			printf("end condition!\n");
			usleep(10);
			break;
		}
	}
}

long long	ft_time(t_philo	*philo)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
//	printf("tv_sec : %u \n  tv_usec : %u \n", tv.tv_sec, tv.tv_usec);
	time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)); // tv_usec : microsec
//	printf("time : %u\n", time);
	return (time);
}

