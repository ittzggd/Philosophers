/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:59:06 by hejang            #+#    #+#             */
/*   Updated: 2022/07/28 23:13:07 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./philo.h"

void	wait_philo(t_data *data, int idx)
{

	while(1)
	{
		if(data->info->number_of_philo - 1  == idx)
		{
			printf("end condition!\n");
			usleep(10);
			break;
		}
	}
}