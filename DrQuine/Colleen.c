#include <stdio.h>

void    boucle() {int i = 0; while (i < 2) i++;}
/* out of main */
int        main() {
	char    *str="#include <stdio.h>%c%cvoid    boucle() {int i = 0; while (i < 2) i++;}%c/* out of main */%cint        main() {%c	char    *str=%c%s%c;%c	/* in main */%c	boucle();%c	printf(str, 10, 10, 10, 10, 10, 34, str, 34, 10, 10, 10, 10, 10);%c}%c";
	/* in main */
	boucle();
	printf(str, 10, 10, 10, 10, 10, 34, str, 34, 10, 10, 10, 10, 10);
}
