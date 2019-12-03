#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct{
  int id;
  int pi;
  int color;
}Graph;

Graph *G;
int **Adj;
int n;
//color[n]:color[v]の訪問状態を記録
//M[u][v]:uからvへの辺の重みを記録した隣接行列
//d[n];d[v]にTに属する頂点とVーTに属する頂点を繋ぐ辺の中で、重みが最小の辺の重みを記録
//pi[n]:p[v]にMSTに置ける頂点vの親を記録

void init(){
  int i;

  G = malloc(sizeof(Graph) * (n+1));
  Adj = (int**)malloc(sizeof(int*) * (n+1));
  for(i=1; i<=n; i++){
    Adj[i]=(int*)malloc(sizeof(int) * (n+1));
  }
}

void prim(){
  int i,mincost,u;

  for(i=1; i<=n; i++){
    G[i].d = INT_MAX;
    G[i].pi = NIL;
    G[i].color = WHITE;
  }

  d[0] = 0;

  while(1){
    mincost = INT_MAX;
    for(i=1; i<=n; i++){
      if((G[i].color != BLACK)&&(G[i].d<mincost)){
	mincost = G[i].d;
	u = i;
      }
    }

    if(mincost == INT_MAX){
      break;
    }

    G[u].color = BLACK;

    for(i=1; i<=n; i++){
      if(Adj[u][i]>-1){
	if((G[i].color!=BLACK)&&(Adj[u][i]<d[i])){
	  G[i].pi = u;
	  G[i].d = Adj[u][i];
	}
      }
    }
  }
}

int main(){
  int i,j;

  scanf("%d",&n);
  init();
  for(j=1; j<=n; j++){
    for(i=1; i<=n; i++){
      scanf("%d",Adj[i][j]);
    }
  }
  prim();

  return 0;
}
