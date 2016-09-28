#include <iostream>
#include <math.h>

using namespace std;

int main () {
	int n;
	cout << "Type in n: ";
	cin >> n;

	double* c = new double[n+1];
	c[0] = 1;
	for (int i = 1; i < n+1; i++) {
		c[i] = c[i-1] / i * (n - i + 1); 
	}

	double successProbability;
	cout << "Type in the success probability: ";
	cin >> successProbability;
	double* sp = new double[n+1];
	for (int i = 0; i < n + 1; i++) {
		sp[i] = c[i] * pow(successProbability, i) * pow(1 - successProbability, n - i); 
	}

	int begin, end = 0;
	cout << "To get the sum,the begin index: ";
	cin >> begin;
	cout << "To get the sum,the end index: ";
	cin >> end;

	double sum = 0;
	for (int i = begin; i < end + 1; i++) {
		sum += sp[i];
	}
	cout << "[begin, end] sum of probability is: " << sum << endl;

	double sumWithWeight = 0;
	for (int i = begin; i < end + 1; i++) {
		sumWithWeight += sp[i] * i;
	}
	cout << "[begin, end] sum of probability with weight is: " << sumWithWeight << endl;

	double expectedValue = 0;
	for (int i = 0; i < n + 1; i++) {
		expectedValue += sp[i] * i;
	}
	cout << "[0, n] sum expected value is: " << expectedValue << endl;
	
	double variance = 0;
	for (int i = 0; i < n + 1; i++) {
		variance +=  (i - expectedValue) * (i - expectedValue) * sp[i];
	}
	cout << "[0, n] the variance is: " << variance << endl;
	cout << "[0, n] the standard deviation is: " << sqrt(variance) << endl;

	delete[] c;
	delete[] sp;
	return 0;
}
