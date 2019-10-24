#include<stdio.h>
#include<math.h>
int main(){
	int n;
	scanf("%d",&n);
	char rem[500];
	scanf("%s",rem);
	int up=0;
	for (int i=0;i<n;i++){
		if (rem[i]=='X')up++;
	}
	printf ("%d\n",abs(up-n/2));
	if (up>n/2){
		up-=n/2;
		for (int i=0;i<n;i++){
			if (rem[i]=='X'&&up>0){
				printf ("x");
				up--;
			}
			else{
				printf ("%c",rem[i]);
			}
		}
	}
	else{
		up=n/2-up;
		for (int i=0;i<n;i++){
			if (rem[i]=='x'&&up>0){
				printf ("X");
				up--;
			}
			else{
				printf ("%c",rem[i]);
			}
		}
	}
}