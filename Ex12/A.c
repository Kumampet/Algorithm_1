#include <stdio.h>
#include <stdlib.h>

int n;
int **Adj;
int *G;

void getDef(){
  int i,j;

  G = malloc(sizeof(int*) * n);
  for(i=0; i<n; i++){
    G[i] = malloc(sizeof(int) * n);
  }
  Adj = malloc(sizeof(int*) * (n+1));
  for(i=1;i<=n;i++){
    Adj[i] = malloc(sizeof(int) * (n+1));
    for(j=1;j<=n;j++){
      Adj[i][j] = 0;
    }
  }
}

void dataimput(){
  int i,j;
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      scanf("%d",&Adj[i][j]);
    }
  }
}

void prim(){
  int i,j;
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){

    }
  }
}

int main() {
  int i,j;

  scanf("%d",&n);
  init();
  dataimput();

  free(G);
  return 0;
}
