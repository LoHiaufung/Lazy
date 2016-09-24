//*********************************************
// Copyright@LoHiaufung
// 2016.09.24 at SYSU
//
// 注意事项：
// 1.所有缩进都应为TAB
// 2.结束tag /> 和 </ 必须写完整
// 如果执行结果异常，很可能是上述两个条件不满足
//*********************************************

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

bool isLineBegin(int c, const string&);

int main(){
	string fname;
	cout << "Enter the file name: ";
	cin >> fname;
	ifstream infile(fname.c_str());
	if (!infile) {
		cout << "No this file!" << endl;
	} else {
		char c;
		char c2;
		int tabAmount = 0;
		string buff;
		ofstream oufile("tmpFile");
		if (!oufile) {
			cout << "Unknown error!" << endl;
			return 1;
		}
		while (!infile.eof()) {
			getline(infile, buff);
			for (int j = 0; j < buff.length(); j++) {
				c = buff[j];
				// discard all original indent Tab
				if ('	' != c) {
					// c's case 1:
					if ('<' == c) {
						c2 = buff[j+1];
						j++;
						// meet end tag "</"
						if ('/' == c2) {
							tabAmount--;
							// at the line begin, output indent Tab 
							// else not output  Tab
							if (true == isLineBegin(j - 1, buff)) {
								for (int i = 0; i <  tabAmount ; ++i) {
									oufile << '\t';
								}
							}
						// meeting comment " <! 
						} else if ('!' == c2) {
							// at the line begin, output indent Tab 
							// else not output  Tab
							if (true == isLineBegin(j - 1, buff)) {
								for (int i = 0; i <  tabAmount ; ++i) {
									oufile << '\t';
								}
							}
						// meeting neither " <! " nor "</ "
						// which means meeting a begin tag '<'
						} else {
							// at the line begin, output indent Tab
							// meeting a begin tag '<, counter add 1
							if (true == isLineBegin(j - 1, buff)) {
								for (int i = 0; i <  tabAmount ; ++i) {
									oufile << '\t';
								}
							}
							tabAmount++;
						}
						// write the not Tab char to temp file
						oufile << c << c2;
					// c's case s:
					} else if ('/' == c){
						c2 = buff[j+1];
						j++;
						// meet end tag "/>"
						if ('>' == c2) {
							tabAmount--;
						}
						// write the not Tab char to temp file
						oufile << c << c2;
					// default case:
					} else {
						 oufile << c;
					}
				}
			}
			// the function getline() discarded '\n', we repick it
			oufile << endl;

		}

		// write to the original file from temp file
		ifstream infile2("tmpFile");
		ofstream outfile2(fname.c_str());
		while (!infile2.eof()) {
			getline(infile2, buff);
			outfile2 << buff << endl;
		}

		// delete temp file
		oufile.close();
		infile2.close();
		remove("tmpFile");
	}
	return 0;
}

bool isLineBegin(int c, const string& str) {
	for (int i = 0; i < c; i++) {
		if ('\t' != str[i]) {return false;}
	}
	return true;
}