/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:55:31 by hejang            #+#    #+#             */
/*   Updated: 2022/08/17 20:46:38 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

 void	philo_act(t_philo *philo, int state)
 {
	long long	start_time;
	long long	current_time;
	long long	diff;
	long long	time_to_wait;
	
	start_time = ft_time();
	if(state == EATING)
		time_to_wait = philo->data->info->time_to_eat;
	else if(state == SLEEPING)
		time_to_wait = philo->data->info->time_to_sleep;
	diff = 0;
	usleep(time_to_wait * 800);
	while(time_to_wait > diff)
	{
		current_time = ft_time();
		diff = current_time - start_time;
		usleep(300);
	}
 }

int	philo_eat(t_philo *philo)
 {
	t_info			*info;
	pthread_mutex_t	*fork;

	info = philo->data->info;
	fork = philo->data->fork;
	
	if(pthread_mutex_lock(&(fork[philo->l_fork])) == 0)
	{
		ft_print(philo, FORK);
		if(pthread_mutex_lock(&(fork[philo->r_fork])) == 0)
		{
			ft_print(philo, FORK);
			ft_print(philo, EATING);
			philo_act(philo, EATING);
		}
	}
	philo->last_eat = ft_time();
	philo->eat_cnt++;
	if(philo->eat_cnt == info->num_of_times_each_philo_must_eat)
		philo->data->philo_full++;
	pthread_mutex_unlock(&(fork[philo->l_fork]));
//	printf("[philo %d] left fork is down\n", philo->philo_num);
	pthread_mutex_unlock(&(fork[philo->r_fork]));
//	printf("[philo %d] right fork is down\n", philo->philo_num);
	
	return (TRUE);
 }

int	philo_sleep(t_philo	*philo)
{
	pthread_mutex_lock(&(philo->data->flag_mutex));
	ft_print(philo, SLEEPING);
	pthread_mutex_unlock(&(philo->data->flag_mutex));
	philo_act(philo, SLEEPING);
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->flag_mutex));
	ft_print(philo, THINKING);
	pthread_mutex_unlock(&(philo->data->flag_mutex));
}