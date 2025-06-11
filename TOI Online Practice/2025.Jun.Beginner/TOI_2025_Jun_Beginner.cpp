#include<iostream>
#include<vector>
using namespace std;
int main() {
	int w, h;
	while (cin >> w >> h) {
		vector<vector<int>> paper(h, vector<int>(w, 0));
		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				cin >> paper[i][j];
			}
		}
		vector<vector<int>> open(h, vector<int>(w * 2, 0));
		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				open[i][j] = paper[i][j];
				open[i][j + w] = paper[i][j];
			}
		}

		//upper part

		vector<vector<int>> opena(2 * h, vector<int>(w * 2, 0));
		for (int i = 0;i < h;i++) {
			opena[i] = open[i];
			opena[2 * h - 1 - i] = open[i];
		}

		for (int i = 0;i < 2 * h;i++) {
			for (int j = 0;j < w * 2;j++) {
				cout << opena[i][j] << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}
