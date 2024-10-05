#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647
using namespace std;

vector<int> bfs(vector<vector<int>>, vector<int>&, vector<int>&, int);
vector<int> get_path(vector<int>, int);

int main() {
	int vertex_count, edge_count, start;

	cout << "Enter the amount of vertexes: ";
	cin >> vertex_count;
	cout << "Enter the amount of edges: ";
	cin >> edge_count;

	vector<vector<int>> graph(vertex_count);

	for (int i = 0; i < edge_count; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << "Enter start vertex: ";
	cin >> start;

	vector<int> names(graph.size());
	vector<int> from(graph.size(), -1);
	vector<int> distances = bfs(graph, names, from, start);
	
	for (int i : names)
	{
		cout << i << " ";
	}

	cout << endl;

	for (int i :distances)
	{
		if(i != INF){
			cout << i << " ";
		}
		else {
			cout << -1 << " ";
		}
	}

	vector<int> path = get_path(from, 4);

	cout << "------------------------------\nPath\n";

	for (int i : path)
	{
		cout << i << " ";
	}

	return 0;
}

vector<int> bfs(vector<vector<int>> graph, vector<int>& names, vector<int>& from, int start) {
	vector<int> distance(graph.size(), INF);
	queue<int> q;

	distance[start] = 0;
	q.push(start);	

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int to : graph[v]) {
			if (distance[to] > distance[v] + 1) {
				distance[to] = distance[v] + 1;
				names[to] = to;
				from[to] = v;
				q.push(to);
			}
		}
	}

	return distance;
}

vector<int> get_path(vector<int> from, int finish) {
	vector<int> path;
	for (int i = finish; i != -1; i = from[i])
	{
		path.push_back(i);
	}

	reverse(path.begin(), path.end());

	return path;
}

	