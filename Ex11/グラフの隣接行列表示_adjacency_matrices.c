#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int id;
  int k;
  int *v;
}Graph;

Graph *G;
int n;
int **Adj;//隣接行列


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
//任意のIDのバーテックスを持ってくる
//そのバーテックスが持っている子供(接続先)を見る
//接続先IDとループした数字が同じであれば１を入れて終了
  for(j=1; j<=G[id].k; j++){
    for(i = 1; i <= n; i++){
      if(G[id].v[j]==i){
        Adj[id][i]=1;
      }
    }
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
    G[id].id = id;//グラフ構造体配列のID番目にIDを格納すれば順番通りでない入力にも対応できる
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

//mallocの開放を忘れずに
  free(G);
  free(Adj);
  return 0;
}
