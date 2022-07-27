/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:30:24 by hejang            #+#    #+#             */
/*   Updated: 2022/07/27 17:57:08 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include "./philo.h"

 int main(int argc, char **argv)
 {
	t_data	*data;
	
	if(argc >= 5)
	{
		data = ft_calloc(1, sizeof(t_data));
		if(init_t_info(argv) == ERROR)
			return (ERROR);
		if(data->info->number_of_philo == 1)
			one_philo(data);
		

	}
 }