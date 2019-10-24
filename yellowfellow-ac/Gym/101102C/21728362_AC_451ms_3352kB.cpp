#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<queue>

using namespace std;

int tot[100005];
priority_queue<pair<int,int> >pq;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
      tot[i] = 0;
      pq.push(pair<int,int>(0, -i));
    }
    int win = 1;
    int when = -1;
    for (int i = 0; i < q; i++) {
      int x, p;
      scanf("%d %d", &x, &p);
      tot[x] += p;
      pq.push(pair<int,int>(tot[x], -x));
      while (tot[-pq.top().second] != pq.top().first) {
        pq.pop();
      }
      DEBUG(printf("the best is %d\n", -pq.top().second);)
      if (-pq.top().second != win) {
        win = -pq.top().second;
        when = i;
      }
    }
    while (!pq.empty()) pq.pop();
    printf("%d\n", when + 1);
  }
  return 0;
}