#include<stdio.h>
#include<string.h>

char str[50005];

int main(int argc, char * argv[]) {
  if (argc == 3) {
    FILE * in = fopen(argv[1], "r");
    FILE * out = fopen(argv[2], "w");
    while (fgets(str, 50000, in)) {
      if (strcmp(str, "#define DEBUG(...)\n") == 0) {
        fprintf(out, "#include<CDBG.h>\n");
      } else {
        fprintf(out, "%s", str);
      }
    }
  }
}
