/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:46:29 by hejang            #+#    #+#             */
/*   Updated: 2022/08/17 20:33:27 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	create_philo(t_data *data)
{
	int	i;
	int	thr_id;

	i = 0;
	pthread_mutex_lock(&(data->start_line));
	while (i < data->info.number_of_philo)
	{
		data->philo[i].philo_num = i + 1;
		data->info.cnt = i;
		thr_id = pthread_create(data->philo[i].p_thread, NULL, ft_philo, (void *)(&(data->philo[i])));
		if (thr_id < 0)
		{
			printf("thread create error");
			return (ERROR);
		}
		usleep(100);
		i++;
	}
	data->info.start_time = ft_time();
	pthread_mutex_unlock(&(data->start_line));
	monitor(data);
	i = 0;
	while (i < data->info.number_of_philo)
	{
		pthread_join(*(data->philo[i].p_thread), NULL);
		i++;
	}
	return (TRUE);
}

void	monitor(t_data *data)
{
	int	i;

	while (data->end_flag != TRUE)
	{
		i = 0;
		if (check_full(data) == TRUE)
			return ;
		while (i < data->info.number_of_philo)
		{
			if (check_die(&(data->philo[i]), data) == DIED)
				return ;
			i++;
		}
		usleep(200);
	}
}

int	check_die(t_philo *philo, t_data *data)
{
	long long	current_time;
	long long	time_to_die;
	long long	last_eat;
	long long	diff;

	current_time = ft_time();
	time_to_die = data->info.time_to_die;
	last_eat = philo->last_eat;
	diff = current_time - last_eat;
	if (diff > time_to_die)
	{
		pthread_mutex_lock(&(data->flag_mutex));
		ft_print(philo, DIED);
		data->end_flag = TRUE;
		pthread_mutex_unlock(&(data->flag_mutex));
		return (DIED);
	}
	return (FALSE);
}

int	check_full(t_data *data)
{
	int	must_eat;

	must_eat = data->info.num_of_times_each_philo_must_eat;
	if (data->philo_full == must_eat)
		return (TRUE);
	else
		return (FALSE);
}
