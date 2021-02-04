/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:34:22 by fadelia           #+#    #+#             */
/*   Updated: 2021/02/03 17:48:44 by fadelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	flag_ord(int *tab, int length)
{
	int i;

	i = 0;
	while ((tab[i] == tab[i + 1]) && (i < length - 1))
	{
		i++;
	}
	if (tab[i] > tab[i + 1])
		return (-1);
	else if (tab[i] < tab[i + 1])
		return (1);
	else
		return (0);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int (*func)(int, int);
	int flag;
	int flag_o;

	flag_o = flag_ord(tab, length);
	if (flag_o == 0)
		return (1);
	i = 0;
	func = f;
	while (i < (length - 1))
	{
		flag = (*func)(tab[i], tab[i + 1]);
		if ((flag_o == 1 && flag > 0) || (flag_o == -1 && flag < 0))
			return (0);
		else
			i++;
	}
	return (1);
}
