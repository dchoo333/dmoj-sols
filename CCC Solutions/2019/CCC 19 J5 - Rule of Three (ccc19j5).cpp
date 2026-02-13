#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define MAX 64
#define lk 'A'
#define lh 'B'

struct S{
	size_t n;
	bitset<MAX> b;

	S()=default;
	S(const string& s):n(size(s)),b(s,0,n,lk,lh){}
	
	auto t()const->string{
		return b.to_string(lk,lh).substr(size(b)-n);
	}

	void r(const S& x,size_t i,size_t l){
		int g=int(x.n-l);
		if(g>0){
			b<<=g;
			for(size_t j=0;j<i;++j)
				b[j]=b[j+g];
		}
		else if(g<0){
			for(size_t j=i-1;j+1>0;--j)
				b[j-g]=b[j];
			b>>=-g;
		}
		for(size_t j=i;j<i+x.n;++j)
			b[j]=x.b[j-i];
		n+=g;
	}

	auto f(const S& s)const->vector<size_t>{
		vector<size_t> a;
		size_t m=s.n;

		vector<int> l(m);
		for(size_t i=1;i<m;++i){
			size_t j=l[i-1];
			while(j>0&&s.b[i]!=s.b[j])
				j=l[j-1];
			if(s.b[i]==s.b[j])
				++j;
			l[i]=int(j);
		}

		for(size_t i=0,j=0;i<n;){
			if(s.b[j]==b[i])
				++i,++j;
			if(j==m){
				a.push_back(i-j);
				j=l[j-1];
			}
			else if(i<n&&s.b[j]!=b[i]){
				if(j)
					j=l[j-1];
				else
					++i;
			}
		}
		return a;
	}

	bool operator==(const S& o)const{
		return b==o.b&&n==o.n;
	}
};

struct H{
	size_t operator()(const S& s)const{
		return hash<bitset<MAX>>()(s.b)^hash<size_t>()(s.n);
	}
};

struct U{
	size_t r,p;
	S s;
};

struct R{
	S f,t;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	array<R,3> a;
	for(auto&[f,t]:a){
		string x,y;
		cin>>x>>y;
		f=x,t=y;
	}

	int N;
	string x,y;
	cin>>N>>x>>y;
	S A(x),B(y);
	
	auto h=[&](auto& q,const S& s,bool d){
		size_t n=size(q);
		q[0].emplace(s,U(0,0,S("")));
		for(size_t i=1;i<n;++i)
			for(auto&[c,_]:q[i-1])
				for(size_t r=1;r<=size(a);++r){
					auto&[f,t]=a[r-1];
					if(!d)swap(f,t);
					for(size_t p:c.f(f)){
						S nx=c;
						nx.r(t,p,f.n);
						q[i].emplace(nx,U(r,c.n-f.n-p+1,c));
					}
					if(!d)swap(f,t);
				}
	};

	vector<unordered_map<S,U,H>> q1(N/2+1),q2(N-N/2+1);
	h(q1,A,true);
	h(q2,B,false);

	for(auto&[m,_]:q1.back())
		if(q2.back().contains(m)){
			vector<U> v;
			S c=m;
			for(auto& x:q1|views::drop(1)|views::reverse){
				auto& nx=x.find(c)->second;
				v.emplace_back(nx.r,nx.p,c);
				c=nx.s;
			}
			for(auto&[r,p,s]:v|views::reverse)
				cout<<r<<" "<<p<<" "<<s.t()<<"\n";
			c=m;
			for(auto& x:q2|views::drop(1)|views::reverse){
				auto&[r,p,s]=x.find(c)->second;
				cout<<r<<" "<<p<<" "<<s.t()<<"\n";
				c=s;
			}
			return 0;
		}
	assert(false);
}
