/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:36:38 by hejang            #+#    #+#             */
/*   Updated: 2022/08/02 15:37:42 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void		*ft_calloc(size_t number, size_t size);
int			ft_atoi(const char *str);
int			init(int argc, char **argv, t_data	*data);
void		wait_philo(t_data *data, int idx);
int			ft_isdigit(int c);
long long	ft_time(t_philo	*philo);