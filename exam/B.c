#include <stdio.h>

#define MAX 201

int main(){
  int a[MAX];
  int i,j,k;
  int key,turn=0;

  //scanf("%d",&n);//要素数の読取り
  for(i=0; i<MAX; i++){
    scanf("%d",&a[i]);//要素の読取り
  }
  for(i=0; i<MAX-1; i++){//バブルソート本体
    for(j=MAX-1; j>i; j--){
      if(a[j]<a[j-1]){
	key=a[j];
	a[j]=a[j-1];
	a[j-1]=key;
	turn++;
      }
    }
  }
  /*
  //以下アウトプット部分
  for(i=0; i<n; i++){
    printf("%d",a[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n",turn);
  */

  printf("%d\n",a[201/2]);
  
  
  return 0;
}
