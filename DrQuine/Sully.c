#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int i = 5;

#define FT(x, y) int main(int argc, char **argv){if (x <= 0)exit(0); if(argc == 1 && argv[0])x=x+1; char str2[1000]; char cmd[1000]; char *str; str = (char *)malloc(sizeof(char)*9); str[0] = 'S'; str[1] = 'u'; str[2] = 'l'; str[3] = 'l'; str[4] = 'y'; str[5] = '_'; str[6] = i - 1 + '0'; str[7] = '.'; str[8] = 'c'; FILE *f; f = fopen(str, "w"); fprintf(f, y, x - 1, #y); fclose(f); strcpy(str2, str); str2[7] = '\0'; sprintf(cmd, "gcc -Werror -Wall -Wextra -o %s %s; ./%s \"b\"", str2, str, str2); system(cmd);}

FT(i, "#include <stdio.h>\n#include <stdlib.h>\n#include <strings.h>\n\nint i = %d;\n\n#define FT(x, y) int main(int argc, char **argv){if (x <= 0)exit(0); if(argc == 1 && argv[0])x=x+1; char str2[1000]; char cmd[1000]; char *str; str = (char *)malloc(sizeof(char)*9); str[0] = \'S\'; str[1] = \'u\'; str[2] = \'l\'; str[3] = \'l\'; str[4] = \'y\'; str[5] = \'_\'; str[6] = i - 1 + \'0\'; str[7] = \'.\'; str[8] = \'c\'; FILE *f; f = fopen(str, \"w\"); fprintf(f, y, x - 1, #y); fclose(f); strcpy(str2, str); str2[7] = \'\\0\'; sprintf(cmd, \"gcc -Werror -Wall -Wextra -o %%s %%s; ./%%s \"b\"\", str2, str, str2); system(cmd);}\n\nFT(i, %s)\n")
