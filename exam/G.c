#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *p;
int **m;

void init(int n){//各種初期化
  int i;
  p = (int*)malloc(sizeof(int) * (n + 1));//入力時の行列の次数
  m = malloc(sizeof(int*) * (n + 1));//各ステップでの行列積
  for(i=0; i<=n; i++){
    m[i] = malloc(sizeof(int) * (n + 1));
  }
}

int min(int a, int q){//計算した行列積のうち最小の組み合わせを返す
  if (a>q){
    return q;
  }
}

void matrixChainOrder(int n){
  int i,l,j,k,q;

  for(i = 1; i <= n; i++){//最下端は０で初期化
    m[i][i] = 0;
  }
  for(l = 2; l<=n; l++){
    for(i = 1; i<=n-l+1; i++){
      j = i+l-1;
      m[i][j] = INT_MAX;
      for(k = i; k<=j-1; k++){
        q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
        m[i][j] = min(m[i][j],q);
      }
    }
  }
}

int main() {
  int n=8, garbage;
  int i;

  //scanf("%d",&n);
  init(n);
  scanf("%d %d",&p[0], &p[1]);
  for(i=2; i<=n; i++){
    scanf("%d %d",&garbage, &p[i]);
  }
  matrixChainOrder(n);
  printf("%d\n",m[1][n]);
  return 0;
}
