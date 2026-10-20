"""
#include <bits/stdc++.h>
using namespace std;
const int Mx=100,K=Mx*(Mx+1)/2;
static unsigned short G[K][K];
inline int id(int A,int a){return A*(A+1)/2+a;}
int st[4096],sc=0;
int main(){
 for(int A=0;A<Mx;A++)for(int C=0;C<Mx;C++)for(int a=0;a<=A;a++)for(int c=0;c<=C;c++){
  int b=A-a,d=C-c; sc++;
  int r=id(A,a),q=id(C,c);
  for(int x=0;x<a;x++) st[G[id(x+b,x)][q]]=sc;
  for(int x=0;x<b;x++) st[G[id(a+x,a)][q]]=sc;
  for(int x=0;x<c;x++) st[G[r][id(x+d,x)]]=sc;
  for(int x=0;x<d;x++) st[G[r][id(c+x,c)]]=sc;
  for(int X=1;X<=a;X++) st[G[id(A,a-X)][q]]=sc;
  for(int X=1;X<=c;X++) st[G[r][id(C,c-X)]]=sc;
  for(int X=1;X<=min(a,c);X++) st[G[id(A,a-X)][id(C,c-X)]]=sc;
  int m=0; while(st[m]==sc) m++; G[r][q]=m;
 }
 for(int s=1;s<=Mx;s++){int i=id(s-1,s-1); printf("%d,",G[i][i]);} puts("");
}
"""

import sys
G = [0,0,1,2,2,7,3,5,4,5,10,9,9,15,5,12,14,17,15,17,17,23,24,27,22,34,18,28,41,29,21,34,33,41,26,55,30,42,35,39,34,56,65,39,41,47,45,43,40,40,29,44,58,56,52,57,55,54,55,48,61,60,60,58,44,67,67,64,64,37,66,64,74,70,72,47,66,75,74,73,90,81,79,80,78,81,87,95,95,83,124,92,93,86,67,91,97,88,97,100,103]

D = sys.stdin.buffer.read().split()
n, m = int(D[0]), int(D[1])
c = [0] * 101
for t in D[2:2 + n]: c[int(t)] ^= 1

x = 0
for s in range(1, 101):
    if c[s]: x ^= G[s]

a = -1
for s in range(1, m + 1):
    if G[s] == x: a = s; break
print(a)