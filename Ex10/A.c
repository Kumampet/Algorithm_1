#include <stdio.h>
#include <stdlib.h>

int *F;

void defFibonacci(int n){
  int i;

  F[0] = 1;
  F[1] = 1;
  for (i = 2; i <= n; i++) {
    F[i] = -1;
  }
}

int fibonacci(int n){
  if (n==0 || n==1) {
    return F[n]=1;
  }
  if (F[n]!=-1) {
    return F[n];
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
