#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROOT 0
#define INTERNAL 1
#define LEAF 2

typedef struct{
  int id;//ノードID
  int p;//ノードの親のID
  int d;//ノードの深さ
  char kind[13];//ノードの種類
  int *c;//ノードの子供のID
  int k;
}node;

node *t;

int getDepth(int id){
  if(t[id].p!=-1){
    return getDepth(t[id].p) + 1;
  }
  return 0;
}

int main() {
  int i,j;
  int n;//要素数
  int count;
  int test;

  //全体の要素数の入力
  scanf("%d",&n);
  //printf("How many node: %d\n",n);
  t = (node*)malloc(sizeof(node) * n);
  //ID[i]のノードの情報を入力
  for(i=0; i<n; i++){
    t[i].p=-1;
    //printf("In ID: ");
    scanf("%d",&test);//ID入力
    t[test].id = test;
    t[test].d = 0;
    //printf("In k: " );
    scanf("%d",&t[test].k);//次数入力
    //ノードの種類の決定
    if(t[test].k!=0){
      t[test].c = (int*)malloc(sizeof(int) * t[test].k);//次数の数だけこどものIDを格納する変数を確保
      //次数の数だけ子供のIDを入力
      for (j = 0; j < t[test].k; j++) {
        scanf("%d",&t[test].c[j]);
        //printf("%d\n",t[i].id );
      }
    }
    /*
    if(t[i].k==0){
      strcpy(t[i].kind,"leaf");
    }else if(t[i].p==-1){
      strcpy(t[i].kind,"root");
    }else strcpy(t[i].kind,"internal node");
    */
  }

  for(i=0; i<n; i++){
    for(j=0; j<t[i].k; j++){
      t[t[i].c[j]].p = t[i].id;
    }
  }
  for(i=0; i<n; i++){
    if(t[i].p==-1){
      strcpy(t[i].kind,"root");
    }else if(t[i].k==0){
      strcpy(t[i].kind,"leaf");
    }else strcpy(t[i].kind,"internal node");
    //階層の決定
    t[i].d = getDepth(t[i].id);
  }

  for(i=0; i<n; i++){
    printf("node %d: parent = %d, depth = %d, %s, [",t[i].id,t[i].p,t[i].d,t[i].kind);
    for(j=0; j<t[i].k; j++){
      printf("%d",t[i].c[j]);
      if (j!=t[i].k-1) {
        printf(", ");
      }
    }
    printf("]\n");
  }
  return 0;
}
