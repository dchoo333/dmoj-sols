#include <stdio.h>
#include <math.h>

#define A 2000
#define B 1000

struct T{long x,y;int m;};

int n;
struct T t[A];
long e[A+1];
double ar;
double ta[B+1];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%ld %ld %d",&t[i].x,&t[i].y,&t[i].m);

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(t[i].y>t[j].y){
                struct T z=t[i];
                t[i]=t[j];
                t[j]=z;
            }

    for(int i=0;i<n;i++) e[i]=t[i].x;
    e[n]=100000000;

    for(int i=0;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(e[i]>e[j]){
                long z=e[i];
                e[i]=e[j];
                e[j]=z;
            }

    for(long i=0;i<=B;i++)
        ta[i]=(double)(i*i)/2.0;

    ar=0;

    for(int i=1;i<=n;i++){
        if(e[i]>e[i-1]){
            long px=e[i-1],py=0;
            for(int j=0;j<n;j++){
                if(t[j].x<=e[i-1] && t[j].x+t[j].m>e[i-1]){
                    if(px>e[i-1]){
                        px-=t[j].y-py;
                        py=t[j].y;
                    }
                    if(t[j].x+t[j].m>px){
                        long x1=e[i-1],x2=e[i],x3=t[j].x+t[j].m;
                        double add=0;
                        if(x3<=x2) add=ta[x3-x1];
                        else add=ta[x3-x1]-ta[x3-x2];
                        ar+=add;
                        if(px>e[i-1]){
                            double sub=0;
                            if(px<=x2) sub=ta[px-x1];
                            else sub=ta[px-x1]-ta[px-x2];
                            ar-=sub;
                        }
                        px=t[j].x+t[j].m;
                        py=t[j].y;
                    }
                }
            }
        }
    }

    printf("%.1f\n",ar);

    return 0;
}