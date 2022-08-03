/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:21:15 by hejang            #+#    #+#             */
/*   Updated: 2022/08/03 16:36:55 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include "./philo.h"

 void	destroy_fork_mutex(t_data *data)
 {
	int		i;
	t_philo	**philo;

	philo = data->philo;
	while(i < data->info->number_of_philo - 1)
	{
		pthread_mutex_destroy(&(philo[i]->l_fork));
		i++;
	}
	pthread_mutex_destroy(&(data->time_mutex));
 }