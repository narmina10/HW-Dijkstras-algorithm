#include <iostream>
using namespace std;

#define SIZE 6

int main() {
	int a[SIZE][SIZE];
	int d[SIZE];
	int v[SIZE];
	int temp, minindex, min;
	int begin_index = 0;
	
	for (int i = 0; i < SIZE; i++) {
		a[i][i] = 0;
		for (int j = i + 1; j < SIZE; j++) {
			cout << "Enter the weight: " << i + 1 << " - " << j + 1 << ": ";
			cin >> temp;
			a[i][j] = temp;
			a[j][i] = temp;
		}
	}
	cout << "Our matrix: \n";
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	
	for (int i = 0; i < SIZE; i++) {
		d[i] = 10000;
		v[i] = 1;
	}
	
	d[begin_index] = 0;
	
	do {
		minindex = 10000;
		min = 10000;
		for (int i = 0; i < SIZE; i++) {
			
			if ((v[i] == 1) && (d[i] < min)) {
				
				min = d[i];
				minindex = i;
			}
		}
		

		if (minindex != 10000) {
			for (int i = 0; i < SIZE; i++) {
				if (a[minindex][i] > 0) {
					temp = min + a[minindex][i];
					if (temp < d[i]) {
						d[i] = temp;
					}
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 10000);
	
	
	cout << "\nShortest distance from vertex " << d[begin_index] + 1 << " to other vertexes: \n";
	for (int i = 0; i < SIZE; i++)
		cout << d[i] << " ";
	

	int ver[SIZE];
	int end = 4;
	ver[0] = end + 1;
	int k = 1;
	int weight = d[end];
	
	while (end != begin_index) {
		for (int i = 0; i < SIZE; i++) {
			if (a[i][end] != 0) {
				temp = weight - a[i][end];
				if (temp == d[i]) {
					
					weight = temp;
					end = i;
					ver[k] = i + 1;
					k++;
				}
			}
		}
	}
	
	cout << "\nShortest paths to vertexes: \n";
	for (int i = 0; i < SIZE; i++) {
		cout << "Vertex " << i+1 << ": ";
		int path[SIZE], len = 0;
		path[len] = i + 1;
		len++;
		int j = i;
		while (j != begin_index) {
			for (k = 0; k < SIZE; k++) {
				if (a[j][k] != 0 && d[j] == d[k] + a[j][k]) {
					path[len] = k + 1;
					len++;
					j = k;
					break;
				}
			}
		}
		for (k = len - 1; k >= 0; k--) {
			cout << path[k] << " ";
		}
		cout << endl;
	}
	return 0;
}
