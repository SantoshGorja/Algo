//Program to traverse a graph using BFS

#include <iostream>
using namespace std;
template <class T>
class node
{
  public:
  T data;
  node *next;
};

template <class T>
class vertex
{
   public:
   int visit;
   int no;
   node<T> *link;
};


template <class T>
class queue
{
  public:
  node<T> *front,*rear;
  queue()
  {
    rear=NULL;
    front=NULL;
  }
  void qinsert(int num)
  {
    node<T> *temp;

    temp=new node<T>;
    temp->data=num;
    temp->next=NULL;
    if(rear==NULL)
      front=rear=temp;
    else
    {
      rear->next=temp;
      rear=temp;
    }
  }
  int qdelete()
  {
    node<T> *temp;
    int k;

    if(front==NULL)
     return -1;
    k=front->data;
    temp=front;
    front=front->next;
    delete temp;
    return k;
}
};
template <class T>
class graph
{
   int n;
   vertex<T> *v[15];
   public:
   graph()
   {
     n=0;
   }
   void creategraph();
   void bfs(T);
   void init(int s)
   {
     v[s]->visit=1;
   }
};
template <class T>
void graph<T>::creategraph()
{
   int i,j,k;
   node<T> *temp,*p;

   cout<<"Enter the number of vertices\n";
   cin>>n;
   cout<<"Enter the adjacency matrix\n";
   for(i=1;i<=n;i++)
   {
     v[i]=new vertex<T> ;
     v[i]->visit=0;
     v[i]->no=i;
     temp=NULL;

     for(j=1;j<=n;j++)
     {
       cin>>k;
       if(k)
       {
	 p=new node<T>;
	 p->data=j;
	 p->next=NULL;
	 if(temp==NULL)
	   v[i]->link=p;
	 else
	   temp->next=p;
	 temp=p;
       }
     }
   }
}
template <class T>
void graph<T>::bfs(T s)
{
  node<T> *cur;
  queue<int> q;
  int k;
 do
 {
   cur=v[s]->link;
   while(cur)
   {
	 if(v[cur->data]->visit==0)
	 {
		cout<<s<<"---"<<cur->data<<endl;
		q.qinsert(cur->data);
		v[cur->data]->visit=1;
	 }
	 cur=cur->next;
   }
   s=q.qdelete();
   if(s==-1)
	return;
  }while(1);
}
int main()
{
  int stver;
  graph<int> G;
  G.creategraph();
  cout<<"Enter the starting vertex\n";
  cin>>stver;
  cout<<"bfs order of edges \n";
  G.init(stver);
  G.bfs(stver);
  return 0; 
}
