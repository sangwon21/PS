#include <iostream>

using namespace std;

int computers, networks;
int network[101][101];
bool check[101];
int cnt = 0;

void dfs(int vertex) {
	check[vertex] = true;
	
	for (int i = 1; i < 101; i++) {
		if (check[i] == false && network[vertex][i] == true) {
			cnt++;
			dfs(i);
		}
	}
}
int main(void) {
		
	cin >> computers;
	cin >> networks;

	for (int i = 0; i < networks; i++) {
		int a, b;
		cin >> a >> b;
		network[a][b] = network[b][a] = 1;
	}
	
	dfs(1);
	printf("%d", cnt);
	return 0;
}