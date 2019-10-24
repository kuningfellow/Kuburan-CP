#include <stdio.h>
int main(){int i,n,f;scanf ("%d%d%d",&n,&f,&i);int j;for (j=1;j<i+1;j++){if (j%n==0&&j%f==0){printf ("FizzBuzz\n");}else if (j%n==0){printf ("Fizz\n");}else if(j%f==0){printf ("Buzz\n");}else printf ("%i\n",j);}}
