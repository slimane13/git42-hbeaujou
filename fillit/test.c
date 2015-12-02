/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:28:50 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/02 16:55:58 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#define ROW 6
#define COL 10

struct pentomino
{
	char info;
	int row[5];
	int col[5];
};

typedef struct pentomino pentomino;

pentomino p[63]={'I',0,0,0,0,0,0,1,2,3,4,
	'I',0,1,2,3,4,0,0,0,0,0,
	'X',0,1,1,1,2,0,-1,0,1,0,
	'Z',0,0,1,2,2,0,1,0,-1,0,
	'Z',0,1,1,1,2,0,0,1,2,2,
	'Z',0,0,1,2,2,0,1,1,1,2,
	'Z',0,1,1,1,2,0,-2,-1,0,-2,
	'V',0,1,2,2,2,0,0,0,1,2,
	'V',0,0,0,1,2,0,1,2,0,0,
	'V',0,1,2,2,2,0,0,-2,-1,0,
	'V',0,0,0,1,2,0,1,2,2,2,
	'T',0,0,0,1,2,0,1,2,1,1,
	'T',0,1,1,1,2,0,-1,-1,0,0,
	'T',0,1,2,2,2,0,0,-1,0,1,
	'T',0,1,1,1,2,0,0,1,2,0,
	'W',0,1,1,2,2,0,0,1,1,2,
	'W',0,1,1,2,2,0,-1,0,-2,-1,
	'W',0,0,1,1,2,0,1,1,2,2,
	'W',0,0,1,1,2,0,1,-1,0,-1,
	'U',0,0,0,1,1,0,1,2,0,2,
	'U',0,0,1,2,2,0,1,1,0,1,
	'U',0,0,1,1,1,0,2,0,1,2,
	'U',0,0,1,2,2,0,1,0,0,1,
	'L',0,1,1,1,1,0,0,1,2,3,
	'L',0,1,2,3,3,0,0,0,-1,0,
	'L',0,0,0,0,1,0,1,2,3,3,
	'L',0,0,1,2,3,0,1,0,0,0,
	'L',0,0,1,2,3,0,1,1,1,1,
	'L',0,0,0,0,1,0,1,2,3,0,
	'L',0,1,2,3,3,0,0,0,0,1,
	'L',0,1,1,1,1,0,-3,-2,-1,0,
	'N',0,0,1,1,1,0,1,-2,-1,0,
	'N',0,1,1,2,3,0,0,1,1,1,
	'N',0,0,0,1,1,0,1,2,-1,0,
	'N',0,1,2,2,3,0,0,0,1,1,
	'N',0,0,1,1,1,0,1,1,2,3,
	'N',0,1,2,2,3,0,0,-1,0,-1,
	'N',0,0,0,1,1,0,1,2,2,3,
	'N',0,1,1,2,3,0,-1,0,-1,-1,
	'Y',0,1,1,1,1,0,-2,-1,0,1,
	'Y',0,1,1,2,3,0,-1,0,0,0,
	'Y',0,0,0,0,1,0,1,2,3,1,
	'Y',0,1,2,2,3,0,0,0,1,0,
	'Y',0,0,0,0,1,0,1,2,3,2,
	'Y',0,1,1,2,3,0,0,1,0,0,
	'Y',0,1,1,1,1,0,-1,0,1,2,
	'Y',0,1,2,2,3,0,0,-1,0,0,
	'F',0,1,1,1,2,0,-1,0,1,1,
	'F',0,0,1,1,2,0,1,-1,0,0,
	'F',0,1,1,1,2,0,0,1,2,1,
	'F',0,1,1,2,2,0,0,1,-1,0,
	'F',0,1,1,1,2,0,-2,-1,0,-1,
	'F',0,0,1,1,2,0,1,1,2,1,
	'F',0,1,1,1,2,0,-1,0,1,-1,
	'F',0,1,1,2,2,0,-1,0,0,1,
	'P',0,0,1,1,2,0,1,0,1,1,
	'P',0,0,0,1,1,0,1,2,0,1,
	'P',0,1,1,2,2,0,0,1,0,1,
	'P',0,0,1,1,1,0,1,-1,0,1,
	'P',0,0,1,1,1,0,1,0,1,2,
	'P',0,1,1,2,2,0,-1,0,-1,0,
	'P',0,0,0,1,1,0,1,2,1,2,
	'P',0,0,1,1,2,0,1,0,1,0,
};

char matrix[ROW][COL]={'\0'};
char used[12]={'\0'};

