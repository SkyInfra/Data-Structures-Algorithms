
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
