/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:40:28 by hejang            #+#    #+#             */
/*   Updated: 2022/07/29 01:29:09 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./philo.h"

int	create_philo(t_data *data)
{
	pthread_mutex_t	tmp;	
	int	i;
	int	thr_id;

	i = 0;
	if(!data)
		return (ERROR);

	pthread_mutex_init(&tmp, NULL);
	pthread_mutex_lock(&tmp);
	while(i < data->info->number_of_philo)
	{
		data->info->cnt = i;
		data->philo[i]->philo_num = i + 1;
//		printf("cnt : %d\n", data->info->cnt);
		printf("philo num = %d\n", data->philo[i]->philo_num);
		thr_id = pthread_create(data->philo[i]->p_thread, NULL, ft_philo, (void *)data);
		if(thr_id < 0)
		{
			printf("thread create error");
	//		return ;
		}
		usleep(10);
		i++;
	}
	pthread_mutex_unlock(&tmp);
	i = 0;
	while(i < data->info->number_of_philo)
	{
		pthread_join(*(data->philo[i]->p_thread), NULL);
		i++;
	}
	printf("end!\n");
}

void	*ft_philo(void *arg)
{
	t_data	*data;
	data = (t_data *)arg;

	pthread_mutex_lock(&data->mutex[data->info->cnt]);

	pthread_mutex_unlock(&data->mutex[data->info->cnt]);
	printf("cnt : %d\n", data->info->cnt);
	printf("unlock mutex \n");
}

