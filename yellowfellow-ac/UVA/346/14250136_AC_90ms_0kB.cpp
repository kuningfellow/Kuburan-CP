//UVA 346 Getting Chorded
#include <bits/stdc++.h>
using namespace std;
string lis[21]={"B#","C","Db","C#","D","Eb","D#","E","Fb","E#","F","F#","Gb","G","G#","Ab","A","A#","Bb","B","Cb"};
int val[21]={0,0,1,1,2,3,3,4,4,5,5,6,6,7,8,8,9,10,10,11,11};
map<string,int>cor;
int main(){
	for (int i=0;i<21;i++){
		cor[lis[i]]=val[i];
	}
	string a[3];
	string oa[3];
	while(cin>>a[0]>>a[1]>>a[2]){
		for (int i=0;i<3;i++){
			oa[i]=a[i];
			if (a[i][0]>='a'&&a[i][0]<='z'){
				a[i][0]=a[i][0]-'a'+'A';
			}
		}
		int d1,d2,sel,eq;
		for (int i=0;i<3;i++){
			d1=cor[a[(i+1)%3]]-cor[a[i]];
			d2=cor[a[(i+2)%3]]-cor[a[i]];
			d1=(d1+12)%12;
			d2=(d2+12)%12;
			sel=i;
			eq=cor[a[sel]];
			if (d1==7||d2==7)break;
		}
		string ans=a[sel];
		if (ans.length()==2){
			if (ans[1]=='b'){
				for (int i=0;i<21;i++){
					if (val[i]==eq){
						if (lis[i].length()==2&&lis[i][1]=='b')continue;
						ans=lis[i];
						break;
					}
				}
			}
			else if (ans[1]=='#'){
				for (int i=0;i<21;i++){
					if (val[i]==eq&&lis[i].length()==1){
						ans=lis[i];
						break;
					}
				}
			}
		}
		cout<<oa[0]<<" "<<oa[1]<<" "<<oa[2]<<" is";
		if (d1==4&&d2==7)cout<<" a "<<ans<<" Major chord.\n";
		else if (d1==7&&d2==4)cout<<" a "<<ans<<" Major chord.\n";
		else if (d1==3&&d2==7)cout<<" a "<<ans<<" Minor chord.\n";
		else if (d1==7&&d2==3)cout<<" a "<<ans<<" Minor chord.\n";
		else printf (" unrecognized.\n");
	}
}