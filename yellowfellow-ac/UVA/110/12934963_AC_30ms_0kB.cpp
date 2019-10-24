#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int take[9];
int n;
void spacer(int n){
	for (int i=0;i<n;i++){
		printf ("  ");
	}
}
void rec(int p){
	if (p==n){
		for (int i=0;i<n;i++){
			printf ("  ");
		}
		printf ("writeln(");
		for (int i=0;i<n;i++){
			printf ("%c",take[i]+'a');
			if (i<n-1)printf (",");
		}
		printf (")\n");
		return;
	}
	spacer(p);
	printf ("if %c < %c then\n",take[p-1]+'a',take[p]+'a');
	rec(p+1);
	for (int i=p;i>0;i--){
		int temp=take[i];
		take[i]=take[i-1];
		take[i-1]=temp;
		if (i==1){
			spacer(p);
			printf ("else\n");
		}
		else{
			spacer(p);
			printf ("else if %c < %c then\n",take[i-2]+'a',take[i-1]+'a');
		}
		rec(p+1);
	}
	for (int i=1;i<=p;i++){
		int temp=take[i];
		take[i]=take[i-1];
		take[i-1]=temp;
	}
	return;
}
int main(){
	int tc,fir=1;
	cin>>tc;
	while (tc--){
		cin>>n;
		for (int i=0;i<n;i++){
			take[i]=i;
		}
		if (fir==0)printf ("\n");
		fir=0;
		printf ("program sort(input,output);\nvar\n");
		for (int i=0;i<n;i++){
			printf ("%c",i+'a');
			if (i<n-1)printf (",");
		}
		printf (" : integer;\nbegin\n  readln(");
		for (int i=0;i<n;i++){
			printf ("%c",i+'a');
			if (i<n-1)printf (",");
		}
		printf (");\n");
		rec(1);
		printf ("end.\n");
	}
}