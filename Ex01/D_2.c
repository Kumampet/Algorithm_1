#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 200000
#define MAX_P 1000000000
int main(){
  int n,price,min,max_prof=-MAX_P;
  int i,j;

  //要素数の指定
  while(1){
    scanf("%d",&n);
    if((1<n)&&(n<=MAX)) break;
  }
  //要素の入力
  scanf("%d",&min);
  for(i=1; i<n; i++){
    //printf("2\n");
    scanf("%d",&price);
    if((price-min)>max_prof){
      max_prof = price-min;
      //printf("%d\n",max_prof);
    }
    if(min>price){
      min=price;
    }
  }
  //後に入力されたほうから先に入力されたほうの差を求める
  //最大値を更新する
  
  printf("%d\n",max_prof);
  return 0;
}
