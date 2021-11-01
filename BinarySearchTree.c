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
//find max value
int findmax(struct node*T)
{
    if(T==NULL)
      return-1;
    while(T->right!=NULL)
      T=T->right;
      return(T->data);
}
//delete
struct node*delete_n(struct node*T,int x)

{
    
    if(T==NULL) 
     return NULL;
  if(x<T->data)
   T->left=delete_n(T->left,x);
  else if(x>T->data)
   T->right=delete_n(T->right,x);//traverse nodes
  else 
  {
      if ((T->left==NULL) && (T->right==NULL))
        return NULL;
      if((T->left==NULL) && (T->right!=NULL))
        return(T->right);
      if((T->right==NULL) && (T->left!=NULL))
        return(T->left);
      else
      {
      struct node*Q;
         Q=T->right;
        while(Q->left!=NULL)
         Q=Q->left;
       
        T->right=delete_n(T->right,Q->data);
      }      
  }
}   
// display using inorder traversal
void inorder(struct node*t1)
{
    if(t1==NULL)
    return;
    else
    {      inorder(t1->left);
        printf(" %d ",t1->data);
        inorder(t1->right);
    }
}
void main()
{    int y;
	struct node*root=NULL;
    root=insert(52,root);
    root=insert(38,root);
    root=insert(12,root);
    root=insert(18,root);
    root=insert(76,root);
    root=insert(55,root);
    root=insert(34,root);
    root=insert(35,root);
    inorder(root);
     y=findmax(root);
    printf("\n %d",y);
    delete_n(root,38);
    inorder(root);
}//main function
