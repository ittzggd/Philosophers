/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:40:28 by hejang            #+#    #+#             */
/*   Updated: 2022/08/04 21:55:47 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./philo.h"

void	wait_create_thread(t_philo *philo);


void	wait_create_thread(t_philo *philo)
{
	printf("hi! philo[%d] start to wait! \n", philo->philo_num);
	while (1)
	{
		if (philo->data->info->cnt == philo->data->info->number_of_philo-1)
		{
		//	philo->start_ms = base->timestamp_start_ms;
			usleep(100);
			break ;
		}
		else
		{
		//	printf("philo[%d] is still waiting!\n");
			usleep(100);
		}
	}
	printf("philo[%d] waiting over!\n", philo->philo_num);
}
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
//		printf("%d\n", i);
		data->info->cnt = i;
		data->philo[i]->philo_num = i + 1;
	//	printf("philo num = %d\n", data->philo[i]->philo_num);
		thr_id = pthread_create(data->philo[i]->p_thread, NULL, ft_philo, (void *)(data->philo[i]));
		if(thr_id < 0)
			printf("thread create error");
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
	t_philo			*philo;
	t_info			*info;
	pthread_mutex_t *fork;
	
	philo = (t_philo *)arg;
	fork = philo->data->fork;
	info = philo->data->info;
	if(philo->philo_num % 2 == 0)
		usleep(100);
	pthread_mutex_lock(&(philo->data->time_mutex));
	philo->data->info->start_time = ft_time(philo);
	pthread_mutex_unlock(&(philo->data->time_mutex));
//	wait_create_thread(philo);
	if(philo_eat(philo) == TRUE)
	{
		philo_sleep(philo);
	 	// pthread_mutex_unlock(&(fork[philo->l_fork]));
		// pthread_mutex_unlock(&fork[philo->r_fork]);
	}
}