/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:44:16 by hejang            #+#    #+#             */
/*   Updated: 2022/08/17 19:59:25 by hejang           ###   ########.fr       */
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

int			create_philo(t_data *data);
void		*ft_philo(void *arg);
int			philo_eat(t_philo *philo, t_data *data);
int			philo_sleep(t_philo	*philo, t_data *data);
int			philo_think(t_philo *philo, t_data *data);
long long	ft_print(t_philo *philo, int state);
void		one_philo(t_philo *philo);
void		destroy_fork_mutex(t_data *data);
void		philo_act(t_philo *philo, int state, long long start_time);
void		free_philo(t_data *data);
void		monitor(t_data *data);
int			check_die(t_philo *philo, t_data *data);
int			check_full(t_data *data);
void		monitor(t_data *data);

void		*ft_calloc(size_t number, size_t size);
int			ft_atoi(const char *str);
int			init(int argc, char **argv, t_data	*data);
void		wait_philo(t_data *data, t_philo *philo);
int			ft_isdigit(int c);
long long	ft_time(void);



#endif