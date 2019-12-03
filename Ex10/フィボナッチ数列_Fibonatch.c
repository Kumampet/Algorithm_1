#include <stdio.h>
#include <stdlib.h>

int *F;

void defFibonacci(int n){
  int i;
  //自明的な頭二つの値を決める
  F[0] = 1;
  F[1] = 1;
  for (i = 2; i <= n; i++) {//それ以上は-1で初期化
    F[i] = -1;
  }
}

int fibonacci(int n){//動的計画法を使って重複する計算を省く
  if (n==0 || n==1) {
    return F[n]=1;
  }
  if (F[n]!=-1) {
    return F[n];//F[n]が計算済み(-1ではない値がある)ならそのまま表示する
  }else{
    return F[n] = fibonacci(n - 2) + fibonacci(n - 1);
  }
}

int main() {
  int n;
  int i;

  scanf("%d",&n);
  F = malloc(sizeof(int) * (n+1));
  defFibonacci(n);
  printf("%d\n",fibonacci(n));

  free(F);
  return 0;
}
