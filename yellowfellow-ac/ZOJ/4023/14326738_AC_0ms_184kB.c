#include <stdio.h>
int main(){
	int tc;
	scanf("%d",&tc);
	while (tc--){
		char rem[500],ram[500];
		scanf("%s%s",rem,ram);
		ram[0]=ram[0]-'a'+'A';
		printf ("%s%s\n",ram,rem);
	}
}