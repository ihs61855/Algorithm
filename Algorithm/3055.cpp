#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> coordinate;
//비어있는 곳은 '.'
//물이 차있는 지역은 '*'
//돌 'X'
//비버의 굴은 'D'로
//고슴도치의 위치는 'S'로 나타내어져 있다.

int main(){
	char arr[50][50];
	deque<coordinate> hedgehog;
	deque<coordinate> water;
	int xy[2];
	int Row, Column;
	int count = 0;
	cin >> Row >> Column;
	for (int i = 0; i < Row; i++){
		for (int j = 0; j < Column; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 'D'){
				xy[0] = i;
				xy[1] = j;
			}
			if (arr[i][j] == 'S'){
				hedgehog.push_back({ i, j });
			}
			if (arr[i][j] == '*'){
				water.push_back({ i, j });
			}
		}
	}

	while (1){
		count++;
		unsigned int temp = 0;


		temp = water.size();
		for (int i = 0; i < temp; i++){
			coordinate t = water.front();
			water.pop_front();
			if (!(t.first + 1 > Row) && arr[t.first + 1][t.second] == '.'){
				arr[t.first + 1][t.second] = '*';
				water.push_back({ t.first + 1, t.second });
			}
			if (!(t.first - 1 < 0) && arr[t.first - 1][t.second] == '.'){
				arr[t.first - 1][t.second] = '*';
				water.push_back({ t.first - 1, t.second });
			}
			if (!(t.second + 1 > Column) && arr[t.first][t.second + 1] == '.' ){
				arr[t.first][t.second + 1] = '*';
				water.push_back({ t.first, t.second + 1 });
			}
			if (!(t.second - 1 < 0) && arr[t.first][t.second - 1] == '.'){
				arr[t.first][t.second - 1] = '*';
				water.push_back({ t.first, t.second - 1 });
			}
		}

		temp = hedgehog.size();
		for (int i = 0; i < temp; i++){
			coordinate t = hedgehog.front();
			hedgehog.pop_front();
			if (t.first + 1 < Row && (arr[t.first + 1][t.second] == '.' || arr[t.first + 1][t.second] == 'D')){
				arr[t.first + 1][t.second] = 'S';
				hedgehog.push_back({ t.first + 1, t.second });
			}
			if (t.first - 1 >= 0 && (arr[t.first - 1][t.second] == '.' || arr[t.first - 1][t.second] == 'D')){
				arr[t.first - 1][t.second] = 'S';
				hedgehog.push_back({ t.first - 1, t.second });
			}
			if (t.second + 1 < Column && (arr[t.first][t.second + 1] == '.' || arr[t.first][t.second + 1] == 'D')){
				arr[t.first][t.second + 1] = 'S';
				hedgehog.push_back({ t.first, t.second + 1 });
			}
			if (t.second - 1 >= 0 && (arr[t.first][t.second - 1] == '.' || arr[t.first][t.second - 1] == 'D')){
				arr[t.first][t.second - 1] = 'S';
				hedgehog.push_back({ t.first, t.second - 1 });
			}

			if (arr[xy[0]][xy[1]] == 'S'){
				cout << count;
				return 0;
			}
		}

		if (hedgehog.size() == 0){
			cout << "KAKTUS";
			return 0;
		}
	}
	return 0;
}