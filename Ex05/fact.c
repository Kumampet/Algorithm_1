#include <stdio.h>
int fact(int n){
  int a;
  printf("%d\n",n);
  if(n>1){
    a = fact(n-1);
  }
  return (a * n);
}

int main() {
  int a,n;
  scanf("%d",&n );
  a = fact(n);
  printf("%d\n",a);
  return 0;
}
