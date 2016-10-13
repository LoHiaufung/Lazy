#include <iostream>
#include <math.h>

using namespace std;

// Combination number
double cn(int x, int n) {
	double* c = new double[n+1];
	c[0] = 1.0;
	for (int i = 1; i < n+1; i++) {
		c[i] = c[i-1] / i * (n - i + 1); 
	}

	double out = c[x];
	delete[] c;
	return out;
}

// [begin , end] 
double hgd(int x, int n, int M, int N) {
	return  (cn(x, M) * cn(n-x, N -M) / cn(n, N));
}

int main() {
	cout << "Hypergrometric Distribution Computer " << endl;
	cout << "[begin, end] enter begin, end , n, M, N:" << endl;
	int begin = 0, end = 0, n = 0, M = 0, N = 0;
	cin >> begin >> end >>  n >>  M >> N;
	
	double sum = 0;
	for (int i = begin; i <= end; i++) {
		sum += hgd(i, n, M, N);
	}
	cout << "P(" << begin << " <= X <= " << end << ") == " << sum << endl;
	return 0;
}
