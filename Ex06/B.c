#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned int *A;
  int n;
  int i,j;
  int l,r;
  int tmp,comp;

  scanf("%d",&n);//要素数の読み込み
  A = (int*)malloc(sizeof(int) * (n+1));
  for(i=1; i<=n; i++){
    scanf("%d",&A[i]);
  }

  comp=A[n];//比較基準
  l=0;
  r=0;
  for(j=1; j<=n; j++){
    if(A[j]<=comp){//基準より小さかった時
      l++;
      tmp=A[l];
      A[l]=A[j];
      A[j]=tmp;
    }else{//基準より大きかったとき
      tmp=A[l+1];
      A[l+1]=A[j];
      A[j]=tmp;
      l++;
    }
  }

  for(i=1; i<=n; i++){
    printf("%d",A[i]);
    if(i!=n){
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}
