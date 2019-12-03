#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1001

int dataset;
char str_X[MAX_LEN];
char str_Y[MAX_LEN];

void LCSLength(char *X, char *Y){
  int m,n;
  int **c;
  int i,j;

  m = strlen(X);
  c = malloc(sizeof(int*) * (m+1));
  n = strlen(Y);
  for(i=0; i<=m; i++){
    c[i] = malloc(sizeof(int) * (n+1));
  }
  for(i=1; i<=m; i++){
    c[i][0] = 0;
  }
  for(j=0; j<=n; j++){
    c[0][j] = 0;
  }
  for(i=1; i<=m; i++){
    for(j=1; j<=n; j++){
      if(X[i-1]==Y[j-1]){
        c[i][j] = c[i-1][j-1] + 1;
      }else if(c[i-1][j] >= c[i][j-1]){
        c[i][j] = c[i-1][j];
      }else{
        c[i][j] = c[i][j-1];
      }
    }
  }
  printf("%d\n",c[m][n]);
}

int main() {
  int i;

  scanf("%d",&dataset);
  for(i=0; i<dataset; i++){
    scanf("%s",str_X);
    scanf("%s",str_Y);
    LCSLength(str_X, str_Y);
  }
  return 0;
}
