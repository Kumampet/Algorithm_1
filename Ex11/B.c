#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct{
  int id;//要素の中身
  int k;//子供の数
  int *v;//kで動的に確保した子供のID
  int color;//巡回判定の色
  int dscv;//最初に発見したステップ数が入る
  int fin;//巡回終了したステップ数が入る
}Graph;

Graph *G;
int n;
int **Adj;
int t;


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
/*
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
*/

void printer(){
  int i, j;

  for(i=1; i<=n; i++){
    printf("%d %d %d\n",G[i].id, G[i].dscv, G[i].fin);
  }
}

void visit(int id){
  int i;

  G[id].color = GRAY;
  G[id].dscv = ++t;
  for(i=1; i<=G[id].k; i++){
    if(G[G[id].v[i]].color == WHITE){
      visit(G[id].v[i]);
    }
  }
  G[id].color = BLACK;
  G[id].fin = ++t;
}

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

int main() {
  int i, j;
  int id;

  //-----各種入力処理------
  scanf("%d",&n);
  G = malloc(sizeof(Graph) * (n+1));
  getDef();
  for (i = 1; i <= n; i++) {
    scanf("%d",&id);
    G[id].id = id;
    scanf("%d",&G[id].k);
    if(G[id].k != 0){
      G[id].v = (int*)malloc(sizeof(int) * (G[id].k+1));
      //G[id].color = (int*)malloc(sizeof(int) * (G[id].k+1));
      for(j = 1; j <= G[id].k; j++){
        scanf("%d",&G[id].v[j]);
      }
    }
    //getAdj(id);
  }
  dfs();
  //printf("fin enter\n");
  //---------------------
  printer();

  free(G);
  free(Adj);
  return 0;
}
