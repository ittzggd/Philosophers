/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_def.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:46:58 by hejang            #+#    #+#             */
/*   Updated: 2022/08/03 16:12:02 by hejang           ###   ########.fr       */
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
}	t_data;

typedef struct s_info
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_each_philo_must_eat;
	int	num_of_fork;
	int	cnt;
}	t_info;

typedef	struct s_philo
{
	struct s_data	*data;
	pthread_t		*p_thread;
	int				philo_num;
	int				r_fork;
	int				l_fork;
	int				eat_cnt;
	long long 		eating_ms;
	long long		sleeping_ms;
	long long		thinking_ms;
	long long		died_ms;
}	t_philo;


enum e_state
{
	FORK = 2,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
};

# define ERROR -1
# define FALSE	0
# define TRUE	1


#endif