#include <bits/stdc++.h>
namespace kmp{
	int kmp[500];
	int kmpl;
	char string_comp[500];
	void preprocess(const char* string, int l){
		kmpl=l;
		for (int i=0;i<l;i++){
			string_comp[i]=string[i];
		}
		kmp[0]=0;
		int j=0;
		for (int i=1;i<l;i++){
			while (j-1>=0&&string_comp[i]!=string_comp[j]){
				j=kmp[j-1];
			}
			if (string_comp[i]==string_comp[j]){
				j++;
			}
			kmp[i]=j;
		}
		for (int i=0;i<l;i++){
			// printf ("%d",kmp[i]);
		}
	}
	int count(const char* string, int l){
		int return_value=0;
		int j=0;
		for (int i=0;i<l;i++){
			while (j-1>=0&&string_comp[j]!=string[i]){
				j=kmp[j-1];
			}
			if (string_comp[j]==string[i]){
				j++;
			}
			if (j==kmpl){
				j=kmp[j-1];
				return_value++;
			}
		}
		return return_value;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int l;
	std::cin>>l;
	char input_string[l+1];
	scanf("%s",input_string);
	char base_string[4]={"xxx"};
	kmp::preprocess(base_string,3);
	printf ("%d\n",kmp::count(input_string,l));
}