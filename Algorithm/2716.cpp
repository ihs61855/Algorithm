#include <iostream>
using namespace std;
int square(int k){
	int sum = 1;
	for (int i = 0; i < k; i++){
		sum = sum * 2;
	}
	return sum;
}

int main(){
	int n;
	char tree[1000][151];

	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++){
		cin.getline(tree[i], 150);
	}


	for (int i = 0; i < n; i++){
		int max = 0;
		int count = 0;
		int n = 0;
		while(tree[i][n] == '[' || tree[i][n] == ']'){
			if (tree[i][n] == '[')
				count++;
			if (tree[i][n] == ']')
				count--;
			if (count > max)
				max = count;
			n++;
		}
		cout << square(max) << endl;
	}
	return 0;
}