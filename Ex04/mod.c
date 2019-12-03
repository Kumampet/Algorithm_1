#include <stdio.h>

int main(){
  int a,b;
  while (1) {
    /* code */
    printf("Ctrl+Cで終了\n" );
    printf("計算する値を入力してください\n");
    printf("例：5%%8\n" );
    scanf("%d %d",&a,&b );
    printf("答えは：%d\n",a%b );
  }
  return 0;
}
