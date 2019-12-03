#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char c;
  int num;
}Card;

Card *T;
int n;

void BubbleSort(){
  int i,j;

  for(i=0; i<n; i++){
    for(j=n-1; j>i; j--){

    }

  }
}

int main() {
  int i;

  scanf("%d",&n);
  T = malloc(sizeof(Card) * n);
  for(i=0; i<n; i++){
    scanf("%c%d",&T[i].c,&T[i].num);
  }
  BubbleSort();
  SelectionSort();

  return 0;
}
