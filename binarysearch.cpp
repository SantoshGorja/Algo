#include <iostream>
#include <cstdlib>
using namespace std;
template <class T>
class node
{
  public:
    node<T> *left;
    T data;
    node<T> *right;
};
template <class T>
class tree
{
	public:
	node<T> *root;

	tree()
	{
	  root=NULL;
	}
	void create();
	void insert(T);
	void del(T);
	int search(T);
	void inorder(node<T> *);
};
template <class T>
void tree<T>::create()
{
	int n;

	if(root==NULL)
	  root=new node<T> ;
	cout<<"Enter data,at end enter -9999\n";
	cin>>n;
	if(n==-9999)
	{
	cout<<"cannot create tree\n";
	exit(1);
	}
	root->data=n;
	root->left=root->right=NULL;
	while(1)
	{
	 cin>>n;
	 if(n==-9999)
		break;
	 insert(n);
   }
}
template <class T>
void tree<T>::insert(T n)
{
   node<T> *t,*p;

   t=new node<T>;
   t->data=n;
   t->left=t->right=NULL;
   p=root;

   while(p!=NULL)
   {
	 if(t->data>p->data)
	 {
	   if(p->right==NULL)
	   {
		 p->right=t;
		 break;
	   }
	   else
		 p=p->right;
	}
	else
	 if(t->data<p->data)
	 {
	   if(p->left==NULL)
	   {
		 p->left=t;
		   break;
	   }
	   else
	    p=p->left;
	 }
	 else
	 {
	   cout<<"Cannot insert";
	   break;
	 }
   }/*while*/
}

/*traversals (recursive)*/
template <class T>
void tree<T>::inorder(node<T> *p)
{
   if(p!=NULL)
   {
	 inorder(p->left);
	 cout<<p->data<<" ";
	 inorder(p->right);
   }
}
template <class T>
int tree<T>::search(T n)
{
  node<T> *p;

  p=root;
  while(p!=NULL)
  {
	 if(n>p->data)
	   p=p->right;
	 else
	   if(n<p->data)
		 p=p->left;
	   else
	 return(1);
  }
  return(0);
}
/*Deletion in a BST*/
template <class T>
void tree<T>::del(T n)
{
   node<T> *par,*l,*p;

   p=root;
   par=NULL;
   while(p!=NULL)
   {
	 if(n>p->data)
	 {
	   par=p;
	   p=p->right;
	 }
	 else
	   if(n<p->data)
	   {
		 par=p;
		 p=p->left;
	   }
	   else
		 break;
   }/*while*/
   if(p==NULL)
   {
	 cout<<"No such node";
	 return;
   }
   if(p->left==NULL)  /*no left child*/
   {
	 if(par->left==p)
	   par->left=p->right;
	 else
	   par->right=p->right;
   }
   else
	 if(p->right==NULL)  /*no right child*/
	 {
		if(par->left==p)
		  par->left=p->left;
		else
		  par->right=p->left;
	 }
	 else            /*both children present*/
	 {
		for(l=p->right;l->left!=NULL;l=l->left);
		if(par->left==p)
		{
		  l->left=p->left;
		  par->left=p->right;
		}
		else
		{
		  l->left=p->left;
		  par->right=p->right;
		}
	 }
	 if(p==root) /*node to be deleted is root node*/
		if(p->right!=NULL)
		  root=p->right;
		else
        root=p->left; 
	 delete p;
}/*delete*/

int main()
{
   int choice,n,i;
   tree<int> bst;
   bst.create();
   while(1)
   {
	 cout<<"\n1.insert\n2.delete\n3.search\n4.inorder\n5.exit";
	 cout<<"\nEnter ur choice";
	 cin>>choice;
	 switch(choice)
	 {
		case 1:cout<<"enter data:";
		       cin>>n;
		       bst.insert(n);
		       break;
		case 2:cout<<"which element to b deleted?";
		       cin>>n;
		       bst.del(n);
		       break;
		case 3:cout<<"Enter element to b searched";
		       cin>>n;
		if(bst.search(n))
			  cout<<"found\n"<<n;
		       else
			  cout<<"Not found";
		       break;
		case 4:cout<<"Inorder traversal\n";
		       bst.inorder(bst.root);
		       break;
		case 5:exit(0);
	}   
   }
return 0;
}

