#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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
    cout << "vector error" << endl;
  }

  int valid=0;
  int result=0;

  for (int linecheck=0; linecheck < data.size(); linecheck++){

    string command;
    string line = data[linecheck];
    int charnum=0;

    while (!line.empty()){   

      while (line[charnum] != ':'){
        char tmp = line[charnum];
        command = command + tmp;
        charnum++;
      }
      cout << command << " ";
      if (command =="byr" || command =="iyr" || command =="eyr" || command =="hgt" || command =="hcl" || command =="ecl" || command =="pid"){
        valid++;
      }
      command="";

      while (line[charnum] != ' '){
        charnum++;
        if (line[charnum] == '\0'){
          break;
        }
      }
      if (line[charnum] == '\0'){
        break;
      }
      if (line[charnum] == ' '){
        charnum++;
      }
    } 
    if (line.empty()){
      if (valid == 7){
        result++;
      }
      valid = 0;
    }
    cout << endl;
  }
  cout << result << endl;
  return 0;
  //if last chunk of data is valid therefore result++, since no condition
  //line.empty() is given, no value is added to result and final result
  //will be 1 lower.
}



