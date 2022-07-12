#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main (){

	vector<string> data;
	string temp;
	fstream input;
	input.open("input.txt", ios::in);
	if (input.is_open()){
		while (getline (input, temp)){
			data.push_back(temp);
		}
	}
	else{
		cout << "vector error";
	}

	int result=0;
	
	for(int instr=0; instr < data.size(); instr++){

		int charnum=0;
		int minimum=0;
		int maximum=0;
		int acceptance=0;
		string line = data[instr];

		while (line[charnum] != '-'){
			minimum = minimum * 10 + (line[charnum] - 48); 
// subtracting 48 to ascii num and letting c++ handle type to convert into int 
			charnum++;
		}
		charnum++;
		while (line[charnum] != ' '){
			maximum = maximum * 10 + (line[charnum] - 48);
			charnum++;
		}
		charnum++;
		char x = line[charnum];
		while (line[charnum] != ' '){
			charnum++;
		}
		charnum++;
		while (line[charnum] != '\0'){
			if (line[charnum] == x){
				acceptance++;
			}
			charnum++;
		}
		if (acceptance <= maximum && acceptance >= minimum){
			result++;	
		}
	}
	
	cout << result << endl;

	return 0;
}

/*
 	while (line[charnum] != '-'){
			tmp = tmp + line[charnum]
			minimum = minimum * 10 + atoi(tmp.c_str);
			charnum++;

			//using c.str to convert to c string for atoi usage
*/		
