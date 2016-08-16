#include <stdio.h>

#define N '\n'
#define T '\t'

/*
 *  cq vq poto
 *	*/

#define FT(x) int main(){FILE *f; f = fopen("Grace_kid.c", "w"); fprintf(f, x, N, N, N, N, N, N, N, T, N, N, N, N, #x, N);}

FT("#include <stdio.h>%c%c#define N '\\n'%c#define T '\\t'%c%c/*%c *  cq vq poto%c *%c*/%c%c#define FT(x) int main(){FILE *f; f = fopen(\"Grace_kid.c\", \"w\"); fprintf(f, x, N, N, N, N, N, N, N, T, N, N, N, N, #x, N);}%c%cFT(%s)%c")
