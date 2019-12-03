#include <stdio.h>
#include <stdlib.h>

int *s;
int *m;
int n, q;

int sum(int a, int b){
  return a+b;
}
int judge(int a){
  int sum;
  int i,j;

  for (i = 0; i < n-1; i++) {
    for (j = i+1; j < n; j++) {
      if (a==s[j]) {
        return 1;
      }else if (a==sum(s[i],s[j])) {
        return 1;
      }else judge(m[j]); 
    }
      /* code */
    }
  }
  return 0;
}

int main() {
  int i,j;
  int key;

//要素数と要素の読み込み
  scanf("%d",&n);
  s = (int*)malloc(sizeof(int) * n);
  for(i=0; i<n; i++){
    //printf("s[%d]: ",i);
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  m = (int*)malloc(sizeof(int) * q);
  for(i=0; i<q; i++){
    //printf("m[%d]: ",i);
    scanf("%d",&m[i]);
  }

  for (i = 0; i < q; i++) {
    printf("%d is ",m[i] );
    if(1==judge(m[i])){
      printf("yes\n" );
    }else printf("no\n" );
  }
/*
  for (i = 0; i < n-1; i++) {
    for(j = i + 1; j < n; j++){
      judge(s[i],s[j]);
    }
  }
*/
  return 0;
}
