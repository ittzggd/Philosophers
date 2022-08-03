/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:37:59 by hejang            #+#    #+#             */
/*   Updated: 2022/08/03 16:20:28 by hejang           ###   ########.fr       */
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
		printf("philo[%d]->left fork : %d \n", philo->philo_num, philo->l_fork);
	if(pthread_mutex_lock(&(fork[philo->r_fork])) == 0)
		printf("philo[%d]->right fork : %d \n",philo->philo_num,  philo->r_fork);
	ft_print(philo, FORK, 0);
	philo->eat_cnt++;
	//pthread_mutex_unlock(&(fork[philo->l_fork]));
	//pthread_mutex_unlock(&(fork[philo->r_fork])
	return (TRUE);
 }
