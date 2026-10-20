#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    map<int, vector<tuple<int,int,int>>> rev_adj; // rev_adj[to] = {from, depart, arrive}
    
    int val;
    while(cin >> val && val != -1){
        int bt = val * 60;
        int et; cin >> et; et *= 60;
        int nss; cin >> nss;
        vector<int> stops(nss);
        for(int i = 0; i < nss; i++) cin >> stops[i];
        vector<int> intervals(nss-1);
        for(int i = 0; i < nss-1; i++) cin >> intervals[i];
        
        int half_trip = 0;
        for(int x : intervals) half_trip += x;
        int full_trip = 2 * half_trip;
        
        for(int start = bt; start < et; start += full_trip){
            int cur = start;
            for(int i = 0; i < nss-1; i++){
                int arr = cur + intervals[i];
                if(arr <= et){
                    rev_adj[stops[i+1]].push_back({stops[i], cur, arr});
                }
                cur += intervals[i];
            }
            cur = start + half_trip;
            for(int i = nss-2; i >= 0; i--){
                int arr = cur + intervals[i];
                if(arr <= et){
                    rev_adj[stops[i]].push_back({stops[i+1], cur, arr});
                }
                cur += intervals[i];
            }
        }
    }
    
    int src;
    while(cin >> src && src != -1){
        int dst, hour, minute;
        cin >> dst >> hour >> minute;
        int deadline = hour * 60 + minute;
        
        map<int,int> latest;
        priority_queue<pair<int,int>> pq;
        latest[dst] = deadline;
        pq.push({deadline, dst});
        
        while(!pq.empty()){
            auto [t, stop] = pq.top(); pq.pop();
            if(latest.count(stop) && t < latest[stop]) continue;
            
            if(!rev_adj.count(stop)) continue;
            for(auto& [from, dep, arr] : rev_adj[stop]){
                if(arr <= t){
                    if(!latest.count(from) || dep > latest[from]){
                        latest[from] = dep;
                        pq.push({dep, from});
                    }
                }
            }
        }
        
        if(!latest.count(src)){
            cout << "-1\n";
        } else {
            int t = latest[src];
            cout << (t/60 < 10 ? "0" : "") << t/60 << ":"
                 << (t%60 < 10 ? "0" : "") << t%60 << "\n";
        }
    }
    
    return 0;
}
