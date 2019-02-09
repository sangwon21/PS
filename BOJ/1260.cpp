#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int vertexes, lines, start;
int map[1001][1001];
bool check[1001];

void dfs(int vertex) {
	check[vertex] = true;
	printf("%d ", vertex);
	for (int i = 1; i < 1001; i++) {
		if (map[vertex][i] == 1) {
			if (check[i] == false) {
				dfs(i);
			}
		}
	}
}

void bfs(int vertex) {
	queue<int> q;
	q.push(vertex);
	check[vertex] = true;

	while (!q.empty()) {
		int newVertex = q.front();
		q.pop();

		for (int i = 1; i < 1001; i++) {
			if (map[newVertex][i] == 1) {
				if (check[i] == false) {
					check[i] = true;
					q.push(i);
				}
			}
		}
		printf("%d ", newVertex);
	}
}
int main(void) {
	
	cin >> vertexes >> lines >> start;
	int a, b;
	for (int i = 0; i < lines; i++) {
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}

	dfs(start);
	printf("\n");
	memset(check, false, sizeof(check));
	bfs(start);
	printf("\n");

	return 0;
}