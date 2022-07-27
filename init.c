/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:33:49 by hejang            #+#    #+#             */
/*   Updated: 2022/07/27 17:43:36 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include "./philo.h"
 # include "./utils.h"

 static int	init_philo(t_data *data);
 static t_info	*init_t_info(int argc, char **argv);

 int	init(int argc, char **argv, t_data	*data)
 {
	data->info = init_t_info(argc, argv);
	if(data->info == NULL)
		return (ERROR);
	if(init_philo(data) == ERROR)
		return (ERROR);
 }

static int	init_philo(t_data *data)
{
	t_info	*info;
	int		i;

	if(!data)
		return (ERROR);
	i = 0;
	info = data->info;
	data->philo = ft_calloc(info->number_of_philo, sizeof(t_philo));
	if(!data->philo)
		return (ERROR);
	while(i < data->info->number_of_philo)
	{
		data->philo[i]->p_thread = ft_calloc(1, sizeof(pthread_t));
		if(!data->philo[i]->p_thread)
			return (ERROR);
		i++;
	}

}

 static t_info	*init_t_info(int argc, char **argv)
 {
	t_info	*info;

	info = ft_calloc(sizeof(t_info), 1);
	if(!info)
		return (NULL);
	info->number_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if(argc == 6)
		info->num_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		info->num_of_times_each_philo_must_eat = NULL;
	if(info->number_of_philo <= 0 || info->time_to_die < 0
		|| info->time_to_eat < 0 || info->time_to_sleep < 0)
	{
		printf("[philo] : number && time > 0");
		return (NULL);
	}
	info->num_of_fork = info->number_of_philo;
 }
