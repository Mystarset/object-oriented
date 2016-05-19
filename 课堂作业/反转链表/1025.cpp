#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <queue>

using namespace std;
struct Node{
	int num,ad;
	Node *next;
};
int main()
{
   freopen("xx.in","r",stdin);
   freopen("xx.out","w",stdout);
   Node *p = new Node[100005];
   int n,head,k;
   scanf("%d%d%d",&head,&n,&k);
   head = head+1;
   int i;
   int address,data,ne;
   for (i = 1; i <= n; i++)
   {
   	   
   	   scanf("%d%d%d",&address,&data,&ne);
   	   p[address+1].next = &p[ne+1];
   	   p[address+1].num = data;
   	   p[address+1].ad = address;
   	   if (ne+1 == head) head = address+1;
   }
   
   p[0].ad = -1;
   p[0].next = NULL;
   
   int sum = 1;
   Node *s = new Node;
   Node *first = new Node;
   first = &p[head];
   bool pd = false;
   s = &p[head];
   n = 0;
   while (s->next!=NULL)
   {
   	    n++;
   	    s = s->next;
   }
   s = &p[head];
   Node *k1 = new Node;
   Node *k2 = new Node;
   Node *k3 = new Node;
   Node *k4 = new Node;
   k4 = s;
   while (sum <= n)
   {
   	   if (sum + k - 1 <= n)
   	   {

   	   	   k1 = s; 
   	   	   k2 = k1->next;
   	   	   for (i = 1; i <= k-1; i++)
		   {
		       k3 = k2->next;
		       k2->next = k1;
			   
			   k1 = k2;
			   k2 = k3;   
		   }  
		   if (!pd)
		   {
		   	   first = k1;
		   	   pd = true;
		   } 
		   else
		   {
		   	   k4->next = k1;
		   	   k4 = s;
		   } 
		   s->next = k2;
		   s = k2;


   	   }
   	   sum += k;
   }
 
  
   while (first->next!=NULL)
   {
   	    if (first->next->ad == -1) 
		   printf("%05d %d -1",first->ad,first->num);
   	    else
		   printf("%05d %d %05d\n",first->ad,first->num,first->next->ad);
   	    first = first->next;  
   }
   //delete k1;
   //delete k2;
   //delete k3;
   //delete s;
   //delete first;
   //delete []p;
   return 0;
}


