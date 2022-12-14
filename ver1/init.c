/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:33:49 by hejang            #+#    #+#             */
/*   Updated: 2022/08/16 20:31:33 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include "./philo.h"
 # include "./utils.h"

 static int	init_philo(t_data *data);
 static t_info	*init_t_info(int argc, char **argv);
 static int	init_mutex(t_data *data);

 int	init(int argc, char **argv, t_data	*data)
 {
	data->info = init_t_info(argc, argv);
	if(data->info == NULL)
		return (ERROR);
	if(init_philo(data) == ERROR)
		return (ERROR);
	init_mutex(data);
	return (TRUE);
 }

static int	init_philo(t_data *data)
{
	t_info	*info;
	int		i;
	int		num;

	if(!data)
		return (ERROR);
	i = 0;
	info = data->info;
	num = data->info->number_of_philo;
	data->philo_full = 0;
	data->philo = ft_calloc(info->number_of_philo, sizeof(t_philo *));
	if(!data->philo)
		return (ERROR);
	while(i < data->info->number_of_philo)
	{
		data->philo[i] = ft_calloc(1, sizeof(t_philo));
		data->philo[i]->p_thread = ft_calloc(1, sizeof(pthread_t));
		if(!data->philo[i]->p_thread)
			return (ERROR);
		data->philo[i]->philo_num = i + 1;
		data->philo[i]->l_fork = i;
		data->philo[i]->r_fork = (i + 1) % num;
		data->philo[i]->data = data;
		data->philo[i]->death_flag = FALSE;
		data->philo[i]->last_eat = ft_time();
		i++;
}
	return (TRUE);
}

 t_info	*init_t_info(int argc, char **argv)
 {
	t_info	*info;

	info = ft_calloc(sizeof(t_info), 1);
	if(!info)
		return (NULL);
	info->number_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->cnt = 0;
	if(argc == 6)
		info->num_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		info->num_of_times_each_philo_must_eat = -99999;
	if(info->number_of_philo <= 0 || info->time_to_die < 0
		|| info->time_to_eat < 0 || info->time_to_sleep < 0)
	{
		printf("[philo] : number && time > 0");
		return (NULL);
	}
	info->num_of_fork = info->number_of_philo;
	return (info);
 }

static int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->fork = ft_calloc(data->info->number_of_philo, sizeof(pthread_mutex_t));
	if(!data->fork)
		return (ERROR);
	while(i < data->info->number_of_philo)
	{
		if(pthread_mutex_init(&(data->fork[i]), NULL))
			return (ERROR);
		i++;
	}
	pthread_mutex_init(&data->time_mutex, NULL);
	pthread_mutex_init(&data->flag_mutex, NULL);
	pthread_mutex_init(&data->mu, NULL);
	return (TRUE);
}
