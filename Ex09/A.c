#include <stdio.h>
#include <stdlib.h>
//#include <.h>

typedef struct{
  int id;
  int parent;
  int left;
  int right;
}Tree;

Tree *A;
int n;

void def(){
  int i;
  for (i = 1; i <= n; i++) {
    A[i].id = 0;
    A[i].parent = -1;
    A[i].left = -1;
    A[i].right = -1;
  }
}

void getParent(int i){
  //printf("getParent now\n");
  if(i==1){
    A[i].parent = -1;
    return;
  }
  A[i].parent = i/2;
}

void getChild(int i){
  //printf("getChild now\n");
  if(i*2 > n){
    A[i].left = -1;
  }else{
    A[i].left = i*2;
  }
  if(i*2 + 1 > n){
    A[i].right = -1;
  }else{
    A[i].right = i*2 + 1;
  }
}

void printer(){
  int i;
//各種表示
  for (i = 1; i <= n; i++) {
    printf("node %d: ",i);//添え字
    printf("key = %d, ",A[i].id );//中身
    if(A[i].parent != -1){//親の表示
      printf("parent key = %d, ",A[A[i].parent].id);
    }
    if(A[i].left != -1){//左の子の表示
      printf("left key = %d, ",A[A[i].left].id);
    }
    if(A[i].right != -1){
      printf("right key = %d, ",A[A[i].right].id);
    }
    printf("\n");
  }
}

int main() {
  int x;
  int i;

  scanf("%d",&n);
  A = malloc(sizeof(Tree) * (n + 1));
  def();
  for (i = 1; i <= n; i++) {
    scanf("%d",&A[i].id);
    getParent(i);
    getChild(i);
    //printf("%d ",A[i].id );
  }

  printer();

  free(A);
  return 0;
}
