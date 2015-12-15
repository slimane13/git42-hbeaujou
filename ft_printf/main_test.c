/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:28:04 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/15 18:30:41 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
  char		c;
  int		*n;
 
  n = NULL; 
  c = 'q';
  
  /*
  ** Note :
  ** Ces tests ne sont ni une moulinette, ni representatif de ce qu'il risque d'y avoir en soutenance.
  ** Je met simplement a disposition les tests que j'ai fait sur le mien.
  ** Ce sont en general des combinaisons de plusieurs modificateurs pour chaque option.
  ** Ne paniquez pas si vous ne gerez pas tout ;-)
  ** Bonne chance pour votre printf !
  ** Si vous le faites serieusement, vous pourrez vous en resservir pour les autres projets.
  */

  /* Pourquoi les ft_printf de ft_printf ? Parce que printf renvoie le nombre de caractere qu'il a affiche. Ainsi, on peut verifier si on renvoie bien le bon nombre.
     Attention ! Il doit y avoir un caractere de moins sur le ft_printf puisqu'il n'a qu'un \n, pour plus de lisibilite */

	printf(" ------------------------------------------------------------- \n");

  printf("%d\n", 2147483647);
  ft_printf("%d\n", 2147483647);

  /* Verifiez bien les bornes ! Elles ont tendance a boucler infini ... */

  ft_printf("Les bornes :  %d, %d\n", -2147483648, 2147483647);
  ft_printf("Les bornes :  %u, %u\n", 0, 4294967295);
  ft_printf("Les bornes :  %o, %o\n", 0, 4294967295);
  ft_printf("Les bornes :  %x, %x\n", 0, 4294967295);

  /* Verification des decimals, %i et %d */

  ft_printf("1chiffre 1 %d chiffre 2 %d\n", 42, -42);
  printf("1chiffre 1 %d chiffre 2 %d\n\n", 42, -42);

  ft_printf("2chiffre 1 %   d chiffre 2 % d\n", 42, -42);
  printf("2chiffre 1 %   d chiffre 2 % d\n\n", 42, -42);

  ft_printf("3chiffre 1 %12d chiffre 2 %12d\n", 42, -42);
  printf("3chiffre 1 %12d chiffre 2 %12d\n\n", 42, -42);

  ft_printf("4chiffre 1 %-12d chiffre 2 %-12d\n", 42, -42);
  printf("4chiffre 1 %-12d chiffre 2 %-12d\n\n", 42, -42);

  ft_printf("5chiffre 1 %0d chiffre 2 %0d\n", 42, -42);
  printf("5chiffre 1 %0d chiffre 2 %0d\n\n", 42, -42);

  ft_printf("6chiffre 1 %012d chiffre 2 %012d\n", 42, -42);
  printf("6chiffre 1 %012d chiffre 2 %012d\n\n", 42, -42);

  ft_printf("7chiffre 1 %-12d chiffre 2 %012d\n", 42, -42);
  printf("7chiffre 1 %-12d chiffre 2 %012d\n\n", 42, -42);

  ft_printf("8chiffre 1 %*d chiffre 2 %*d\n", 42, 6, 6, 6);
  printf("8chiffre 1 %*d chiffre 2 %*d\n\n", 42, 6, 6, 6);

  ft_printf("12chiffre 1 %-+5d chiffre 2 %-+5d\n", 42, -42);
  printf("12chiffre 1 %-+5d chiffre 2 %-+5d\n\n", 42, -42);  

  ft_printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n", 42, -42);
  printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n\n", 42, -42);

  ft_printf("15chiffre 1 %.d chiffre 2 %.d\n", 42, -42);
  printf("15chiffre 1 %.d chiffre 2 %.d\n\n", 42, -42);

  ft_printf("16chiffre 1 %.6d chiffre 2 %.6d\n", 42, -42);
  printf("16chiffre 1 %.6d chiffre 2 %.6d\n\n", 42, -42);

  ft_putstr(" -----  Memes tests avec les c ------ ");
  ft_putchar('\n');
  ft_putchar('\n');

  ft_printf("1caractere 1 %c caractere 2 %c\n", 'a', 'c');
  printf("1caractere 1 %c caractere 2 %c\n\n", 'a', 'c');

  ft_printf("4caractere 1 %12c caractere 2 %12c\n", 'a', 'c');
  printf("4caractere 1 %12c caractere 2 %12c\n\n", 'a', 'c');

  ft_printf("4caractere 1 %-12c caractere 2 %-12c\n", 'a', 'c');
  printf("4caractere 1 %-12c caractere 2 %-12c\n\n", 'a', 'c');

  ft_printf("8caractere 1 %*c caractere 2 %*c\n", 'a', 6, 6, 6);
  printf("8caractere 1 %*c caractere 2 %*c\n\n", 'a', 6, 6, 6);

  ft_printf("15caractere 1 %.c caractere 2 %.c\n", 'a', 'c');
  printf("15caractere 1 %.c caractere 2 %.c\n\n", 'a', 'c');

  ft_putstr(" -----  Memes tests avec les o ------ ");
  ft_putchar('\n');
  ft_putchar('\n');

  ft_printf("1octal 1 %o octal 2 %o\n", 42, -31);
  printf("1octal 1 %o octal 2 %o\n\n", 42, -31);

  ft_printf("4octal 1 %12o octal 2 %12o\n", 42, -42);
  printf("4octal 1 %12o octal 2 %12o\n\n", 42, -42);

  ft_printf("4octal 1 %-12o octal 2 %-12o\n", 42, -42);
  printf("4octal 1 %-12o octal 2 %-12o\n\n", 42, -42);

  ft_printf("5octal 1 %0o octal 2 %0o\n", 42, -42);
  printf("5octal 1 %0o octal 2 %0o\n\n", 42, -42);

  ft_printf("6octal 1 %012o octal 2 %012o\n", 42, -42);
  printf("6octal 1 %012o octal 2 %012o\n\n", 42, -42);

  ft_printf("15octal 1 %.o octal 2 %.o\n", 42, -42);
  printf("15octal 1 %.o octal 2 %.o\n\n", 42, -42);

  ft_printf("16octal 1 %.6o octal 2 %.6o\n", 42, -42);
  printf("16octal 1 %.6o octal 2 %.6o\n\n", 42, -42);
  
  ft_printf("1octal 1 %o octal 2 %o\n", 42, -42);
  printf("1octal 1 %o octal 2 %o\n\n", 42, -42);

  ft_printf("4octal 1 %12o octal 2 %12o\n", 42, -42);
  printf("4octal 1 %12o octal 2 %12o\n\n", 42, -42);

  ft_printf("4octal 1 %-12o octal 2 %-12o\n", 42, -42);
  printf("4octal 1 %-12o octal 2 %-12o\n\n", 42, -42);

  ft_printf("5octal 1 %0o octal 2 %0o\n", 42, -42);
  printf("5octal 1 %0o octal 2 %0o\n\n", 42, -42);

  ft_printf("6octal 1 %012o octal 2 %012o\n", 42, -42);
  printf("6octal 1 %012o octal 2 %012o\n\n", 42, -42);

  ft_printf("8octal 1 %*o octal 2 %*o\n", 42, 6, 6, 6);
  printf("8octal 1 %*o octal 2 %*o\n\n", 42, 6, 6, 6);

  ft_printf("15octal 1 %.o octal 2 %.o\n", 42, -42);
  printf("15octal 1 %.o octal 2 %.o\n\n", 42, -42);

  ft_printf("16octal 1 %.6o octal 2 %.6o\n", 42, -42);
  printf("16octal 1 %.6o octal 2 %.6o\n\n", 42, -42);

  ft_putstr(" -----  Memes tests avec les x ------ ");
  ft_putchar('\n');
  ft_putchar('\n');

  ft_printf("1hexa 1 %x hexa 2 %x\n", 42, -42);
  printf("1hexa 1 %x hexa 2 %x\n\n", 42, -42);

  ft_printf("4hexa 1 %12x hexa 2 %12x\n", 42, -42);
  printf("4hexa 1 %12x hexa 2 %12x\n\n", 42, -42);

  ft_printf("4hexa 1 %-12x hexa 2 %-12x\n", 42, -42);
  printf("4hexa 1 %-12x hexa 2 %-12x\n\n", 42, -42);

  ft_printf("5hexa 1 %0x hexa 2 %0x\n", 42, -42);
  printf("5hexa 1 %0x hexa 2 %0x\n\n", 42, -42);

  ft_printf("6hexa 1 %012x hexa 2 %012x\n", 42, -42);
  printf("6hexa 1 %012x hexa 2 %012x\n\n", 42, -42);

  ft_printf("8hexa 1 %*x hexa 2 %*x\n", 42, 6, 6, 6);
  printf("8hexa 1 %*x hexa 2 %*x\n\n", 42, 6, 6, 6);

  ft_printf("15hexa 1 %.x hexa 2 %.x\n", 42, -42);
  printf("15hexa 1 %.x hexa 2 %.x\n\n", 42, -42);

  ft_printf("16hexa 1 %.6x hexa 2 %.6x\n", 42, -42);
  printf("16hexa 1 %.6x hexa 2 %.6x\n\n", 42, -42);

  ft_putstr(" -----  Memes tests avec les X ------ ");
  ft_putchar('\n');
  ft_putchar('\n');

  ft_printf("1hexa-maj 1 %X hexa-maj 2 %X\n", 42, -42);
  printf("1hexa-maj 1 %X hexa-maj 2 %X\n\n", 42, -42);

  ft_printf("4hexa-maj 1 %12X hexa-maj 2 %12X\n", 42, -42);
  printf("4hexa-maj 1 %12X hexa-maj 2 %12X\n\n", 42, -42);

  ft_printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n", 42, -42);
  printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n\n", 42, -42);

  ft_printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n", 42, -42);
  printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n\n", 42, -42);

  ft_printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n", 42, -42);
  printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n\n", 42, -42);

  ft_printf("8hexa-maj 1 %*X hexa-maj 2 %*X\n", 42, 6, 6, 6);
  printf("8hexa-maj 1 %*X hexa-maj 2 %*X\n\n", 42, 6, 6, 6);

  ft_printf("15hexa-maj 1 %.X hexa-maj 2 %.X\n", 42, -42);
  printf("15hexa-maj 1 %.X hexa-maj 2 %.X\n\n", 42, -42);

  ft_printf("16hexa-maj 1 %.6X hexa-maj 2 %.6X\n", 42, -42);
  printf("16hexa-maj 1 %.6X hexa-maj 2 %.6X\n\n", 42, -42);

  /* Memes tests avec les %p */
  ft_putstr(" -----  Memes tests avec les P ------ ");
  ft_putchar('\n');
  ft_putchar('\n');

  ft_printf("1pointeur 1 %p pointeur 2 %p\n", &c, &c);
  printf("1pointeur 1 %p pointeur 2 %p\n\n", &c, &c);

  ft_printf("4pointeur 1 %12p pointeur 2 %12p\n", &c, &c);
  printf("4pointeur 1 %12p pointeur 2 %12p\n\n", &c, &c);

  ft_printf("4pointeur 1 %-12p pointeur 2 %-12p\n", &c, &c);
  printf("4pointeur 1 %-12p pointeur 2 %-12p\n\n", &c, &c);

  ft_printf("15pointeur 1 %.p pointeur 2 %.p\n", &c, &c);
  printf("15pointeur 1 %.p pointeur 2 %.p\n\n", &c, &c);

  /* Memes tests avec les %u */
  ft_putstr(" -----  Memes tests avec les U ------ ");
  ft_putchar('\n');
  ft_putchar('\n');

  ft_printf("1unsigned 1 %u unsigned 2 %u\n", 42, -42);
  printf("1unsigned 1 %u unsigned 2 %u\n\n", 42, -42);

  ft_printf("4unsigned 1 %12u unsigned 2 %12u\n", 42, -42);
  printf("4unsigned 1 %12u unsigned 2 %12u\n\n", 42, -42);

  ft_printf("4unsigned 1 %-12u unsigned 2 %-12u\n", 42, -42);
  printf("4unsigned 1 %-12u unsigned 2 %-12u\n\n", 42, -42);

  ft_printf("5unsigned 1 %0u unsigned 2 %0u\n", 42, -42);
  printf("5unsigned 1 %0u unsigned 2 %0u\n\n", 42, -42);

  ft_printf("6unsigned 1 %012u unsigned 2 %012u\n", 42, -42);
  printf("6unsigned 1 %012u unsigned 2 %012u\n\n", 42, -42);

  ft_printf("8unsigned 1 %*u unsigned 2 %*u\n", 42, 6, 6, 6);
  printf("8unsigned 1 %*u unsigned 2 %*u\n\n", 42, 6, 6, 6);

  ft_printf("15unsigned 1 %.u unsigned 2 %.u\n", 42, -42);
  printf("15unsigned 1 %.u unsigned 2 %.u\n\n", 42, -42);

  ft_printf("16unsigned 1 %.6u unsigned 2 %.6u\n", 42, -42);
  printf("16unsigned 1 %.6u unsigned 2 %.6u\n\n", 42, -42);


  /* Tests avec une chaine NULLe 
  ft_putstr(" -----  Memes tests avec str NULLe ------ ");
  ft_putchar('\n');
  ft_putchar('\n');

  ft_printf("%s", NULL);
  printf("%s", NULL); */

  /* Test du %% . Attention, les justifications aussi doivent etre gerees ! */
  ft_putstr(" -----  Memes tests avec %% ------ ");
  ft_putchar('\n');
  ft_putchar('\n');

  ft_printf("%%\n");
  printf("%%\n");   

  
  /* Et le dieZ ? */
  ft_putstr(" -----  Memes tests avec les # ------ ");
  ft_putchar('\n');
  ft_putchar('\n');

  ft_printf("%#o\n", 42);
  printf("%#o\n", 42);

  ft_printf("%#5o\n", 42);
  printf("%#5o\n", 42);

  ft_printf("%#5x\n", 42);
  printf("%#5x\n", 42);

  ft_printf("%o\n", -42);
  printf("%o\n", -42);
  
  /* Le %n n'est pas obigatoire. Il consiste a mettre le nombre de caracteres affiches jusqu'a celui ci dans un pointeur sur int */

  printf("%-.12u\n", -20000000);
  ft_printf("%-.12u\n", -20000000);

  printf("%-.12i\n", -20000000);
  ft_printf("%-.12i\n", -20000000);

