#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
  struct node *right;
  struct node *left;
  struct node *parent;
  int key;
  char type[13];
};
typedef struct node * Node;
#define NIL NULL

Node root;
Node z;
int n;

void insert(int i, int l, int r){
  z = malloc(sizeof(struct node));
  z->key = i;
  z->left->key = l;
  z->right->key = r;
  //printf("ID:%d Left_child:%d Right_child:%d\n",z->key, z->left->key,z->right->key);
}
void parent(){
  if((z->left->key==-1)&&(z-)){

  }
}

int main() {
  int id;
  int left;
  int right;
  int i;

  scanf("%d",&n);
  for (i = 0; i < n; i++) {
    scanf("%d",&id);
    scanf("%d",&left);
    scanf("%d",&right );
    insert(id, left, right);
  }
  for (i = 0; i < n; i++) {
    parent();
  }

  return 0;
}
