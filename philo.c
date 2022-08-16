/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:40:28 by hejang            #+#    #+#             */
/*   Updated: 2022/08/16 20:20:30 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./philo.h"

void	wait_create_thread(t_philo *philo);
void	philo_think(t_philo *philo);
int	ft_check_philo(t_data *data);
int	check_die(t_philo *philo);
int	check_full(t_data *data);

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
		usleep(100);
		i++;
	}
	pthread_mutex_unlock(&tmp);
	i = 0;
	while(data->end_flag != TRUE)
	{
		if(ft_check_philo(data) == DIED || ft_check_philo(data) == FULL)
			break;
	}
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
		usleep(200);
	pthread_mutex_lock(&(philo->data->time_mutex));
	philo->data->info->start_time = ft_time();
	pthread_mutex_unlock(&(philo->data->time_mutex));
	while(philo->data->end_flag != TRUE)
	{
		if(philo_eat(philo) == TRUE && philo->data->end_flag != TRUE) 
		{
			philo_sleep(philo);
			philo_think(philo);
		}
	}
}


int	ft_check_philo(t_data *data)
{
	int	i;
	t_info	*info;
	
	i = 0;
	info = data->info;
	while(i < data->info->number_of_philo)
	{
		if(check_die(data->philo[i]) == TRUE)
		{
			data->end_flag = TRUE;
			return (DIED);
		}
		else if(check_full(data) == TRUE)
		{
			data->end_flag = TRUE;
			return (FULL);
		}
		i++;
	}
	return (TRUE);
}

int	check_full(t_data *data)
{
	t_info	*info;

	info = data->info;
	if(data->philo_full == info->num_of_times_each_philo_must_eat)
		return (TRUE);
	else
		return(FALSE);
}

int	check_die(t_philo *philo)
{
	long long	current_time;
	long long	time_to_die;
	long long	last_eat;
	long long	diff;

	current_time = ft_time();
	time_to_die = philo->data->info->time_to_die;
	last_eat = philo->last_eat;
	diff = current_time - last_eat;
	if(diff >= time_to_die)
	{
		pthread_mutex_lock(&(philo->data->flag_mutex));
		ft_print(philo, DIED);
		pthread_mutex_unlock(&(philo->data->flag_mutex));
		return (TRUE);
	}
}