void show()
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		while (j < 10)
		{
			if(matrix[i][j]=='I')
				printf("%c ",matrix[i][j]);
			else if(matrix[i][j]=='X')
				printf("%c ",matrix[i][j]);
			else if(matrix[i][j]=='V')
				printf("%c ",matrix[i][j]);
			else if(matrix[i][j]=='Z')
				printf("%c ",matrix[i][j]);
			else if(matrix[i][j]=='T')
				printf("%c ",matrix[i][j]);
			else if(matrix[i][j]=='W')
				printf("%c ",matrix[i][j]);
			else if(matrix[i][j]=='U')
				printf("%c ",matrix[i][j]);
			else if(matrix[i][j]=='L')
				printf("%c ",matrix[i][j]);
			else if(matrix[i][j]=='L')
				printf("%c ",matrix[i][j]);
			else if(matrix[i][j]=='N')
				printf("%c ",matrix[i][j]);
			else if(matrix[i][j]=='Y')
				printf("%c ",matrix[i][j]);
			else if(matrix[i][j]=='P')
				printf("%c ",matrix[i][j]);
			else if(matrix[i][j]=='F')
				printf("%c ",matrix[i][j]);
			else
				printf("  ");
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
}

void clear(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < ROW)
	{
		while (j < COL)
		{
			matrix[i][j]='\0';
			j++;
		}
		i++;
		j = 0;
	}
}

int	unused(pentomino p)
{
	int i;
	int flag;
	char c;

	flag = 0;
	i = 0;
	c = p.info;
	while(i < 12)
	{
		if(c == used[i])
		{
			flag=1;
			break;
		}
		i++;
	}
	if (flag == 1)
		return (0);
	else
		return (1);

}

int blank(void)
{
	int i;
	int j;
	int flag;

	flag = 0;
	i = 0;
	j = 0;
	while (i < ROW)
	{
		while (j < COL)
		{
			if (matrix[i][j]=='\0')
			{
				flag=1;
				break;
			}
			j++;
		}
		if (flag == 1)
			break;
		i++;
		j = 0;
	}
	if (flag == 1)
		return (0);
	else
		return (1);
}

void findempty(int *row1, int *col1)
{
	int i;
	int j;
	int flag;

	flag = 0;
	i = 0;
	j = 0;
	while (i < ROW)
	{
		while (j < COL)
		{
			if(matrix[i][j]=='\0')
			{
				*row1 = i;
				*col1 = j;
				flag = 1;
				break;
			}
			j++;
		}
		if(flag==1)
			break;
		i++;
		j = 0;
	}
}

int	fit(int row, int col, pentomino pent)
{
	int row1;
	int i;
	int col1;
	int flag;

	flag = 0;
	row1 = row;
	col1 = col;
	i = 0;
	while (i < 5)
	{
		row1+=pent.row[i];
		col1+=pent.col[i];
		if ((matrix[row1][col1] == '\0') && (row1 >= 0 && row1 < ROW && col1 >= 0 && col1 < COL))
		{
		}
		else
		{
			flag=1;
			break;
		}
		row1=row;
		col1=col;
		i++;
	}
	if (flag == 1)
		return (0);
	return (1);
}

void place(int row, int col, pentomino pent)
{
	int row1;
	int i;
	char c;
	int col1;

	row1 = row;
	col1 = col;
	c = pent.info;
	i = 0;
	while (i < 5)
	{
		row1 += pent.row[i];
		col1 += pent.col[i];
		matrix[row1][col1] = c;
		row1 = row;
		col1 = col;
		i++;
	}

}

void unplace(int row, int col, pentomino pent)
{
	int row1;
	int i;
	char c;
	int col1;

	row1 = row;
	col1 = col;
	c = '\0';
	i = 0;
	while (i < 5)
	{
		row1 += pent.row[i];
		col1 += pent.col[i];
		matrix[row1][col1] = c;
		row1 = row;
		col1 = col;
		i++;
	}
}

int pencomb(int row, int col, int counter)
{
	int i;
	int j;
	int k;
	int result;
	int row1;
	int col1;

	i = 0;
	j = 0;
	k = 0;
	result = 0;
	while (i < 63)
	{
		if (unused(p[i]) && (fit(row,col,p[i])))
		{
			used[counter++] = p[i].info;
			place(row,col,p[i]);
			if((counter == 12) && blank())
			{
				show();
				return (1);
			}
			findempty(&row1,&col1);
			result = pencomb(row1,col1,counter);
			counter--;
			used[counter]='\0';
			unplace(row,col,p[i]);
			if (result == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int main(void)
{
	int result;
	result = pencomb(0,0,0);
	printf("%d",result);
	return (0);
}
