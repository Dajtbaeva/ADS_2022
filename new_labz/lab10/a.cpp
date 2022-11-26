// Marios War
#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, c, mushrooms = 0, t = 0;
	cin >> r >> c;
	int adj_matrix[r + 2][c + 2];
	vector<pair<int, int> > mario;
	for (int i = 0; i < r + 2; i++) {
		for (int j = 0; j < c + 2; j++) {
			if (i == 0 || j == 0 || i == r + 1 || j == c + 1) {
				adj_matrix[i][j] = 1000;
				continue;
			}
			cin >> adj_matrix[i][j];
			if (adj_matrix[i][j] == 2) {
				mario.push_back({ i, j });
			} else if (adj_matrix[i][j] == 1) {
				mushrooms++;
			}
		}
	}
	queue<pair<int, int> > q;
	for (int i = 0; i < mario.size(); i++) {
		q.push({ mario[i].first, mario[i].second });
	}
	while (!q.empty()) {
		if (!mushrooms) break;
		int size = q.size();
		while (size--) {
			pair<int, int> marioPos = q.front();
			q.pop();
			int i = marioPos.first;
			int j = marioPos.second;
			if (adj_matrix[i - 1][j] == 1) {
				adj_matrix[i - 1][j] = 2;
				q.push({ i - 1, j });
				mushrooms--;
			}
			if (adj_matrix[i + 1][j] == 1) {
				adj_matrix[i + 1][j] = 2;
				q.push({ i + 1, j });
				mushrooms--;
			}
			if (adj_matrix[i][j - 1] == 1) {
				adj_matrix[i][j - 1] = 2;
				q.push({ i, j - 1 });
				mushrooms--;
			}
			if (adj_matrix[i][j + 1] == 1) {
				adj_matrix[i][j + 1] = 2;
				q.push({ i, j + 1 });
				mushrooms--;
			}
		}
		t++;
	}
	cout << (!mushrooms ? t : -1);

}