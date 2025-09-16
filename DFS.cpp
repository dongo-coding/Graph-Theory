#include<stdio.h> 
#define SIZE 100 
 
int A[SIZE][SIZE]; 
int n; 
int DaXet[SIZE]={0}; 
 
void DocDoThi(); 
void DFS(int u); 
int LayPT(int Q[], int &nQ); 
int CheckDS(int Q[], int nQ, int v); 
void DuyetDoThi(); 
 
int main() 
{ 
  DocDoThi(); 
  DuyetDoThi(); 
  return 0; 
} 
 
void DocDoThi() 
{ 
  FILE* f = fopen("C5_input.txt","rt"); 
  if (f==NULL) 
  { 
    printf("Khong mo duoc file\n"); 
    return; 
  } 
  fscanf(f,"%d",&n); 
  for (int i=0; i<n; i++) 
    for (int j=0; j<n; j++) 
      fscanf(f,"%d",&A[i][j]); 
  fclose(f); 
} 
 
void DFS(int u) 
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
 
      if (A[u][v]>0 && DaXet[v]==0 && ((CheckDS(Q,nQ,v)==0))) 
      { 
        DaXet[v]=1; 
        Q[nQ++]=v; 
      } 
  } 
} 
 
int LayPT(int Q[], int &nQ) 
{ 
  int kq=Q[nQ-1]; 
  nQ--; 
  return kq; 
} 
 
int CheckDS(int Q[], int nQ, int v) 
{ 
  for (int i=0; i<nQ; i++) 
    if (Q[i]==v) 
      return 1; 
  return 0; 
} 
 
void DuyetDoThi() 
{ 
  int i; 
  for (i=0; i<n; i++) 
    DaXet[i]=0; 
  for ( i=0; i<n; i++) 
    if (DaXet[i]==0) 
    { 
      DFS(i); 
    } 
} //duyệt sâu