//  ft_printf("truc");   ALLLLLLLLLLLLLLLOOOOOOOOOOOOOOOOOOO

  ft_printf("truc %d\n", 42);
  printf("truc %d\n", 42);

  /* Ces modificateurs ne sont pas obigatoires (h et l) */

  ft_printf("Test de chiffre sans h : %d, et %d\n", 432767, -432767);
  printf("Test de chiffre sans h : %d, et %d\n", 432767, -432767);

  printf("Test de cliffre avec l : %ld, et %ld\n", 32147483647, -32147483647);
  ft_printf("Test de cliffre avec l : %ld, et %ld\n\n", 32147483647, -32147483647);

  /* Memes tests avec les %s */

  ft_printf("1string 1 %s string 2 %s\n", "toto", "bonjour");
  printf("1string 1 %s string 2 %s\n\n", "toto", "bonjour");

  ft_printf("4string 1 %12s string 2 %12s\n", "toto", "bonjour");
  printf("4string 1 %12s string 2 %12s\n\n", "toto", "bonjour");

  ft_printf("4string 1 %-12s string 2 %-12s\n", "toto", "bonjour");
  printf("4string 1 %-12s string 2 %-12s\n\n", "toto", "bonjour");

  /* Ces tests a ne fonctionnent pas avec le vrai. */

  /*  ft_printf("8string 1 %*s string 2 %*s\n", "toto", 6, "tata", 6);*/
  /*  printf("8string 1 %*s string 2 %*s\n\n", "toto", 6, "tata", 6);*/

  /*ft_printf("9string 1 %+s string 2 %+s\n", "toto", 6, "bonjour", 6);*/
  /*printf("9string 1 %+s string 2 %+s\n\n", "toto", 6, "bonjour", 6);*/

  /*ft_printf("10string 1 %+12s string 2 %+12s\n", "toto", 6, "bonjour", 6);*/
  /*  printf("10string 1 %+12s string 2 %+12s\n\n", "toto", 6, "bonjour", 6);*/

  /*ft_printf("11string 1 %*12s string 2 %*12s\n", "toto", -6, "bonjour", 6);*/
  /*  printf("11string 1 %*12s string 2 %*12s\n\n", "toto", -6, "bonjour", 6);*/
  
  ft_printf("15string 1 %.s string 2 %.s\n", "toto", "bonjour");
  printf("15string 1 %.s string 2 %.s\n\n", "toto", "bonjour");

  ft_printf("16string 1 %.6s string 2 %.6s\n", "toto", "bonjour");
  printf("16string 1 %.6s string 2 %.6s\n\n", "toto", "bonjour");


  /* Et paf ! Segfault...
   Pour savoir quels tests ne fonctionnent pas, mettez un exit par ci par la ;-) */
  
  return (0);
}
