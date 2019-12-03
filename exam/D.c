//分割統治法を用いたマージソート

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *A;
int *B;
int n=1000000;
//int comp=0;

void A_merge(int *A, int left, int mid, int right){
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
    }else{
      A[k]=R[j];
      //printf("A[%d]: %d\n",k,A[k]);
      j++;
    }
  }
}

void B_merge(int *B, int left, int mid, int right){
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
    L[i]=B[left + i];
  }
  for (i = 0; i < n2; i++) {
    R[i]=B[mid + i];
  }

  L[n1]=INT_MAX;
  R[n2]=INT_MAX;
  i=0;
  j=0;

  for(k=left; k<right; k++){
    if(L[i]<=R[j]){
      B[k]=L[i];
      //printf("A[%d]: %d\n",k,A[k]);
      i++;
    }else{
      B[k]=R[j];
      //printf("A[%d]: %d\n",k,A[k]);
      j++;
    }
  }
}
void A_mergeSort(int *A, int left, int right){
  int mid;
  //printf("margeSort in\n" );
  if (left+1<right) {
    mid = (left + right)/2;
    //printf("left: %d, mid: %d, right: %d\n",left,mid,right);
    //printf("mid->%d\n",mid );
    A_mergeSort(A, left, mid);
    A_mergeSort(A, mid, right);
    //printf("go to merge\n" );
    A_merge(A, left, mid ,right);
  }
  //merge(A, left, mid ,right);
}

void B_mergeSort(int *B, int left, int right){
  int mid;
  //printf("margeSort in\n" );
  if (left+1<right) {
    mid = (left + right)/2;
    //printf("left: %d, mid: %d, right: %d\n",left,mid,right);
    //printf("mid->%d\n",mid );
    B_mergeSort(B, left, mid);
    B_mergeSort(B, mid, right);
    //printf("go to merge\n" );
    B_merge(B, left, mid ,right);
  }
  //merge(A, left, mid ,right);
}

int max(){
  int i,j;
  //int maxim;

  for(i=n-1; i>0; i--){
    for(j=i; j>0; j--){
      if(A[i]==B[i]){
	printf("A[%d]:%d---B[%d]:%d\n",i,A[i],i,B[i]);
	return A[i];
      }else if(A[i]==B[j]){
	printf("A[%d]:%d----B[%d]:%d\n",i,A[i],j,B[j]);
	return B[j];
      }else if(B[i]==A[j]){
	printf("B[%d]:%d---A[%d]:%d\n",i,B[i],j,A[j]);
	return A[j];
      }
    }
  }
  return -1;
}

int main() {
  int left, right;
  int i;

  //要素の入力
  //scanf("%d",&n );
  A = (int*)malloc(sizeof(int) * n);
  B = (int*)malloc(sizeof(int) * n);
  for (i=0; i<n; i++) {
    //printf("S[%d]->",i );
    scanf("%d",&A[i]);
  }
  for(i=0; i<n; i++){
    scanf("%d",&B[i]);
  }
  //printf("入力終了\n" );
  A_mergeSort(A,0,n-1);
  B_mergeSort(B,0,n-1);

  /*
  for (i = 0; i < n; i++) {
    printf("%d\n%d\n",A[i],B[i]);
    if(i!=n-1)printf(" ");
  }
  */

  printf("Ans: %d\n",max());
  return 0;
}
