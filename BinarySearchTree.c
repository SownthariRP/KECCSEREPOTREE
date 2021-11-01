#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*left;
    struct node*right;
};
//create function
struct node*create(int x,struct node*l,struct node*r)
{
    struct node*t1;
    t1=(struct node*)malloc(sizeof(struct node));
    t1->data=x;
    t1->left=l;
    t1->right=r;
    return t1;
}
//insertion function
struct node *insert(int x, struct node*t)
{
    if(t==NULL)
      return create(x,NULL,NULL);
    else if (x<t->data)
      t->left=insert(x,t->left);
    else
      t->right=insert(x,t->right);
      return t;
} 
void main()
{
	struct node*root=NULL;
    root=insert(52,root);
    root=insert(38,root);
    root=insert(12,root);
    root=insert(18,root);
    root=insert(76,root);
    root=insert(55,root);
    root=insert(34,root);
    root=insert(35,root);
}
