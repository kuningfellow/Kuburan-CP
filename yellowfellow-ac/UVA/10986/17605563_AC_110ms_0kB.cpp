//strukdat linked list
#include <stdio.h>
#include <stdlib.h>
struct data{
	int vertex;
	int cost;
	struct data* next;
	struct data* prev;
};
typedef struct data data;
void addtodata(int v, int c, data** par){
	data* ndata = (data*)malloc(sizeof(data));
	ndata->vertex =	v;
	ndata->cost	= c;
	ndata->next = *par;
	ndata->prev = NULL;
	if (*par != NULL){
		(*par)->prev = ndata;
	}
	*par = ndata;
	return;
}
void swap(data* a, data* b){
	data temp;
	temp.vertex = a->vertex;
	temp.cost = a->cost;
	a->vertex = b->vertex;
	a->cost = b->cost;
	b->vertex = temp.vertex;
	b->cost = temp.cost;
	return;
}
void heapdown(data* minheap, int heapsize, int x){
	int to = x;
	if (x*2 <= heapsize && minheap[x*2].cost < minheap[to].cost){
		to = x*2;
	}
	if (x*2+1 <= heapsize && minheap[x*2+1].cost < minheap[to].cost){
		to = x*2+1;
	}
	if (to == x)return;
	else{
		swap(&minheap[x], &minheap[to]);
		heapdown(minheap, heapsize, to);
	}
	return;
}
void heapup(data* minheap, int x){
	int to = x;
	if (x/2 == 0)return;
	if (minheap[x].cost < minheap[x/2].cost){
		to = x/2;
	}
	if (to == x)return;
	else{
		swap(&minheap[x], &minheap[to]);
		heapup(minheap, to);
	}
}
void pop(data *minheap, int *heapsize){
	swap(&minheap[1], &minheap[*heapsize]);
	*heapsize = *heapsize-1;
	heapdown(minheap, *heapsize, 1);
}
void add(data *minheap, int *heapsize, int vertex, int cost){
	*heapsize = *heapsize+1;
	minheap[*heapsize].vertex = vertex;
	minheap[*heapsize].cost = cost;
	heapup(minheap, *heapsize);
}
void top(data* minheap, int *vertex, int *cost){
	*vertex = minheap[1].vertex;
	*cost = minheap[1].cost;
}
data heap[5000000];
int main(){
	int tc, kas = 1;
	scanf("%d", &tc);
	while (tc--){
		int n,m,s,e;
		scanf("%d%d%d%d", &n, &m, &s, &e);
		data *adjlist[n];
		int visit[n];
		int heapsize = 0;
		for (int i = 0; i < n; i++){
			adjlist[i] = NULL;
			visit[i] = -1;
		}
		for (int i = 0; i < m; i++){
			int vertex1, vertex2, cost;
			scanf("%d%d%d", &vertex1, &vertex2, &cost);
			addtodata(vertex2, cost, &adjlist[vertex1]);
			addtodata(vertex1, cost, &adjlist[vertex2]);
		}
		add(heap, &heapsize, s, 0);
		int cur_cost=0;
		while (heapsize){
			int vertex, cost;
			top(heap, &vertex, &cost);
			pop(heap, &heapsize);
			if (visit[vertex] != -1)continue;
			visit[vertex] = cost;
			data *curlist = adjlist[vertex];
			data *del;
			while (curlist != NULL){
				if (visit[curlist->vertex] == -1){
					add(heap, &heapsize, curlist->vertex, curlist->cost + cost);
				}
				del = curlist;
				curlist = curlist->next;
				free(del);
			}
		}
		printf ("Case #%d: ",kas++);
		if (visit[e] == -1){
			printf("unreachable\n");
		}
		else{
			printf("%d\n",visit[e]);
		}
	}
}