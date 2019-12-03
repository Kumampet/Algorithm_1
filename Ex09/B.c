#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 2000001
/*
typedef struct{
  int id;
  int parent;
  int left;
  int right;
}Tree;
*/
int *A;
int n;

void insert(int n, int i){
  int size;
  int tmp;

  size = i+1;
  A[size] = -INFINITY;
  heapIncreaseKey(size, n);
}

void heapIncreaseKey(int i, int key){
  int parent = i/2;
  if(key < A[i]){
    return;
  }
  A[i] = key;
  while (i > 1 && A[parent] < A[i]) {
    tmp = A[i];
    A[i] = A[parent];
    A[parent] = A[i];
    i = parent;
  }
}

void maxHeapify(int i){
  int l, r;
  int largest;
  int tmp;

  l=i*2;
  r=i*2+1;

  if((l <= n) && (A[l] > A[i])){
    largest = l;
  }else{
    largest = i;
  }
  if ((r <= n) && (A[r] > A[largest])) {
    largest = r;
  }
  //printf("largest:%d\n",largest );
  //printf("A[largest]:%d\n",A[largest]);
  if(largest != i){
    //printf("A[%d]:%d\n",i,A[i] );
    tmp = A[i];
    A[i] = A[largest];
    A[largest] = tmp;
    maxHeapify(largest);
  }
}

void buildHeap(){
  int i;

  for(i = n/2; i >= 1; i--){
    maxHeapify(i);
  }
}

void printer(){
  int i;

  for (i = 1; i <= n; i++) {
    printf(" %d",A[i] );
  }
  printf("\n");
}

int main() {
  int i;
  int n;
  char com[10];

  A = (int *)malloc(sizeof(int) * MAX;
  i=0;

  while (1) {
    scanf("%s",com);
    if(0==strcmp(com,"end")){
      break;
    }else if(com[0]=='i'){
      scanf("%d",&n);
      insert(n,i);
      i++;
    }else{
      printf("test\n");
    }
  }
  //printf("\n");

  buildHeap();
  printer();

  free(A);
  return 0;
}
