#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct{
  int id;
  int k;
  int *v;
  int color;
  int dist;
  //int dscv;
  //int fin;

}Graph;

Graph *G;
int *Q;
int n = 100;
//int **Adj;
int t;
int head=0, tail=0;


void getDef(){
  int i,j;

  Adj = malloc(sizeof(int*) * (n+1));
  for(i=1;i<=n;i++){
    Adj[i] = malloc(sizeof(int) * (n+1));
    for(j=1;j<=n;j++){
      Adj[i][j] = 0;
    }
  }
}

void getAdj(int id){
  int i,j;
  
  //printf("in getAdj\n");
  for(j=1; j<=G[id].k; j++){
    for(i = 1; i <= n; i++){
      //printf("Adj[%d][%d]->G[id].v[j]:%d\n",id,i,G[id].v[j]);
      if(G[id].v[j]==i){
	Adj[id][i]=1;
      }
      //printf("Adj[%d][%d]->%d\n",id,i,Adj[id][i]);
    }
    //printf("%d\n",Adj[id-1][i]);
  }
}


void printer(){
  int i, j;

  for(i=1; i<=n; i++){
    printf("%d %d\n",G[i].id, G[i].dist);
  }
}

void enqueue(int in){
  Q[tail] = in;
  tail++;
}
int dequeue(){
  int out;

  out = Q[head];
  head++;
  return out;
}

void visit(int id){
  int i;
  int u;

  G[id].color = GRAY;
  //G[id].dscv = ++t;
  enqueue(id);
  while(head!=tail){
    u = dequeue();
    for(i=1; i<=G[id].k; i++){
      if(G[id].color == WHITE){
        G[id].color = GRAY;
        G[id].dist = G[u].dist + 1;
        enqueue(G[G[id].v[i]].id);
      }
    }
    G[u].color = BLACK;
  }

}
/*
void dfs(){
  int i,j;

  for(i=1; i<=n; i++){
    G[i].color = WHITE;
  }
  t = 0;
  for(i=1; i<=n; i++){
    if(G[i].color == WHITE){
      visit(G[i].id);
    }
  }
}
*/
void bfs(){
  int i,j;

  for(i=1; i<=n; i++){
    G[i].color = WHITE;
    G[i].dist = 0;
  }
  for(i=1; i<=n; i++){
    if(G[i].color == WHITE){
      visit(G[i].id);
    }
  }
}

int main() {
  int i, j;
  int id;

  //-----各種入力処理------
  //scanf("%d",&n);
  //G = malloc(sizeof(Graph) * (n+1));
  //Q = malloc(sizeof(int) * (n+1));
  getDef();
  for (i = 1; i <= n; i++) {
    //getAdj(id);
    for(j=1; j<=n; j++){
      scanf("%d",&Adj[j][i]);
    }
  }
  //dfs();
  //printf("fin enter\n");
  //---------------------
  printer();

  free(G);
  free(Q);
  free(G->v);
  //free(Adj);
  return 0;
}
