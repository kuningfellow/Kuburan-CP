// menguji malfple

#include<stdio.h>
#include<map>

typedef long long int LL;
using namespace std;

struct state {
    int len, link;
    map<char,int>next;//use array if TLE
};
  
const int MAXLEN = 100005;
state st[MAXLEN*2];
int sz, last;
  
void sa_init() {
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    st[0].next.clear();
    ++sz;
}

void sa_extend (char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].next.clear();
    int p;
    for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c] = cur;
    if (p == -1)
        st[cur].link = 0;
    else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

LL d[MAXLEN*2];
LL distsub(int ver)
{
	LL  tp = ver != 0;
	if(d[ver]) return d[ver];
	
	for(map<char, int>::iterator it=st[ver].next.begin();it!=st[ver].next.end();it++)
	{
		tp+=distsub(it->second);
	}
	d[ver]=tp;
	return d[ver];
}

char str[100005];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%s", str);
    sa_init();
    for (int i = 0; str[i] != '\0'; i++) {
      sa_extend(str[i]);
    }
    for (int i = 0; i < last; i++) {
      d[i] = 0;
    }
    printf("%lld\n", distsub(0));
  }
  return 0;
}