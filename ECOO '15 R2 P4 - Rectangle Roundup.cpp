#include <stdio.h>
#include <set>

int n;
int sz,done;
int s1[15],s2[15];

std::set<int> got[15];
std::set<int> single;

int main()
{
    got[0].insert(0);
    got[1].insert(0);
    for (int i=0; i<10; i++) {
        sz=done=0;
        scanf("%d",&n);
        for (int i=2; i<n+2; i++) {
            scanf("%d%d",s1+i,s2+i);
            sz+=s1[i]*s2[i];
        }
        for (int p1=1; p1*p1<=sz && !done; p1++) {
            if (sz%p1) continue;
            int p2=sz/p1;
            // p1 by p2
            for (int i=2; i<n+2; i++) {
                // get all placements
                single.clear();
                for (int j=0; j+s1[i]<=p1; j++)
                for (int k=0; k+s2[i]<=p2; k++) {
                    int mask=0;
                    for (int jj=j; jj<j+s1[i]; jj++)
                    for (int kk=k; kk<k+s2[i]; kk++) {
                        mask|=(1<<(jj*p2+kk));
                    }
                    single.insert(mask);
                }
                for (int j=0; j+s2[i]<=p1; j++)
                for (int k=0; k+s1[i]<=p2; k++) {
                    int mask=0;
                    for (int jj=j; jj<j+s2[i]; jj++)
                    for (int kk=k; kk<k+s1[i]; kk++) {
                        mask|=(1<<(jj*p2+kk));
                    }
                    single.insert(mask);
                }
                got[i].clear();
                for (int m1:got[i-2]) {
                    for (int m2:single) {
                        if (m1&m2) continue;
                        got[i].insert(m1|m2);
                    }
                }
            }
            int cover=(1<<sz)-1;
            for (int i:got[n]) {
                if (got[n+1].count(i^cover)) {
                    printf("%d\n",(p1+p2)*2);
                    done=1;
                    break;
                }
            }
        }
        if (!done) printf("Not Possible\n");
    }
}
