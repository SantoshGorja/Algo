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
   void inordernon(node<T> *);
   void preordernon(node<T> *);
   void postordernon(node<T> *);

};
template <class t>
class stack
{
   t s[20];
   int top;
   public:
   stack()
   {
     top=-1;
   }
   void push(t x)
   {
     s[++top]=x;
   }
   t pop()
   {
     return s[top--];
   }
   int empty()
   {
     if(top==-1)
      return 1;
     return 0;
   }
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
	 if(t->data > p->data)
	 {
	   if(p->right==NULL)
	   {
		 p->right=t;
		 break;
	   }
	   else
		 p=p->right;
	 }
	else if(t->data<p->data)
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
/*traversals (non recursive)*/
template <class T>
void tree<T>::inordernon(node<T> *p)
{
  stack<node<T>*> stk;

  do
  {
   while(p!=NULL)
   {
      stk.push(p);
      p=p->left;
   }
   if(!stk.empty())
   {
      p=stk.pop();
      cout<<p->data<<" ";
      p=p->right;
   }
   else
     break;
  }while(1);
}
template <class T>
void tree<T>::preordernon(node<T> *p)
{
  stack<node<T> *> stk;
  do
  {
   while(p!=NULL)
   {
      cout<<p->data<<" ";
      stk.push(p);
      p=p->left;
   }
   if(!stk.empty())
   {
      p=stk.pop();
      p=p->right;
   }
   else
     break;
  }while(1);
}
template <class T>
void tree<T>::postordernon(node<T> *p)
{

  stack<node<T> *> stk;
  stack<int> stk1;
  int flag;
  do
  {
   if(p!=NULL)
   {
    stk.push(p);
    stk1.push(1);
    p=p->left;
   }
   else
   {
    if(stk.empty())
      break;
    p=stk.pop();
    flag=stk1.pop();
     if(flag==2)
     {
      cout<<p->data<<" ";
      p=NULL;
     } /*end if */
     else
     {
      stk.push(p);
      stk1.push(2);
      p=p->right;
     } /* end else */
  } /* end if */
 }while(1);/*end do while*/
}
int main()
{
   int choice,n,i;
   tree<int> bst;
   bst.create();
   while(1)
   {
	 cout<<"\n\n1.Inorder\n2.Preorder\n3.Postorder\n4.exit";
	 cout<<"\n\nEnter ur choice";
	 cin>>choice;
	 switch(choice)
	 {
		case 1:cout<<"\nInorder traversal\n";
		       bst.inordernon(bst.root);
		       break;
		case 2:cout<<"\nPreorder traversal\n";
		       bst.preordernon(bst.root);
		       break;
		case 3:cout<<"\nPostorder traversal\n";
		       bst.postordernon(bst.root);
		       break;
		case 4:exit(0);
		default:cout<<"Wrong choice\n\n";
	}
      }
return 0;
}
