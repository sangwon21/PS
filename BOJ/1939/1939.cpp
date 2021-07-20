#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int,int>> islands[10001];
bool check[10001];
int N, M;
int Max = 0;
int start, target;

bool dfs(int vertex, int weight) {

	if (vertex == target)
		return true;
	if (check[vertex]) {
		return false;
	}
	check[vertex] = true;
	for (auto &p:islands[vertex]) {
		int next = p.first;
		int cost = p.second;
		if (cost >= weight) {
			if (dfs(next, weight))
				return true;
		}
	}
	return false;
}

int main(void) {
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		islands[a].push_back(make_pair(b, c));
		islands[b].push_back(make_pair(a, c));
		if (Max < c) {
			Max = c;
		}
	}
	scanf("%d %d", &start, &target);

	int left = 1, right = Max;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;

		memset(check, false, sizeof(check));

		if (dfs(start, mid)) {
			if (ans < mid) {
				ans = mid;
			}
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	printf("%d\n", ans);

	return 0;
}