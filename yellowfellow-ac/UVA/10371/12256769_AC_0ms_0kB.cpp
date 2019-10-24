//UVA 10371 Time Zones
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
int main()
{
	map<string,int>code;
	map<string,int>cum;
	code["UTC"]=0;
	code["GMT"]=0;
	code["BST"]=1;
	code["IST"]=1;
	code["WET"]=0;
	code["WEST"]=1;
	code["CET"]=1;
	code["CEST"]=2;
	code["EET"]=2;
	code["EEST"]=3;
	code["MSK"]=3;
	code["MSD"]=4;
	code["AST"]=-4;
	code["ADT"]=-3;
	code["NST"]=-3;
	cum["NST"]=-1;
	code["NDT"]=-2;
	cum["NDT"]=-1;
	code["EST"]=-5;
	code["EDT"]=-4;
	code["CST"]=-6;
	code["CDT"]=-5;
	code["MST"]=-7;
	code["MDT"]=-6;
	code["PST"]=-8;
	code["PDT"]=-7;
	code["HST"]=-10;
	code["AKST"]=-9;
	code["AKDT"]=-8;
	code["AEST"]=10;
	code["AEDT"]=11;
	code["ACST"]=9;
	cum["ACST"]=1;
	code["ACDT"]=10;
	cum["ACDT"]=1;
	code["AWST"]=8;
	int tc;
	cin>>tc;
	while (tc--)
	{
		char temp[500];
		int h=0;
		int m=0;
		int am;
		scanf("%s",temp);
		int l=strlen(temp);
		if (temp[0]=='n')
		{
			am=0;
		}
		else if (temp[0]=='m')
		{
			am=1;
		}
		else
		{
			int mode=0;
			for (int i=0;i<l;i++)
			{
				if (temp[i]==':')
				{
					mode=1;
				}
				if (temp[i]>='0'&&temp[i]<='9')
				{
					if (mode==0)
					{
						h*=10;
						h+=temp[i]-'0';
					}
					if (mode==1)
					{
						m*=10;
						m+=temp[i]-'0';
					}
				}
			}
			scanf("%s",temp);
			if (temp[0]=='a')am=1;
			else am=0;
		}
		h%=12;
		int shift=0;
		int sec=0;
		string firs;
		cin>>firs;
		shift-=code[firs];
		sec-=cum[firs];
		cin>>firs;
		shift+=code[firs];
		sec+=cum[firs];
		if (sec==2)
		{
			sec=0;
			shift++;
		}
		if (sec==-2)
		{
			sec=0;
			shift--;
		}
		if (sec==1)
		{
			m+=30;
			if (m>=60)
			{
				m%=60;
				h++;
				if (h>=12)
				{
					am^=1;
					h%=12;
				}
			}
		}
		else if (sec==-1)
		{
			m-=30;
			if (m<0)
			{
				m+=60;
				m%=60;
				h--;
				if (h<0)
				{
					am^=1;
					h+=12;
					h%=12;
				}
			}
		}
		h+=shift;
		if (h<0)
		{
			int mon=0;
			while (h<0)
			{
				mon++;
				h+=12;
			}
			h%=12;
			if (mon%2==1)
				am^=1;
		}
		if (h>=12)
		{
			int mon=h;
			h%=12;
			if ((mon/12)%2==1)
				am^=1;
		}
		if (m==0&&h==0)
		{
			if (am==1)printf ("midnight\n");
			else printf ("noon\n");
		}
		else
		{
			if (am==1)
			{
				if (h==0)
					printf ("12:%02d a.m.\n",m);
				else printf ("%d:%02d a.m.\n",h,m);
			}
			else
			{
				if (h==0)
					printf ("12:%02d p.m.\n",m);
				else printf ("%d:%02d p.m.\n",h,m);
			}
		}
	}
}