#include <stdio.h>
#include <stdlib.h>

int i = 5;

#define FT(x, y) int main(){if (x < 0)exit(0); FILE *f; f = fopen("Sully_5.c", "w"); fprintf(f, y, x - 1, #y);fclose(f);} 

FT(i, "#include <stdio.h>\n#include <stdlib.h>\n\nint i = %d;\n\n#define FT(x, y, x - 1, #y) int main(){if (x < 0)exit(0); FILE *f; f = fopen(\"Sully_5.c\", \"w\"); fprintf(f, y);fclose(f);}\n\nFT(i, %s)\n")
