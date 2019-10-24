#define  DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int pref[200005];
int last1[200005], last2[200005];
int Countblock[450];
int Count[200005];
int ar[200005];
int valT[200005];
int block;
struct query {
  int type, l, r, t;
  bool operator<(const query &o) {
    if (t/block < o.t/block) return true;
    else if (t/block > o.t/block) return false;
    else if (r < o.r) return true;
    else if (r > o.r) return false;
    return t < o.t;
  }
};
vector<query> Q;
vector<query> updates;
vector<pair<int,int>>ans;
// 1=Count, 2=last1, 3=last2
struct mod {
  int type, p, v;
};
vector<mod>mods;

void edit(int type, int p, int v) {
  if (type == 1) {
    Count[p] += v;
    Countblock[p/block] += v;
    mods.push_back({type, p, -v});
  } else if (type == 2) {
    mods.push_back({type, p, last1[p]});
    last1[p] = v;
  } else if (type == 3) {
    mods.push_back({type, p, last2[p]});
    last2[p] = v;
  }
}
void revert(mod x) {
  if (x.type == 1) {
    Count[x.p] += x.v;
    Countblock[x.p/block] += x.v;
  } else if (x.type == 2) {
    last1[x.p] = x.v;
  } else {
    last2[x.p] = x.v;
  }
}

template<typename T>
void getnum(T& var) {
	char c;
	var = 0;
	while ((c = getchar_unlocked()) != EOF) {
		if (c == '-' || (c >= '0' && c <= '9')) break;
	}
	if (c == EOF) return;
	else var = c - '0';
	while ((c = getchar_unlocked()) != EOF) {
		if (c < '0' || c > '9') break;
		var = var * 10 + (c - '0');
	}
}


int main() {
  int n, q;
  getnum(n);
  getnum(q);
  for (int i = 0; i < n; i++) {
    getnum(ar[i]);
  }
  block = sqrt(q);
  for (int i = 0; i < q; i++) {
    query dum;
    getnum(dum.type);
    dum.t = i;
    if (dum.type == 1) {
      getnum(dum.r);
      getnum(dum.l);
    } else {
      getnum(dum.l);
      getnum(dum.r);
    }
    Q.push_back(dum);
  }
  sort(Q.begin(), Q.end());
  for (int i = 0, ptr, sebelum = -1; i < Q.size(); i++) {
    if (sebelum != Q[i].t / block) {
      for (auto u : updates) {
        if (valT[u.r] < u.t) {
          valT[u.r] = u.t;
        }
      }
      for (auto u : updates) {
        if (valT[u.r] == u.t) {
          ar[u.r] = u.l;
        }
      }
      updates.clear();
      for (int j = 0; j < 200005; j++) {
        last1[j] = last2[j] = -1;
        Count[j] = 0;
        if (j / block < 450) Countblock[j / block] = 0;
        valT[j] = -1;
      }
      ptr = 0;
    }
    while (ptr <= Q[i].r) {
      pref[ptr] = last1[ar[ptr]];
      if (last2[ar[ptr]] != -1) Count[last2[ar[ptr]]]++, Countblock[last2[ar[ptr]]/block]++;
      if (last1[ar[ptr]] != -1) Count[last1[ar[ptr]]]--, Countblock[last1[ar[ptr]]/block]--;
      last2[ar[ptr]] = last1[ar[ptr]];
      last1[ar[ptr]] = ptr;
      if (last2[ar[ptr]] != -1) Count[last2[ar[ptr]]]--, Countblock[last2[ar[ptr]]/block]--;
      if (last1[ar[ptr]] != -1) Count[last1[ar[ptr]]]++, Countblock[last1[ar[ptr]]/block]++;
      ptr++;
    }
    if (Q[i].type == 1) {
      updates.push_back(Q[i]);
    } else {
      for (int j = updates.size() - 1; j >= 0; j--) {
        if (updates[j].t > Q[i].t) continue;
        if (valT[updates[j].r] < updates[j].t) {
          valT[updates[j].r] = updates[j].t;
        }
      }
      for (int j = updates.size() - 1; j >= 0; j--) {
        if (updates[j].t > Q[i].t) continue;
        if (valT[updates[j].r] == updates[j].t) {
          int x = updates[j].r;
          int v = updates[j].l;
          if (ar[x] == v) continue;
          if (Count[x] == 1) {
            int p = last2[ar[x]];
            edit(1, x, -1);
            edit(2, ar[x], p);
            if (p != -1) {
              edit(1, p, 2);
              edit(3, ar[x], pref[p]);
              if (pref[p] != -1) {
                edit(1, pref[p], -1);
              }
            }
          } else if (Count[x] == -1) {
            edit(1, x, 1);
            int p = pref[x];
            if (p != -1) {
              edit(1, p, -1);
            }
            edit(3, ar[x], p);
          }
          if (last1[v] < x) {
            edit(1, x, 1);
            if (last2[v] != -1) {
              edit(1, last2[v], 1);
            }
            edit(3, v, last1[v]);
            if (last1[v] != -1) {
              edit(1, last1[v], -2);
            }
            edit(2, v, x);
          } else if (last2[v] < x) {
            if (last2[v] != -1) {
              edit(1, last2[v], 1);
            }
            edit(1, x, -1);
            edit(3, v, x);
          }
        }
      }
      int tmp = 0;
      for (int j = Q[i].l; j <= Q[i].r;) {
        if (j % block == 0 && j + block - 1 <= Q[i].r) {
          tmp += Countblock[j / block];
          j += block;
        } else {
          tmp += Count[j];
          j++;
        }
      }
      ans.push_back(pair<int,int>(Q[i].t, tmp));
      for (int j = 0; j < updates.size(); j++) {
        valT[updates[j].r] = -1;
      }
      for (int j = mods.size() - 1; j >= 0; j--) {
        revert(mods[j]);
      }
      mods.clear();
    }
    sebelum = Q[i].t / block;
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d\n", ans[i].second);
  }
}