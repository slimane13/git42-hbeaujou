/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 18:11:48 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/02 19:30:09 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void resolve_test(int *l_a, int *l_b, int max, int nbr)
{
	int tab[10]; // 0 = ra - 1 = rra - 2 = rb - 3 = rrb - 4 = sa - 5 = sb 6 = ss 7 = rr - 8 = rrr
	int ret;
	int min;
	int count;
	int p;

	ret = 0;
	p = 0;
	min = 0;
	count = 0;
	while (!ft_is_valid(l_a) || !ft_is_unvalid(l_b))
	{
		min = find_min(l_a);
		p = find_min_iter(l_a);
		while (count < (nbr / 2) - 1)
		{
			while (l_a[0] != min)
			{
				min = find_min(l_a);
				p = find_min_iter(l_a);
				if (p < (nbr - 2) / 2) 
				{
					printf("RA ");
					RA;
				}
				else
				{
					printf("RRA ");
					RRA;
				}
			}
			printf("PB ");
			PB;
			min = find_min(l_a);
			count++;
		}
		if (!ft_is_unvalid(l_b))
		{
			do_tests(tab, l_a, l_b);
			ret = attrib_tests(tab);
			apply_test(ret, l_a, l_b);
		}
		else
		{
			do_tests_onlya(tab, l_a);
			ret = attrib_tests_onlya(tab);
			apply_test(ret, l_a, l_b);
		}
		//		affiche(l_a, nbr - 2);
		//		affiche(l_b, nbr - 2);
		//		printf("\n");
	}
	while (l_b[0] != 0)
	{
		printf("PA ");
		PA;
	}
}

void merge(int numbers[], int temp[], int left, int mid, int right)
{
	int i, left_end, num_elements, tmp_pos;

	left_end = mid - 1;
	tmp_pos = left;
	num_elements = right - left + 1;

	while ((left <= left_end) && (mid <= right))
	{
		if (numbers[left] <= numbers[mid])
		{
			temp[tmp_pos] = numbers[left];
			tmp_pos = tmp_pos + 1;
			left = left +1;
			printf("X  ");
		}
		else
		{
			temp[tmp_pos] = numbers[mid];
			tmp_pos = tmp_pos + 1;
			mid = mid + 1;
			printf("X  ");
		}
	}
	while (left <= left_end)
	{
		temp[tmp_pos] = numbers[left];
		left = left + 1;
		tmp_pos = tmp_pos + 1;
		printf("X  ");
	}
	while (mid <= right)
	{
		temp[tmp_pos] = numbers[mid];
		mid = mid + 1;
		tmp_pos = tmp_pos + 1;
		printf("X  ");
	}
	for (i = 0; i <= num_elements; i++)
	{
		numbers[right] = temp[right];
		right = right - 1;
		printf("X  ");
	}
}

void m_sort(int numbers[], int temp[], int left, int right)
{
	int mid;

	if (right > left)
	{
		mid = (right + left) / 2;
		m_sort(numbers, temp, left, mid);
		m_sort(numbers, temp, mid+1, right);
		merge(numbers, temp, left, mid+1, right);
	}
}

void mergeSort(int numbers[], int temp[], int array_size)
{
	m_sort(numbers, temp, 0, array_size - 1);
}
