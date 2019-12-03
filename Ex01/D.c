#include <stdio.h>
#define MAX 200000
int main(){
  int n,p,max_p,min_p;
  int i,j;

  //要素数の指定
  while(1){
    //printf("1\n");
    scanf("%d",&n);
    if((1<n)&&(n<=MAX)) break;
  }
  //要素の入力
  for(i=0; i<n; i++){
    scanf("%d",&p);
    if(p<min_p){
      min_p = p;
    }
    if(p>max_p){
      max_p
  printf("%d\n",max_p - min_p);
  return 0;
}
