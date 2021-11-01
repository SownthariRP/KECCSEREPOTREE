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
//search
int search(struct node*T,int x)
{
    if (T==NULL)
    return 0;
    else if(T->data==x)
    {
        printf("\nfound");
        return 0;
    } 
     else if 
        (x<T->data)
        return(search(T->left,x));
    else if 
        (x>T->data)
        return(search(T->right,x));
    
}
//find min value
int findmin(struct node*T)
{
    if(T==NULL)
      return 0;
    while(T->left!=NULL)
      T=T->left;
      return(T->data);
}
void main()
{       
	int b,x;
	struct node*root=NULL;
    root=insert(52,root);
    root=insert(38,root);
    root=insert(12,root);
    root=insert(18,root);
    root=insert(76,root);
    root=insert(55,root);
    root=insert(34,root);
    root=insert(35,root);
	x= findmin(root);
    printf("\n %d",x);
	 b=search(root,22);
}
