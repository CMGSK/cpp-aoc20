#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){

	vector<int> data;
	string temp;
	fstream input;
	input.open("bigboy.txt", ios::in);
	if (input.is_open()){
		while (getline(input, temp)){
			data.push_back(atoi(temp.c_str()));
//			cout << data.size() << endl << "reach lecture ";
		}
	}
	else{
		cout << "failed vector" << endl;
	}
	
	int fchar = 0;
	int schar = 0;
	int tchar = 0;

	for (fchar=0; fchar < data.size(); fchar++){
		if (data[fchar] > 99920042){
			continue;
		}
		for (schar=0; schar < data.size(); schar++){
			if (data[fchar] + data[schar] > 99920043){
				continue;
			}
			for (tchar=0; tchar < data.size(); tchar++){
				if (data[fchar] + data[schar] + data[tchar] == 99920044){
					cout << "nigger" << endl;
					return 0;
				}

			}

		}
	cout << fchar/100 << endl;
	}

	return 0;

}


