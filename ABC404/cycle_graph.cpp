#include <iostream>
#include <vector>

using namespace std;

int main(){
    int M, N;
    cin >> N;
    cin >> M;
    if (M < N || M > N) {
        cout << "No" << endl;
        return 0;
    }
    vector<Node> list_node(N);
    for (int i = 0; i < N; i++) {
        list_node[i] = Node(i + 1);
    }

    for (int i = 1; i < N; i++) {
        int v1, v2;
        cin >> v1;
        cin >> v2;
        Node node1 = list_node[v1 - 1];
        Node node2 = list_node[v2 - 1];
        node1.neighbors.push_back(&node2);
        node2.neighbors.push_back(&node1);
    }
    
}

struct Node {
    int val;
    vector<Node*> neighbors;
    int visited;

    Node(int value) {
        val = value;
        int visited = 0;
    }
}