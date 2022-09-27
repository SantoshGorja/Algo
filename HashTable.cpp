#include<iostream>
#include<stdlib.h>
using namespace std;
template <class K,class V>
struct pair
	{
	  K key;
	  V value;
	};

template<class K,class V>
class HashTable
{
	int D;   //hash function divisor
	int n;  // number of pairs
	pair<K,V> **ht;
	int *never;
	public:
	HashTable(int divisor);
	void search(K thekey);
	void insert(pair<K,V> p);
	void erase(K thekey);
	void display();
};

template<class K,class V>
HashTable<K,V>::HashTable(int divisor)
{
  n=0;
  D=divisor;

  // allocate and initialize hashtable array

  ht = new pair<K,V>*[D];
  never = new int[D];
  for(int i=0;i<D;i++)
  {
	 ht[i]=NULL;
	 never[i]=1;
  }
}
template<class K,class V>
void HashTable<K,V>::search(K thekey)
{

	 int i,j;

	 i=thekey%D;     //home bucket
	 j=i;

	 do
	 {

		if(never[j])
		{
			cout<<"matching pair not found\n";
			return;
		}
		else
		if(ht[j]!=NULL&&ht[j]->key==thekey)
		{
		  cout<<"matching pair found\n";
		  cout<<j<<"\t"<<ht[j]->key<<"\t"<<ht[j]->value<<endl;
		  return;
		}
		j = (j+1) % D;

	 }while(j!=i);   // returned to home bucket?
	 cout<<"matching pair not found\n";
}

template<class K,class V>
void HashTable<K,V>::insert(pair<K,V> p)
{
  //insert p into dictionary.overwrite existing pair,
  //if any, with same key.
  int i,j;

	 i=p.key%D;     //home bucket
	 j=i;

	 do
	 {

		 if(ht[j]==NULL)
		 {
			 ht[j]=new pair<K,V>(p);
			 never[j]=0;
			 n++;
			 return;
		 }
		 else
		  if(ht[j]->key==p.key)
		 {
			ht[j]->value=p.value; //duplicate
			return;
		 }
		 j = (j+1) % D;
	 }while(i!=j);
		 cout<<"cannot insert table full\n";

  }

template<class K,class V>
void HashTable<K,V>::display()
{
  cout<<"\nbucket\tkey\tvalue\n";
  for(int i=0;i<D;i++)
  {
	if(ht[i]!=NULL)
	 cout<<i<<"\t"<<ht[i]->key<<"\t"<<ht[i]->value<<endl;
	else
	 cout<<i<<endl;
  }
}
template<class K,class V>
void HashTable<K,V>::erase(K thekey)
{
	 int i,j;

	 i=thekey%D;     //home bucket
	 j=i;

 do
  {

	if(never[j])
	{
	  cout<<"\nmatching pair not found\n";
	  return;
	}
	else
	if(ht[j]!=NULL&&ht[j]->key==thekey)
	{
	  ht[j]=NULL;
	  n--;
	  return;
	}
	j = (j+1) % D;
  }while(i!=j);
	cout<<"\nmatching pair not found\n";
}
int main()
{
  HashTable<int,int> H(11);
  pair<int,int> p;
  int k;

  int ch=1;
  while(ch!=5)
	  {
		 cout<<"\n\t\t1.insert\n\t\t2.delete\n\t\t3.find\n\t\t4.display\n\t\t5.exit\n\n";
		 cout<<"Enter ur choice:";
		 cin>>ch;
		 switch(ch)
		 {
			case 1:cout<<"\nenter key & value\n";
					 cin>>p.key>>p.value;
					 
					 H.insert(p);
					 break;
			case 2:cout<<"enter key\n";
					 cin>>k;
					 H.erase(k);
					 break;
			case 3:cout<<"enter key\n";
					 cin>>k;
					 H.search(k);
					 break;
			case 4:H.display();
					 break;
			case 5:exit(0);
		 }
	  }
  return 0;
}

