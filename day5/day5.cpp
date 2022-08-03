#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
  
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

  int seatID=0;
  for (int z=0; z < data.size(); z++){
    string seat = data[z];
    int upper=128;
    int lower=0;
    for (int charnum=0; charnum < 7; charnum++){
      char search = seat[charnum];
      if (search == 'F'){
        upper -= (upper - lower) / 2;
      }
      else if (search == 'B'){
        lower += (upper - lower) / 2;
      }

    }
    upper--;
    // row assign
    
    int right=8;
    int left=0;
    for (int charnum=7; charnum < 10; charnum++){
      char search = seat[charnum];
      if (search == 'L'){
        right -= (right - left) / 2;
      }
      else if (search == 'R'){
        left += (right - left) / 2;
      }
    }
    right--;
    // column assing
    
    if ((upper * 8) + right > seatID){
      seatID = (upper * 8) + right;
    }
    
  cout << "Row " << upper << " | Column " << right << endl;
  cout << "seat ID: " << (upper * 8) + right << endl << endl;
  }
  cout << "highest ID: " << seatID << endl;
}
