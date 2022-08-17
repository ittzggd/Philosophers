/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:42:19 by hejang            #+#    #+#             */
/*   Updated: 2022/08/17 20:31:58 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*ft_philo(void *arg)
{
	t_philo		*philo;
	t_data		*data;
	t_info		info;

	philo = (t_philo *)arg;
	data = philo->data;
	info = data->info;
	pthread_mutex_lock(&(data->start_line));
	pthread_mutex_unlock(&(data->start_line));
	// wait_philo(data, philo);
	if (philo->philo_num % 2 == 0)
		usleep(200);
	while (data->end_flag != TRUE)
	{
		if (philo_eat(philo, data) != TRUE)
			break ;
		if (philo_sleep(philo, data) != TRUE)
			break ;
		if (philo_think(philo, data) != TRUE)
			break ;
		usleep(100);
	}
}

int	philo_eat(t_philo *philo, t_data *data)
{
	t_info			info;
	long long		time;
	pthread_mutex_t	*fork;

	fork = data->fork;
	info = data->info;
	if (pthread_mutex_lock(&(fork[philo->l_fork])) == 0)
	{
		ft_print(philo, FORK);
		if (pthread_mutex_lock(&(fork[philo->r_fork])) == 0)
		{
			ft_print(philo, FORK);
//			pthread_mutex_lock(&(philo->data->flag_mutex));
			time = ft_print(philo, EATING);
//			pthread_mutex_unlock(&(philo->data->flag_mutex));
			philo_act(philo, EATING, time);
		}
	}
	philo->eat_cnt++;
	if (philo->eat_cnt == info.num_of_times_each_philo_must_eat)
		data->philo_full++;
	pthread_mutex_unlock(&(fork[philo->l_fork]));
	pthread_mutex_unlock(&(fork[philo->r_fork]));
	philo->last_eat = ft_time();
	if (data->end_flag == TRUE)
		return (DIED);
	return (TRUE);
}

int	philo_sleep(t_philo	*philo, t_data *data)
{
	long long	time;

//	pthread_mutex_lock(&(philo->data->flag_mutex));
//	pthread_mutex_unlock(&(philo->data->flag_mutex));
	time = ft_print(philo, SLEEPING);
	philo_act(philo, SLEEPING, time);
	if (data->end_flag == TRUE)
		return (DIED);
	return (TRUE);
}

int	philo_think(t_philo *philo, t_data *data)
{
//	pthread_mutex_lock(&(philo->data->flag_mutex));
//	pthread_mutex_unlock(&(philo->data->flag_mutex));
	ft_print(philo, THINKING);
	if (data->end_flag == TRUE)
		return (DIED);
	return (TRUE);
}
