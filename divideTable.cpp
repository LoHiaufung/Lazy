//     When I do my project2, my program produce four 
// million data which is too much for a single excel chart.
// However, it is impossible to divide it into four by hand,  
// so I write this program to hele me.
//     做 project2 的时候，产生了四百万条数据。但是一个excel
// 表只能处理一百万多一点的数据，然而用人手把这四百万条数据
// 分成四份几乎不可能，所以我写了一个小程序来干这事。


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	// the input file
	ifstream inFile("out2.txt");

	// divide the input file into four files
	ofstream file[4];
	file[0].open("out2/out1.txt");
	file[1].open("out2/out2.txt");
	file[2].open("out2/out3.txt");
	file[3].open("out2/out4.txt");
	string str;

	for (int i = 0; i < 4; i++) {
		int counter = 0; 
		while ((!inFile.eof()) && (counter <= 1048575)) {
			getline(inFile, str);
			counter++;
			file[i] << str << endl;
		}
	}
	return 0;
}