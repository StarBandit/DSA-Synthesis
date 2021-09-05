1. 
Problem: Choose a seat for 1 student in a class of M * N positions (excluding the teacher's desk).
Solution: Make a 2D array M*N. Mark positions with people (in code: equal to 1), empty positions (in code: equal to 0). Based on the matrix, enter the row and column of the empty position to determine student seating.
Code: 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand((int)time(0));
	int M = rand() % 6;
	int N = rand() % 6;
	int a[10][10];
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			a[i][j] = 1;
	int m = rand() % M;
	int n = rand() % N;
	a[m][n] = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cout << a[i][j] << "  ";
		cout << endl;
	}
	do {
		cout << "row position= ";
		cin >> m;
		cout << "column position= ";
		cin >> n;
		if (a[m - 1][n - 1] == 1)
			cout << "Someone is already sitting!!!" << endl;
		else cout << "Please sit.";
	} while (a[m - 1][n - 1] != 0);

	return 0;
}
