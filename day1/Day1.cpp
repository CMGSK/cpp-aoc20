#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){

	vector<int> data;
	string temp;
	fstream input;
	input.open("input.txt", ios::in);
	if (input.is_open()){
		while (getline(input, temp)){
			data.push_back(atoi(temp.c_str()));
//			cout << data.size() << endl << "reach lecture ";
		}
	}
	else{
		cout << "failed vector" << endl;
	}
	

	for(int charnum=0; charnum < data.size(); charnum++){
		for (int secondnum=charnum; secondnum < data.size(); secondnum++){
			if (data[charnum] + data[secondnum] == 2020){
				cout << data[charnum] << "*" << data[secondnum] << endl;
				cout << data[charnum] * data[secondnum] << endl;
			}
		}
	}
	return 0;
}


