/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:37:59 by hejang            #+#    #+#             */
/*   Updated: 2022/08/04 21:56:17 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include "./philo.h"

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
	philo->eat_cnt++;
	pthread_mutex_unlock(&(fork[philo->l_fork]));
	pthread_mutex_unlock(&(fork[philo->r_fork]));
	return (TRUE);
 }
