/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:40:28 by hejang            #+#    #+#             */
/*   Updated: 2022/07/28 19:58:35 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./philo.h"

int	create_philo(t_data *data)
{
	int	i;
	int	thr_id;

	i = 0;
	if(!data)
		return (ERROR);

	while(i < data->info->number_of_philo)
	{
		data->info->cnt = i;
		data->philo[i]->philo_num = i + 1;
//		printf("cnt : %d\n", data->info->cnt);
		printf("philo num = %d\n", data->philo[i]->philo_num);
		thr_id = pthread_create(data->philo[i]->p_thread, NULL, philo, (void *)data);
		if(thr_id < 0)
		{
			printf("thread create error");
//			return ;
		}
		usleep(10);
		i++;
	}
	i = 0;
	while(i < data->info->number_of_philo)
	{
		pthread_join(*(data->philo[i]->p_thread), NULL);
		i++;
	}
	printf("end!\n");
}

void	*philo(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;

	pthread_mutex_lock(&data->mutex[data->info->cnt]);

	printf("cnt : %d\n", data->info->cnt);
//	wait_philo(data, data->info->cnt);
	
	pthread_mutex_unlock(&data->mutex[data->info->cnt]);

	
}

