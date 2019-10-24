//UVA 11402 Ahoy, Pirates!
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int ar[1050000];
int tree[4200000];
int lazy[4200000];
void prop(int k,int l, int r)
{
    if (lazy[k]!=0)
    {
        if (lazy[k]==1)
        {
            tree[k]=(r-l+1);
            lazy[k*2]=1;
            lazy[k*2+1]=1;
            lazy[k]=0;
        }
        else if (lazy[k]==2)
        {
            tree[k]=0;
            lazy[k*2]=2;
            lazy[k*2+1]=2;
            lazy[k]=0;
        }
        else if (lazy[k]==3)
        {
            tree[k]=(r-l+1)-tree[k];
            lazy[k*2]=lazy[k]-lazy[k*2];
            lazy[k*2+1]=lazy[k]-lazy[k*2+1];
            lazy[k]=0;
        }
    }
}
void build(int l, int r, int k)
{
    lazy[k]=0;
    if (l==r)
    {
        tree[k]=ar[l];
    }
    else
    {
        build(l,(l+r)/2,k*2);
        build((l+r)/2+1,r,k*2+1);
        tree[k]=tree[k*2]+tree[k*2+1];
    }
}
int query(int l,int r, int ql, int qr, int k)
{
    prop(k,l,r);
    if (ql<=l&&r<=qr)
    {
        return tree[k];
    }
    if (qr<l||ql>r)
    {
        return 0;
    }
    return query(l,(l+r)/2,ql,qr,k*2)+query((l+r)/2+1,r,ql,qr,k*2+1);
}
void update(int l, int r, int ql, int qr, int k, int v)
{
    prop(k,l,r);
    if (qr<l||ql>r)
    {
        return;
    }
    if (ql<=l&&r<=qr)
    {
        lazy[k]=v;
        prop(k,l,r);
        lazy[k]=0;
    }
    else if (l!=r)
    {
        update(l,(l+r)/2,ql,qr,k*2,v);
        update((l+r)/2+1,r,ql,qr,k*2+1,v);
        tree[k]=tree[k*2]+tree[k*2+1];
    }
}
int main()
{
    int tc,kas=1;
    cin>>tc;
    while (tc--)
    {
        int n,k;
        cin>>n;
        char rem[5000];
        int pos=0;
        for (int i=0;i<n;i++)
        {
            cin>>k;
            scanf("%s",rem);
            for (int j=0;j<strlen(rem);j++)
            {
                for (int l=0;l<k;l++)
                {
                    ar[pos+strlen(rem)*l+j]=rem[j]-'0';
                }
            }
            pos+=strlen(rem)*k;
        }
        build(0,pos-1,1);
        cin>>n;
        int a,b;
        int q=0;
        printf ("Case %d:\n",kas++);
        for (int i=0;i<n;i++)
        {
            scanf("%s%d%d",rem,&a,&b);
            if (rem[0]=='F')
            {
                update(0,pos-1,a,b,1,1);
            }
            else if (rem[0]=='E')
            {
                update(0,pos-1,a,b,1,2);
            }
            else if (rem[0]=='I')
            {
                update(0,pos-1,a,b,1,3);
            }
            else if (rem[0]=='S')
            {
                printf ("Q%d: %d\n",++q,query(0,pos-1,a,b,1));
            }
        }
    }
}
