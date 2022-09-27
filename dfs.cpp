#include <iostream>
#include <cstdlib>
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
   void dfs(T);
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
       }    }  }}
template <class T>
void graph<T>::dfs(T s)
{
  node<T> *cur;
  int k;
  cur=v[s]->link;
  while(cur)
  {
    if(v[cur->data]->visit==0)
    {
      cout<<s<<"---"<<cur->data<<endl;
      v[cur->data]->visit=1;
      dfs(cur->data);
    }
    cur=cur->next;
  }  return;}

int main()
{
  int stver;
  graph<int> G;
  G.creategraph();
  cout<<"Enter the starting vertex\n";
  cin>>stver;
  cout<<"dfs order of edges \n";
  G.init(stver);      G.dfs(stver);   
return 0;
}
