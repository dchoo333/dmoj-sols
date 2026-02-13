#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

double n;
std::vector<int> v;
std::unordered_map<long long, bool> m;

void func(int k, double a, double b){
    if(!k){
        int l = std::ceil(a), r = std::floor(b);
        for(int i = l; i <= r; i++) v.push_back(i);
        return;
    }
    double d = (b - a) / 3.0;
    func(k - 1, a, a + d);
    func(k - 1, a + 2.0 * d, b);
}

bool g(long long x){
    if(x * 3 > n && x * 3 < 2 * n) return false;
    long long y;
    if(x * 3 <= n) y = x * 3;
    else y = x * 3 - 2 * n;
    if(m[y]) return true;
    m[y] = true;
    return g(y);
}

int main(){
    std::cin >> n;
    func(19, 0.0, n);
    for(int x : v){
        if(g(x)) std::cout << x << '\n';
        m.clear();
    }
}
