#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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
int heap_size = 0;

void maxHeapify(int i){
  int l, r;
  int largest;
  int tmp;

  l=i*2;
  r=i*2+1;

  if((l <= heap_size) && (A[l] > A[i])){
    largest = l;
  }else{
    largest = i;
  }
  if ((r <= heap_size) && (A[r] > A[largest])) {
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

void heapIncreaseKey(int i, int key){
  int tmp;
  int parent = i/2;
  if(key < A[i]){
    return;
  }
  A[i] = key;
  while ((i > 1) && (A[parent] < A[i])) {
    //printf("in\n");
    tmp = A[i];
    A[i] = A[parent];
    A[parent] = tmp;
    i = parent;
  }
  //printf("A[i]:%d\n",A[i]);
}

void insert(int n){

  heap_size++;
  A[heap_size] = -1;
  heapIncreaseKey(heap_size, n);
}

void buildHeap(){
  int i;
  for(i = heap_size/2; i > 0; i--){
    if(i==0) i=1;
    maxHeapify(i);
  }
}

void heapExtructMax(){
  if(heap_size < 1){
    return;
  }
  A[1] = A[heap_size];
  heap_size--;
  maxHeapify(1);
  //buildHeap();
}
/*
void printer(int p){
  int i;
  for (i = 1; i <= p; i++) {
    printf(" %d",A[i]);
  }
  printf("\n");
}
*/
int main() {
  int n;
  char com[10];

  A = (int *)malloc(sizeof(int) * MAX);

  while (1) {
    //printer(heap_size);
    scanf("%s",com);
    if(0==strcmp(com,"end")){
      break;
    }else if(com[0]=='i'){
      //printf("increase\n");
      scanf("%d",&n);
      insert(n);
      //printer(heap_size);
    }else if(0==strcmp(com,"extract")){
      printf("%d\n",A[1]);
      heapExtructMax();
    }else{
      printf("test\n");
      break;
    }
    buildHeap();
    //printf("heap_size:%d\n",heap_size);
  }
  //printf("\n");

  //buildHeap();

  free(A);
  return 0;
}
