#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long u;
u hs(u x){x+=0x9e3779b97f4a7c15ULL;x=(x^x>>30)*0xbf58476d1ce4e5b9ULL;x=(x^x>>27)*0x94d049bb133111ebULL;return x^x>>31;}
struct T{
	vector<u> k;vector<int> v;size_t c=0;
	T(size_t n=512){size_t s=1024;while(s<n*2)s<<=1;k.assign(s,0);v.resize(s);}
	size_t f(u x){size_t m=k.size()-1,i=hs(x)&m;while(k[i]&&k[i]!=x)i=i+1&m;return i;}
	void g(){vector<u> a(k.size()*2);vector<int> b(a.size());swap(a,k);swap(b,v);for(size_t i=0;i<a.size();i++)if(a[i]){size_t j=f(a[i]);k[j]=a[i];v[j]=b[i];}}
	bool ad(u x,int d){if(2*(c+1)>k.size())g();size_t i=f(x);if(k[i])return 0;k[i]=x;v[i]=d;c++;return 1;}
	int gt(u x){size_t i=f(x);return k[i]?v[i]:-1;}
};
struct L{vector<u> s;vector<int> p;vector<char> r,q;};
int S,pn[3],tn[3],dA[3],dB[3],IA,IB,FA,FB;u pb[3],tb[3];
bool rc[16][151][151];
int ln(u v){return 63-__builtin_clzll(v);}
u en(const string&s){u v=0;for(size_t i=0;i<s.size();i++)if(s[i]=='B')v|=1ULL<<i;return v;}
string ds(u v){int n=ln(v);string s(n,'A');for(int i=0;i<n;i++)if(v>>i&1)s[i]='B';return s;}
template<class G> bool gn(u v,bool w,int d,G fn){
	int n=ln(v),nb=__builtin_popcountll(v)-1,na=n-nb,s=w?1:-1;
	for(int j=0;j<3;j++){
		int a2=na+s*dA[j],b2=nb+s*dB[j];
		if(a2+b2>62)continue;
		if(d>=0){
			int ea,eb,r=S-d;
			if(w)ea=FA-a2,eb=FB-b2;else ea=a2-IA,eb=b2-IB;
			if(abs(ea)>75||abs(eb)>75||!rc[r][ea+75][eb+75])continue;
		}
		u P=w?pb[j]:tb[j],R=w?tb[j]:pb[j];
		int m=w?pn[j]:tn[j],o=w?tn[j]:pn[j];
		u k=(1ULL<<m)-1;
		for(int i=0;i+m<=n;i++)if((v>>i&k)==P){
			u y=(v&((1ULL<<i)-1))|R<<i|(v>>(i+m))<<(i+o);
			if(fn(y,j,i))return 1;
		}
	}
	return 0;
}
void ex(L&a,L&b,bool w,int d){
	T t(a.s.size()*2);
	for(int x=0;x<(int)a.s.size();x++)
		gn(a.s[x],w,d,[&](u y,int j,int i){
			if(t.ad(y,0)){b.s.push_back(y);b.p.push_back(x);b.r.push_back(j+1);b.q.push_back(i);}
			return false;
		});
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	string x,y;
	for(int j=0;j<3;j++){
		cin>>x>>y;
		pb[j]=en(x);pn[j]=x.size();tb[j]=en(y);tn[j]=y.size();
		int xb=count(x.begin(),x.end(),'B'),yb=count(y.begin(),y.end(),'B');
		dB[j]=yb-xb;dA[j]=(tn[j]-yb)-(pn[j]-xb);
	}
	cin>>S>>x>>y;
	IB=count(x.begin(),x.end(),'B');IA=x.size()-IB;
	FB=count(y.begin(),y.end(),'B');FA=y.size()-FB;
	rc[0][75][75]=1;
	for(int r=0;r<S;r++)for(int a=0;a<151;a++)for(int b=0;b<151;b++)if(rc[r][a][b])
		for(int j=0;j<3;j++){
			int a2=a+dA[j],b2=b+dB[j];
			if(a2>=0&&a2<151&&b2>=0&&b2<151)rc[r+1][a2][b2]=1;
		}
	vector<L> F(1),B(1);
	F[0].s={en(x)|1ULL<<x.size()};F[0].p={-1};F[0].r={0};F[0].q={0};
	B[0].s={en(y)|1ULL<<y.size()};B[0].p={-1};B[0].r={0};B[0].q={0};
	int a=0,b=0;
	while(a+b<S-1){
		if(F[a].s.size()<=B[b].s.size()){F.emplace_back();ex(F[a],F[a+1],1,a+1);a++;}
		else{B.emplace_back();ex(B[b],B[b+1],0,b+1);b++;}
	}
	bool g0=F[a].s.size()<=B[b].s.size();
	L&X=g0?B[b]:F[a],&G=g0?F[a]:B[b];
	T t(X.s.size());
	for(int i=0;i<(int)X.s.size();i++)t.ad(X.s[i],i);
	int gi=-1,ti=-1,rj=0,ri=0;u ry=0;
	for(int z=0;z<(int)G.s.size();z++)
		if(gn(G.s[z],g0,-1,[&](u v,int j,int i){
			int h=t.gt(v);
			if(h<0)return false;
			gi=z;ti=h;rj=j;ri=i;ry=v;
			return true;
		}))break;
	int fi=g0?gi:ti,bi=g0?ti:gi;
	string md=to_string(rj+1)+" "+to_string(ri+1)+" "+ds(g0?ry:B[b].s[gi])+"\n";
	vector<string> v;
	int i=fi;
	for(int d=a;d>0;d--){
		v.push_back(to_string(F[d].r[i])+" "+to_string(F[d].q[i]+1)+" "+ds(F[d].s[i])+"\n");
		i=F[d].p[i];
	}
	string o;
	for(int k=v.size()-1;k>=0;k--)o+=v[k];
	o+=md;
	i=bi;
	for(int d=b;d>0;d--){
		int p=B[d].p[i];
		o+=to_string(B[d].r[i])+" "+to_string(B[d].q[i]+1)+" "+ds(B[d-1].s[p])+"\n";
		i=p;
	}
	cout<<o;
}
