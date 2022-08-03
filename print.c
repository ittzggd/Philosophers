/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:59:33 by hejang            #+#    #+#             */
/*   Updated: 2022/08/01 18:28:12 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include "./philo.h"

 void	ft_print(t_philo *philo, int state, int ms)
 {

	if(state == FORK)
		printf("[philo%d] has taken a fork\n",philo->philo_num);
	else if(state == EATING)
		printf("[philo%d] is eating\n", philo->philo_num);
	else if(state == SLEEPING)
		printf("[philo%d] is sleeping\n",philo->philo_num);
	else if(state == THINKING)
		printf("[philo%d] is thinking\n", philo->philo_num);
	else if(state == DIED)
		printf("[philo%d] is died\n", philo->philo_num);
 }