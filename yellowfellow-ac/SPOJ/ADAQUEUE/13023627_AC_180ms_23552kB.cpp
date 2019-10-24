#include <bits/stdc++.h>
using namespace std;
int num[2000005];
int pl,pr;
int main(){
	pl=1000002;
	pr=1000003;
	int n;
	cin>>n;
	char rem[500];
	int a,dir=0;
	for (int i=0;i<n;i++){
		scanf("%s",rem);
		if (!strcmp(rem,"toFront")){
			scanf("%d",&a);
			if (dir==0){
				num[pl--]=a;
			}
			else{
				num[pr++]=a;
			}
		}
		else if (!strcmp(rem,"push_back")){
			scanf("%d",&a);
			if (dir==0){
				num[pr++]=a;
			}
			else{
				num[pl--]=a;
			}
		}
		else if (!strcmp(rem,"reverse")){
			dir^=1;
		}
		else if (!strcmp(rem,"front")){
			if (pl+1==pr){
				printf ("No job for Ada?\n");
			}
			else if (dir==0){
				pl++;
				printf ("%d\n",num[pl]);
			}
			else{
				pr--;
				printf ("%d\n",num[pr]);
			}
		}
		else if (!strcmp(rem,"back")){
			if (pl+1==pr){
				printf ("No job for Ada?\n");
			}
			else if (dir==0){
				pr--;
				printf ("%d\n",num[pr]);
			}
			else{
				pl++;
				printf ("%d\n",num[pl]);
			}
		}
	}
}