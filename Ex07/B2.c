#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int id;
  int k;
  struct *parent;
  struct *left;
  struct *right;
}tree;
