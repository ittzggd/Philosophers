/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:47:24 by hejang            #+#    #+#             */
/*   Updated: 2022/08/04 21:56:54 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./philo.h"

int	philo_sleep(t_philo	*philo)
{
	ft_print(philo, SLEEPING);
	philo_act(philo, SLEEPING);
}