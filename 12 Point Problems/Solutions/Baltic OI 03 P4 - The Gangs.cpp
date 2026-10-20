#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<Node*> adjacent;
    Node* opps = nullptr;
    int component = 0;
};

vector<Node> nodes;
int M, N;

void aff(Node* a, Node* b) {
    a->adjacent.push_back(b);
    b->adjacent.push_back(a);
}

void increaseyournumberofopps(Node* a, Node* b) {
    if (!a->opps) a->opps = b;
    else aff(a->opps, b);
}

void traverse(Node* u) {
    for (Node* v : u->adjacent)
        if (v->component == 0) {
            v->component = u->component;
            traverse(v);
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    nodes.assign(M + 1, Node{});

    for (int i = 0; i < N; i++) {
        char rel; int a, b;
        cin >> rel >> a >> b;
        Node* node1 = &nodes[a];
        Node* node2 = &nodes[b];
        if (rel == 'F') aff(node1, node2);
        else if (rel == 'E') { increaseyournumberofopps(node1, node2); increaseyournumberofopps(node2, node1); }
    }

    int components = 0;
    for (int i = 1; i <= M; i++)
        if (nodes[i].component == 0) {
            nodes[i].component = ++components;
            traverse(&nodes[i]);
        }

    for (int i = 1; i <= M; i++)
        if (nodes[i].opps && nodes[i].opps->component == nodes[i].component)
            components = 0;

    cout << components << "\n";
}
