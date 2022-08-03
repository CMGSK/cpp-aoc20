#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;


bool agree (vector <string>& data, int vectorline, char yes){
  int check=0;
  int fwd=0;
  string line = data[vectorline+1];
  while (!line.empty()){
    for (int charnum=0; charnum < line.size(); charnum++){
      if (yes==line[charnum]){
        check++;
        break;
      }
    }
    vectorline++;
    fwd++;
    if (fwd!=check){
      return false;
    }
    line = data[vectorline+1];
  }
  if (check != 0 && fwd != 0){
    return (check==fwd);
  }
  else return false;
}

//TODO: find the mistake making the program take always
// +1 and forward letters of first row and giving them
// to the vector and never the first character at row 1.

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
    cout << "Vector error" << endl;
  }

//forms some needed variables and starts the input parse
  int endResult=0;
  vector<char> affirmatives;

  for (int vectorline=0; vectorline <= data.size(); vectorline++){
    string line = data[vectorline];
    
//prepares for another passenger when empty line is detected
//-1 in both here and endResult operation since vector will take a new empty space to fill up next
    if (line.empty()){
      endResult = endResult + affirmatives.size();
      cout << affirmatives.size() << ": ";
      for (char x : affirmatives){
         cout << x << " ";
      }
      cout << endl;
      affirmatives.clear();
    }

    else if (data[vectorline+1].empty()){
      cout << "DUH" << endl;
      for (int charnum=0; charnum < data[vectorline].size(); charnum++){
        affirmatives.push_back(data[vectorline][charnum]);
      }
      cout << affirmatives.size() << endl;
    }

// provided lane is not empty, in each char from the input calls for a funct that should give
// true if letter is in the following lines up to a double line jump or not. If exists in all 
// of them, it should add said char to vector
    else{
      for (int charnum=0; charnum < line.size(); charnum++){
        char yes = line[charnum];
        if (agree(data, vectorline, yes)){
          affirmatives.push_back(yes);
        }
      }
      while (!data[vectorline].empty()){
        vectorline++;
      }
      vectorline--;
    }
  }
  
  cout << endResult << endl;
  return 0;
}

