#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool repeat(vector<char> affirmatives, char yes){
  for (int i=0; i<affirmatives.size(); i++){
    if (yes == affirmatives[i]){
      return false;
    }
    else continue;
  }

  return true;
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
    cout << "Vector error" << endl;
  }
  
  int endResult=0;
  vector<char> affirmatives;
  int jump=0;

  for (int vectorline=0; vectorline <= data.size(); vectorline++){
    string line = data[vectorline];
    
    if (line.empty()){
      endResult = endResult + affirmatives.size()-1;
      sort(affirmatives.begin(), affirmatives.end());
      cout << affirmatives.size() << ": ";
// -1 in both here and endResult since vector will take a new empty space to fill up next
      for (char x : affirmatives){
        cout << x << " ";
      }
      cout << endl;
      affirmatives.clear();
      jump=0;
    }

    else{
      for (int charnum=0; charnum <= line.size(); charnum++){
        char yes = line[charnum];
        if (charnum == 0 && jump==0){
          affirmatives.push_back(yes);
          jump++;
        } 
        else if(repeat(affirmatives, yes)){
          affirmatives.push_back(yes);
        }
      }
    }
  }
  
  cout << endResult << endl;
  return 0;
}

