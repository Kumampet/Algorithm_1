#include <stdio.h>

#define MAX 100

int main(){
  int i,j;
  int n;
  int a[MAX];
  int minj;
  int key;
  int dif=0;

  scanf("%d",&n);//要素数
  for(i=0; i<n; i++){//要素読み
    scanf("%d",&a[i]);
  }

  for(i=0; i<n-1; i++){
    minj=i;
    for(j=i; j<=n-1; j++){
      if(a[j]<a[minj]){
	minj = j;
      }
    }
    key=a[i];
    a[i]=a[minj];
    a[minj]=key;
    if(i!=minj)dif++;
  }
  for(i=0; i<n; i++){
    printf("%d",a[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n",dif);

  return 0;
}
