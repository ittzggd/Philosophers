/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:20:48 by hejang            #+#    #+#             */
/*   Updated: 2022/08/14 00:58:02 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>
# include <memory.h>
# include <sys/time.h>
# include "./philo_def.h"
# include "./utils.h"

int		create_philo(t_data *data);
void	*ft_philo(void *arg);
int		philo_eat(t_philo *philo);
int		philo_sleep(t_philo	*philo);
void	ft_print(t_philo *philo, int state);
void	one_philo(t_philo *philo);
void	destroy_fork_mutex(t_data *data);
void	philo_act(t_philo *philo, int state);
void	free_philo(t_data *data);
#endif