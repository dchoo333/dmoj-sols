#include <bits/stdc++.h>
using namespace std;

struct Line { double m, b; };

double intersection(const Line& a, const Line& b) { return (b.b - a.b) / (a.m - b.m); }
bool cmp(const Line& a, const Line& b) { return a.m == b.m ? a.b < b.b : a.m < b.m; }
bool isBad(const Line& a, const Line& b, const Line& c) { return intersection(a, b) >= intersection(b, c); }

int x[300], y[300];
vector<Line> req[300];

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &x[i]);
    for(int i = 0; i < N; i++) scanf("%d", &y[i]);

    for(int i = 0; i < N; i++) {
        double t = -1e99;
        for(int j = i-1; j >= 0; j--) {
            t = max(t, (double)(y[j] - y[i]) / (x[i] - x[j]));
            req[j].push_back({-t, t * x[i] + y[i]});
        }
        t = -1e99;
        for(int j = i+1; j < N; j++) {
            t = max(t, (double)(y[j] - y[i]) / (x[j] - x[i]));
            req[j-1].push_back({t, y[i] - t * x[i]});
        }
    }

    double ans = 1e99;
    for(int i = 0; i < N-1; i++) {
        double m = (double)(y[i+1] - y[i]) / (x[i+1] - x[i]);
        double b = y[i] - m * x[i];

        for(auto& line : req[i]) { line.m -= m; line.b -= b; }
        sort(req[i].begin(), req[i].end(), cmp);

        vector<Line> hull;
        for(auto& line : req[i]) {
            while(!hull.empty() && hull.back().m == line.m) hull.pop_back();
            while(hull.size() >= 2 && isBad(hull[hull.size()-2], hull.back(), line)) hull.pop_back();
            hull.push_back(line);
        }

        for(int j = 1; j < hull.size(); j++) {
            double xx = intersection(hull[j], hull[j-1]);
            if(xx >= x[i] && xx <= x[i+1]) ans = min(ans, hull[j].m * xx + hull[j].b);
        }

        double mm = 0;
        for(auto& line : hull) mm = max(mm, line.m * x[i] + line.b);
        ans = min(ans, mm);

        mm = 0;
        for(auto& line : hull) mm = max(mm, line.m * x[i+1] + line.b);
        ans = min(ans, mm);
    }

    printf("%.3lf\n", ans);
    return 0;
}