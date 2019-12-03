#include <stdio.h>
#include <stdlib.h>

int *s;
int *m;
int n, q;

int solve(int i, int m){
  int res;

  if (m==0) {
    return 1;
  }
  if (i >= n) {
    return 0;
  }else{
    res = solve(i + 1, m) || solve(i + 1, m - s[i]);
    return res;
  }
}
int main(){
  int i,j;
  int q=9;
  //要素数と要素の読み込み
  //scanf("%d",&n);
  //s = (int*)malloc(sizeof(int) * n);
  //for(i=0; i<n; i++){
    //printf("s[%d]: ",i);
  //  scanf("%d",&s[i]);
  //}
  //scanf("%d",&q);
  m = (int*)malloc(sizeof(int) * q);
  for(i=0; i<q; i++){
    //printf("m[%d]: ",i);
    scanf("%d",&m[i]);
    if(1==solve(0,m[i])){
      printf("yes\n");
    }else{
      printf("no\n");
    }
  }
  return 0;
}
