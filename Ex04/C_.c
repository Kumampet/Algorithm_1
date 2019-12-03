#include <stdio.h>
#include <stdlib.h>

#define MAXJOB 1000000
#define MAXLEN 12

char dec[MAXJOB][MAXLEN];



int main() {
  int i;
  int n;
  char com[9], str[MAXLEN];

  scanf("%d",&n );
  for(i=0; i<n; i++){
    scanf("%s %s",com,str);
    if(com[0]=='i'){
      insert(str);
    }else find(str);
  }
  return 0;
}
