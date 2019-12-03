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
  int h;//ノードの深さ
  char kind[13];//ノードの種類
  int lc;
  int rc;//ノードの子供のID
  int k;
  int sib;
  int deg;
}node;

node *t;
int n;//要素数

//高さの決定
void getHeight(int id, int k){
  if(t[id].deg==0){
    t[id].h = 0;
  }
  if(t[id].h < k){
    t[id].h = k;
  }
  if(t[id].p!=-1){
    getHeight(t[id].p, ++k);
  }
}
//兄弟の検索
void getSib(){
  int i,j;
  for(i=0; i<n; i++){
    if(strcmp(t[i].kind,"root")==0)t[i].sib=-1;
    for(j=i+1; j<n; j++){
      if(t[i].d==t[j].d){
        if(t[i].p==t[j].p){
          t[i].sib=t[j].id;
          t[j].sib=t[i].id;
        }
      }
    }
  }
}
//深さの決定
int getDepth(int id){
  if(t[id].p!=-1){
    return getDepth(t[id].p) + 1;
  }
  return 0;
}
//表示
void print(){
  int i;
  //printf("print now\n");
  for(i=0; i<n; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",t[i].id,t[i].p,t[i].sib,t[i].deg,t[i].d,t[i].h,t[i].kind);
  }
}
//----------------------------------------------------------
int main() {
  int i,j;
  int count;
  int id;
  int left, right;

  //全体の要素数の入力
  scanf("%d",&n);
  t = (node*)malloc(sizeof(node) * n);
  //ID[i]のノードの情報を入力
  for(i=0; i<n; i++){
    //printf("In ID: ");
    scanf("%d",&id);//ID入力
    t[id].id = id;
    scanf("%d%d",&t[id].lc,&t[id].rc);
    t[id].p = -1;
    t[id].d = 0;
    t[id].h = 0;
    t[id].sib = -1;
    t[id].deg = 0;
  }
  //  printf("end input\n");
  for (i = 0; i < n; i++) {
    if(t[i].lc!=-1){
      t[t[i].lc].p=t[i].id;
      t[i].deg++;
      //printf("%d:%d\n",t[left].id,t[left].p);
    }
    if(t[i].rc!=-1){
      t[t[i].rc].p=t[i].id;
      t[i].deg++;
      //printf("%d\n",t[right].id,t[right].p);
    }
  }
  //print();
  //ノードの種類の決定
  for(i=0; i<n; i++){
    if(t[i].p==-1){
      strcpy(t[i].kind,"root");
    }else if((t[i].lc==-1)&&(t[i].rc==-1)){
      strcpy(t[i].kind,"leaf");
    }else strcpy(t[i].kind,"internal node");
    //階層の決定
    t[i].d = getDepth(t[i].id);
    getHeight(i, 0);
    //兄弟の決定
    getSib();
  }
  //printf("kink fin\n" );
  print();

  return 0;
}
