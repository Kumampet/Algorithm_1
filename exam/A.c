#include <stdio.h>

int main(){
  int i;
  int n[20000];
  int sum=0;

  for(i=0; i<20000; i++){
    scanf("%d",&n[i]);
    if(n[i]==2018){
      sum++;
    }
  }

  printf("%d\n",sum);

  return 0;
}
