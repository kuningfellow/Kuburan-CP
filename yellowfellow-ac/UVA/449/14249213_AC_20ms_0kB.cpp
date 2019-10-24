//UVA 449 Majoring in Scales
#include <bits/stdc++.h>
using namespace std;
string lis[21]={"B#","C","C#","Db","D","D#","Eb","E","Fb","E#","F","F#","Gb","G","G#","Ab","A","A#","Bb","B","Cb"};
int val[21]={0,0,1,1,2,3,3,4,4,5,5,6,6,7,8,8,9,10,10,11,11};
vector<pair<string,int> >letr[7];
int major_scale[6]={2,4,5,7,9,11};
vector<string>scale[21];
map<string,int>query;
int main(){
	for (int i=0;i<21;i++){
		query[lis[i]]=i;
		letr[lis[i][0]-'A'].push_back(pair<string,int>(lis[i],val[i]));
	}
	for (int i=0;i<21;i++){
		scale[i].push_back(lis[i]);
		int j=0;
		int ptr=lis[i][0]-'A';
		ptr=(ptr+1)%7;
		while (j<6){
			for (int k=0;k<letr[ptr].size();k++){
				int delta=letr[ptr][k].second-val[i];
				delta=(delta%12+12)%12;
				if (delta==major_scale[j]){
					scale[i].push_back(letr[ptr][k].first);
					j++;
					break;
				}
			}
			ptr=(ptr+1)%7;
		}
	}
	char rem[5000];
	while (scanf("%[^\n]",rem)!=EOF){
		getchar();
		string ram="";
		for (int i=0;i<strlen(rem);i++){
			ram+=rem[i];
		}
		cout<<"Key of "<<ram<<endl;
		int scal=query[ram];
		while (1<2){
			scanf("%[^;\n]",rem);
			int c=getchar();
			int l=strlen(rem);
			ram="";
			int idelta=-1;
			int flag=0;
			int dir=0;
			int step=0;
			string a,b;
			for (int i=0;i<l;i++){
				if (rem[i]!=' '){
					ram+=rem[i];
				}
				else{
					if (flag==0){
						cout<<ram<<": ";
						for (int j=0;j<7;j++){
							if (scale[scal][j]==ram){
								idelta=j;
								break;
							}
						}
					}
					else if (flag==1){
						a=ram;
						if (ram=="UP")dir=1;
						else dir=-1;
					}
					flag++;
					ram="";
				}
			}
			b=ram;
			if (idelta==-1){
				cout<<"invalid note for this key\n";
			}
			else{
				if (ram=="SECOND")step=1;
				else if (ram=="THIRD")step=2;
				else if (ram=="FOURTH")step=3;
				else if (ram=="FIFTH")step=4;
				else if (ram=="SIXTH")step=5;
				else if (ram=="SEVENTH")step=6;
				else if (ram=="OCTAVE")step=7;
				int tot=idelta+dir*step;
				tot=(tot%7+7)%7;
				cout<<a<<" "<<b<<" > "<<scale[scal][tot]<<endl;
			}
			if (c=='\n')break;
		}
		printf ("\n");
	}
}