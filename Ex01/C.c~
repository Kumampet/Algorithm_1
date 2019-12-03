#include <stdio.h>
#include <math.h>

int isPrime(int);

int main(){
  int i,n,d;
  int prime_sum=0;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&d);
    prime_sum += isPrime(d);
  }
  printf("%d\n",prime_sum);
}

int isPrime(int p){
  int sq;
  int i;
  if(p < 2) return 0;
  else if(p == 2) return 1;
  else if(p % 2 == 0)return 0;

  sq = sqrt(p);
  for(i=3; i<=sq; i+=2){
    if(p % i == 0) return 0;
  }
  return 1;
}
