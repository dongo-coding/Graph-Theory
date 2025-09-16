#include<stdio.h> 
#define SIZE 100 
 
int A[SIZE][SIZE]; 
int n; 
int DaXet[SIZE]={0}; 
 
void DocDoThi(); 
void BFS(int u); 
int LayPT(int Q[], int &nQ); 
void DuyetDoThi(); 
 
int main() 
{ 
  DocDoThi(); 
  DuyetDoThi(); 
  return 1; 
} 
 
void DocDoThi() 
{ 
  int i,j; 
  FILE* f = fopen("C5_input.txt","rt"); 
  if (f==NULL) 
  { 
    printf("Khong mo duoc file\n"); 
    return; 
  } 
  fscanf(f,"%d",&n); 
  for (i=0; i<n; i++) 
Số trang: 2 
 
    for (j=0; j<n; j++) 
      fscanf(f,"%d",&A[i][j]); 
  fclose(f); 
} 
 
void BFS(int u) 
{ 
  int Q[SIZE]={0}; 
  int nQ=0; 
  Q[nQ++]=u; 
  DaXet[u]=1; 
  while (nQ>0) 
  { 
    u = LayPT(Q,nQ); 
    printf("%d ",u); 
    for (int v=0; v<n; v++) 
      if (A[u][v]>0 && DaXet[v]==0) 
      { 
        DaXet[v]=1; 
        Q[nQ++]=v; 
      } 
  } 
} 
 
int LayPT(int Q[], int &nQ) 
{ 
  int kq=Q[0]; 
  for (int i=1; i<nQ; i++) 
    Q[i-1]=Q[i]; 
  nQ--; 
  return kq; 
} 
 
void DuyetDoThi() 
{ 
  int i; 
  for (i=0; i<n; i++) 
    DaXet[i]=0; 
  for ( i=0; i<n; i++) 
    if (DaXet[i]==0) 
    { 
      BFS(i); 
    } 
}  //duyệt rộng, lưu trữ bằng ma trận kề

-------------------------------------------------------------------------------------------------------------------------------------------
#include <conio.h>       
#include <string.h>      
#include <math.h>        
#include<iostream>  
#include <cstdio> 
#include <list>  
 
using namespace std;  
 
class Graph  
{  
    int V;     
    list<int> *adj;     
public:  
    Graph(int V);   
    void addEdge(int v, int w);   
    void BFS(int s);    
};  
   
Graph::Graph(int V)  
{  
    this->V = V;  
    adj = new list<int>[V];  
}  
   
void Graph::addEdge(int v, int w)  
{  
    adj[v].push_back(w);  
}  
   
void Graph::BFS(int s)  
{  
    bool *visited = new bool[V];  
    for(int i = 0; i < V; i++)  
        visited[i] = false;  
    list<int> queue;  
    visited[s] = true;  
    queue.push_back(s);  
    list<int>::iterator i;  
    while(!queue.empty())  
    {  
        s = queue.front();  
        cout << s << " ";  
        queue.pop_front();  
        for (i = adj[s].begin(); i != adj[s].end(); ++i)  
        {  
            if (!visited[*i])  
            {  
 
                visited[*i] = true;  
                queue.push_back(*i);  
            }  
        }  
    }  
}  
int main()  
{  
    FILE* fp; 
    fp = fopen("C5_input.txt","rt"); 
    if (fp == NULL) 
    { 
        cout << "ko mo duoc tap tin!\n"; 
        return -1; 
    } 
    int nV, nE, b, a; 
    fscanf(fp, "%d %d", &nV, &nE); 
    Graph g(nV); 
    for (int i = 0; i < nE; i++) 
    { 
        fscanf(fp, "%d %d", &a,&b); 
        g.addEdge(a, b); 
        g.addEdge(b, a); 
    } 
    fclose(fp); 
    cout << "Breadth First Traversal, starting from vertex 0 \n";  
    g.BFS(0);  
    return 0;  
} //duyệt rộng, lưu trữ bằng danh sách cạnh

