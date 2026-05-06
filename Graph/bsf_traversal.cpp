
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void traverse(int start, vector<vector<int>> &adj, vector<bool> &visited) {
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " "; 

        for(int neighbour : adj[node]) {
            if(!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
int main() {
    int vertices = 5;

    vector<vector<int>> adj(vertices);

    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    vector<bool> visited(vertices, false);

    cout << "BFS Traversal: ";
    traverse(0, adj, visited);

    return 0;
}
