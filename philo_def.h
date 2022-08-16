/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_def.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:46:58 by hejang            #+#    #+#             */
/*   Updated: 2022/08/16 21:11:49 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DEF_H
# define PHILO_DEF_H

#include "./philo.h"

typedef struct s_data
{
	struct	s_info		*info;
	struct  s_philo		**philo;
	pthread_mutex_t		*fork;
	pthread_mutex_t		time_mutex;
	pthread_mutex_t		flag_mutex;
	pthread_mutex_t		mu;
	pthread_mutex_t		start_line;
	int					end_flag;
	int					philo_full;
}	t_data;

typedef struct s_info
{
	long long	number_of_philo;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int			num_of_times_each_philo_must_eat;
	int			num_of_fork;
	int			cnt;
	long long	start_time;
}	t_info;

typedef	struct s_philo
{
	struct s_data	*data;
	pthread_t		*p_thread;
	int				philo_num;
	int				r_fork;
	int				l_fork;
	int				eat_cnt;
	long long 		eat_ms;
	long long		sleep_ms;
	long long		think_ms;
	long long		die_ms;
	long long		last_eat;
	int				death_flag;
}	t_philo;


enum e_state
{
	FORK = 2,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	FULL,
};

# define ERROR -1
# define FALSE	0
# define TRUE	1


#endif