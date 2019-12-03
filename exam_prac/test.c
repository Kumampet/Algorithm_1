#include <stdio.h>
#include <stdlib.h>
int main(){
  int n,i;
  int sum=0;

  for(i=0; i<10000; i++){
    scanf("%d",&n);
    sum += n;
  }
  printf("%d\n",sum);

  return 0;
}
