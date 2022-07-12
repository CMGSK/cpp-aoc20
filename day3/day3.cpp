#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


int slope (vector<string>& data, int i){

	int charnum=0;
	int trees=0;

	for (int linecheck=1; linecheck < data.size(); linecheck++){
		string line = data[linecheck];
		int tmp=0;
		while (tmp < i){
			tmp++;
			charnum++;
			if (line[charnum] == '\0'){
				charnum=0;
			}
		}

		if (line[charnum] == '#'){
			trees++;
		}
	}
	return trees;
}

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
		cout << "vector error" << endl;
	}

	int S1 = slope(data, 1);
	int S2 = slope(data, 3);
	int S3 = slope(data, 5);
	int S4 = slope(data, 7);

////////////////////////////////////////////////////////////////////////////////////

	const int i=1;
	int trees=0;	
	int charnum=0;
	for(int linecheck=2; linecheck < data.size(); linecheck += 2){
		string line = data[linecheck];
		int tmp=0;
		
		while (tmp < i){
			tmp++;
			charnum++;
			if (line[charnum] == '\0'){
				charnum=0;
			}
		}

		if (line[charnum] == '#'){
			trees++;
		}
	}

	int S5 = trees;

////////////////////////////////////////////////////////////////////////////////////////////

	cout << "Trees per slope:" << endl << S1 << endl << S2 << endl << S3 << endl << S4 << endl << S5 << endl;
	long int lint=0;
	lint = S1*S2*S3*S4;
	long long int res=lint*S5;
	cout << endl << res << endl;
	
//result for part 1 (given slope i=3)//
//	cout << trees << endl;	

	return 0;
}
