#include <iostream>
#include <iomanip>
using namespace std;
int rootxloc=40,rootyloc=5,ygap=4;
struct node
{
	int data;
	int bal;
	struct node *left;
	struct node *right;
};
class AVLtree
{
	node *root;

	void LeftRotate(node* &);
	void RightRotate(node* &);
	int ins(node* &,int);
	int del(node* &,int);


	public:
	AVLtree()
	{
	  root = NULL;
	}
	void insert(int x)
	{
	  ins(root,x);
	}
	void delet(int x)
	{
	  del(root,x);
	}

	void draw(){ drawtree(root,rootxloc,rootyloc,ygap,ygap);}
	void drawtree(node *,int,int,int,int);
};

void AVLtree::LeftRotate(node* &p)
{
  node *q=p;

  p=p->right;
  q->right=p->left;
  p->left=q;

  q->bal--;
  if(p->bal >0)
	q->bal=q->bal-p->bal;

  p->bal--;
  if(q->bal <0)
	p->bal=p->bal+q->bal;

}
void AVLtree::RightRotate(node* &p)
{
  node *q=p;

  p=p->left;
  q->left=p->right;
  p->right=q;

  q->bal++;
  if(p->bal <0)
	q->bal=q->bal-p->bal;

  p->bal++;
  if(q->bal >0)
	p->bal=p->bal+q->bal;

}
int AVLtree::ins(node* &p,int x)
{
	int deltah=0;

	if(p==NULL)
	{
	  p=new node;
	  p->data=x;
	  p->bal=0;
	  p->left=p->right=NULL;
	  deltah=1;           //height of tree increased by 1
	}
	else if(x>p->data)
	  {
		 if(ins(p->right,x))
		 {
			p->bal++;      //height og right subtree increased
			if(p->bal==1)
			  deltah=1;
			else if(p->bal==2)
				  {
					 if(p->right->bal==-1)
						RightRotate(p->right);
					 LeftRotate(p);
				  }

		 }
	  }
	  else if(x<p->data)
	  {
		 if(ins(p->left,x))
		 {
			p->bal--;          //height of left subtree increased
			if(p->bal==-1)
			  deltah=1;
			else if(p->bal==-2)
				  {
					 if(p->left->bal==1)
						LeftRotate(p->left);
					 RightRotate(p);
				  }

		 }
	  }
	return deltah;
}

void AVLtree::drawtree(node *p,int xloc,int yloc,int xgap,int ygap)
{

  //goto xy(xloc,yloc);
  cout<<p->data;
  if(p->left!=NULL)
	drawtree(p->left,xloc-xgap,yloc+ygap,xgap/2,ygap);
  if(p->right!=NULL)
	drawtree(p->right,xloc+xgap,yloc+ygap,xgap/2,ygap);


}
int AVLtree::del(node* &p,int x)
{
  node **qq,*p0;
  int deltah=0;
  if(p==NULL) return 0;
  if(x<p->data)
  {
	  if(del(p->left,x))
	  {
		 p->bal++;          //height of left subtree decreased
		 if(p->bal==0)
			 deltah=1;
		 else if(p->bal==2)
				{
				  if(p->right->bal==-1)
					 RightRotate(p->right);
				  LeftRotate(p);
				  if(p->bal==0)
					 deltah=1;
				}

	  }
  }
  else if(x>p->data)
  {
	  if(del(p->right,x))
	  {
		 p->bal--;          //height of right subtree decreased
		 if(p->bal==0)
			 deltah=1;
		 else if(p->bal==-2)
				{
				  if(p->left->bal==1)
					 LeftRotate(p->left);
				  RightRotate(p);
				  if(p->bal==0)
					 deltah=1;
				}

	  }
  }
  else
  {
	  if(p->right==NULL)
	  {
		 p0=p;
		 p=p->left;
		 delete p0;
		 return 1;
	  }
	  else if(p->left==NULL)
			 {
				 p0=p;
				 p=p->right;
				 delete p0;
				 return 1;
			 }
			 else
			 {
				 qq=&p->left;
				 while((*qq)->right!=NULL)
					qq=&(*qq)->right;
				 p->data=(*qq)->data;
				 (*qq)->data=x;
				 if(del(p->left,x))
				 {
					p->bal++;    //height of left subtree decreased
					if(p->bal==0)
					  deltah=1;
					else if(p->bal==2)
						  {
							  if(p->right->bal==-1)
								 RightRotate(p->right);
							  LeftRotate(p);
							  if(p->bal==0)
								 deltah=1;
						  }
				 }
			 }

  }
  return deltah;
}

int main()
{
  AVLtree t;
  int n,choice;

  while(1)
	{
	 cout<<"\n1.insert\n2.delete\n3.exit";
	 cout<<"\nEnter ur choice";
	 cin>>choice;
	 switch(choice)
	 {
		case 1:cout<<"enter data:";
				 cin>>n;
				 t.insert(n);
				 t.draw();
				 break;
		case 2:cout<<"which element to b deleted?";
				 cin>>n;
				 t.delet(n);
				 t.draw();
				 break;
		//case 3: exit(0);break;
		default:cout<<"Wrong choice\n";
	}
   cout<<"\n press any key\n";

 }
 return 0;
}
