#include <stdio.h>
#include <stdlib.h>
int main(){
  int i,j,k;
  int l;
  int f=0;
  int n[100];
  int key;

  //データ長さ入力
  while(1){
    //printf("prease data length\n");
    scanf("%d",&l);
    if((0<l)&&(l<101)){
      break;
    }
    printf("prease 0<length<101\n");
  }

  //データ入力
  //printf("prease inport number\n");
  for(i=0; i<l; i++){
    scanf("%d",&n[i]);
    if((1000<=n[i])||n[i]<=0){
      printf("prease more low number\n");
      continue;
    }
  }
 
  for(i=0; i<l; i++){
    if(i!=l-1)printf(" ");
  }
  printf("\n");
  
  for(i=1; i<l; i++){
    key = n[i];
    for(j=i-1; j>=0&&n[j]>key; j--){
      n[j+1]=n[j];
      
    }
    n[j+1]=key;
    
    
    for(k=0; k<l; k++){
      printf("%d",n[k]);
      if(k!=l-1)printf(" ");
    }
    printf("\n");
  }
  return 0;
}
