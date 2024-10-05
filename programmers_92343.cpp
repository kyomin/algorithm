#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Node;
vector<int> Graph[17];	// 2 <= info length <= 17
bool Visited[17][18][18];	// [node][sheep][wolf]
int MaxS;

void dfs(int pos, int s, int w) {
	if (Visited[pos][s][w]) return;

	Visited[pos][s][w] = true;

	int backupS = s;
	int backupW = w;
	int backupNode = Node[pos];

	if (Node[pos] == 0)
		++s;
	else if(Node[pos] == 1)
		++w;

	// Clear Node
	Node[pos] = -1;

	// Search Next Node
	if (w < s) {
		MaxS = max(MaxS, s);

		for (int next : Graph[pos]) 
			dfs(next, s, w);		
	}

	// Restore Node
	Node[pos] = backupNode;
	Visited[pos][backupS][backupW] = false;
}

int solution(vector<int> info, vector<vector<int>> edges) {
	// Initialization
	Node = info;

	for (int i = 0; i < Node.size(); i++)
		Graph[i].clear();
	
	for (auto edge : edges) {
		Graph[edge[0]].push_back(edge[1]);
		Graph[edge[1]].push_back(edge[0]);
	}

	memset(Visited, sizeof(Visited), 0);
	MaxS = 0;

	// Start Search
	dfs(0, 0, 0);

	return MaxS;
}