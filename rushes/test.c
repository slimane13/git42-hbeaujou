/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 12:48:57 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/20 12:49:41 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LARGEUR_CONSOLE 80

extern int current_line;
void jeu1vsordi(int n, int cpj1, int cpj2, int N, int *tab);
int win(int jgagnant, int nbjoueurs, int n, int *tab);
int menu();
void menuall();
void centrer (const char* str);
ssize_t ft_putstr(char const *s);
void ft_putnbr(long int n);
int regles();
int credits();

int current_line;

int main ()
{
	menu();
	return (0);
}

int menu()
{
	int choix;
	
	ft_putstr("\n\n");
	ft_putstr("Bonjour et bienvenue dans le jeu des allumettes\n");
	system("pause");
	ft_putstr("\n    Que faire ?\n\n");
	ft_putstr("1 - Jouer\n");
	ft_putstr("2 - Quitter");
	ft_putstr("\n\nVotre choix : ");
	scanf("%d", &choix);
	if (choix == 1)
		menuall();
	else if (choix == 2)
		return (0);
	else
	{
		ft_putstr("\nJe n'ai pas compris votre demande....");
		system("pause");
		menu();
	}
	return (0);
}

void menuall()
{
	int n;
	int *tab;
	
	ft_putstr("\n    Que faire ?\n\n");
	ft_putstr("Entrez le nombre d'allumettes\n");
	ft_putstr("\nVotre choix : ");
	scanf("%d", &n);
	current_line = 1;
	tab = (int *)malloc(sizeof(int) * current_line);
	jeu1vsordi(n,0,0,n, tab);
}

void jeu1vsordi(int n, int cpj1, int cpj2, int N, int *tab) // n=nbre allumettes en cours, cpj1, cpj2 = nbre de coups des joueurs, N = nbre allumettes au départ
{
	int j1;
	int j2;
	int i;
	int l;
	int k;
	
	ft_putstr("\n");
	i = 1;
	l = 0;
	while (tab[l])
	{
		while (i <= n)
		{
			ft_putstr("| ");
			i++;
		}
		ft_putstr("\n");
		l++;
	}
	if (n<=24)
		k=48-2*n;
	else
		k=3;
	for(i=1;i<=k;i++)
		ft_putstr(" ");
	printf("Il reste %d allumettes\n\n", n);
	if (cpj1==cpj2)
	{
		scanf("%d", &j1);
		if ((j1<=0)||j1>3)
		{
			ft_putstr("\nAction impossible\n\n");
			jeu1vsordi(n, cpj1, cpj2, N, tab);
		}
		n=n-j1;
		cpj1++;
		if (n==1)
			win(1,1,N, tab);
		else 
			jeu1vsordi(n, cpj1, cpj2, N, tab);
	}
	else
	{
		if (n<=4)
	   		j2=n-1;
		else if ((n>5)&&(n<=8)) 
			j2=n-5;
		else if (n%4==0) 
			j2=3;
		else if (n%4==2) 
			j2=1;
		else if (n%4==3) 
			j2=2;
		else 
		{
			while (j2 == 0) 
				j2=rand()%3;
		}
		ft_putstr("l'IA enleve ");
		ft_putnbr(j2);
		ft_putstr(" allumettes\n");
		n=n-j2;
		cpj2++;
		if (n==1)
			win(3,1,N, tab);
		else
			jeu1vsordi(n, cpj1, cpj2, N, tab);
	}
}

int win(int jgagnant, int nbjoueurs, int n, int *tab)
{
	int choix;

	if (jgagnant == 1)
		ft_putstr("\nBravo mec tu as gagne");
	else
		ft_putstr("\nOrdi a gagne");
	ft_putstr("\nQue faire?\n");
	ft_putstr("1 - Rejouer\n");
	ft_putstr("3 - Quitter\n");
	scanf("%d", &choix);
	if (choix == 1)
		jeu1vsordi(n,0,0,n, tab);
	else if (choix == 2)
		menuall();
	else if (choix == 3)
		return (EXIT_SUCCESS);
	else
		ft_putstr("\nMauvais input, reessaye");
	return 0;
}

void centrer (const char* str)
{
	unsigned int n;
	
	for (n = 0; n < (LARGEUR_CONSOLE-strlen(str)) / 2; n++)
	{
		putchar(' ');
	}
	ft_putstr(str);
}
