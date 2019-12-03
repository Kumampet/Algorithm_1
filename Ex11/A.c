#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int id;
  int k;
  int *v;
}Graph;

Graph *G;
int n;
int **Adj;


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
      for(j=1; j<=n; j++){
        printf("%d",Adj[i][j]);
        if(j!=n){
          printf(" ");
        }
      }
      printf("\n");
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
    G[id].v = (int*)malloc(sizeof(int) * (G[id].k+1));
    for(j = 1; j <= G[id].k; j++){
      scanf("%d",&G[id].v[j]);
    }
    getAdj(id);
  }
  //printf("fin enter\n");
  //---------------------
  printer();

  free(G);
  free(Adj);
  return 0;
}
