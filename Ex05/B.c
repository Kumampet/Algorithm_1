#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *A;
int comp=0;

void merge(int *A, int left, int mid, int right){
  int *L, *R;
  int n1;
  int n2;
  int i,j,k;

  n1 = mid - left;
  n2 = right - mid;
  //printf("in merge\n" );
  L = (int*)malloc(sizeof(int) * (n1+1));
  R = (int*)malloc(sizeof(int) * (n2+1));

  for(i=0; i<n1; i++){
    L[i]=A[left + i];
  }
  for (i = 0; i < n2; i++) {
    R[i]=A[mid + i];
  }

  L[n1]=INT_MAX;
  R[n2]=INT_MAX;
  i=0;
  j=0;

  for(k=left; k<right; k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      //printf("A[%d]: %d\n",k,A[k]);
      i++;
      comp++;
    }else{
      A[k]=R[j];
      //printf("A[%d]: %d\n",k,A[k]);
      j++;
      comp++;
    }
  }
}
void mergeSort(int *A, int left, int right){
  int mid;
  //printf("margeSort in\n" );
  if (left+1<right) {
    mid = (left + right)/2;
    //printf("left: %d, mid: %d, right: %d\n",left,mid,right);
    //printf("mid->%d\n",mid );
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    //printf("go to merge\n" );
    merge(A, left, mid ,right);
  }
  //merge(A, left, mid ,right);
}

int main() {
  int n;
  int left, right;
  int i;

  //要素の入力
  scanf("%d",&n );
  A = (int*)malloc(sizeof(int) * n);
  for (i=0; i<n; i++) {
    //printf("S[%d]->",i );
    scanf("%d",&A[i]);
  }
  //printf("入力終了\n" );
  mergeSort(A,0,i);

  for (i = 0; i < n; i++) {
    printf("%d",A[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n",comp );
  return 0;
}
