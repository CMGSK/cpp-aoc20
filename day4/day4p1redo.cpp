#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

bool isdigit(char number){
  int check = number - 48;
  if (check <=9 && check >=0){
    return true;
  }
  else return false;  
}

bool ishex(char hex){
  if (hex >= 'a' && hex <= 'f'){
    return true;
  }
  else{
    int num = hex - 48;
    return (num <= 9 && num >= 0);
  }
}

bool isvalid(string& line, string& command, int charnum){
  int valid=0;
  if (command == "byr"){
    int year=0;
    while(line[charnum] !=  ' ' && line[charnum] != '\0'){
      int tmp = line[charnum] - 48;
      year = (year * 10) + tmp;
      charnum++;
    }
    if (year >= 1920 && year<=2002){
      valid++;
    }
  }
  else if (command == "iyr"){
    int year=0;
    while(line[charnum] !=  ' ' && line[charnum] != '\0'){
      int tmp = line[charnum] - 48;
      year = (year * 10) + tmp;
      charnum++;
    }
    if (year >= 2010 && year <= 2020){
      valid++;
    }
  }
  else if (command == "eyr"){
    int year=0;
    while(line[charnum] !=  ' ' && line[charnum] != '\0'){
      int tmp = line[charnum] - 48;
      year = (year * 10) + tmp;
      charnum++;
    }
    if (year >= 2020 && year <= 2030){
      valid++;
    }
  }
  else if (command == "hgt"){
    int height=0;
    while (isdigit(line[charnum])){
      int tmp = line[charnum] - 48;
      height = (height * 10) + tmp;
      charnum++;
    }
    if (line[charnum] == 'c'){
      if (height >= 150 && height <= 193){
        valid++;
      }
    }
    else if (line[charnum] == 'i'){
      if (height >= 59 && height <= 76){
        valid++;
      }
    }
  }
  else if (command == "hcl"){ 
    if (line[charnum] == '#'){
      charnum++;
      int count=0;
      for (count ; ishex(line[charnum]) && count < 6 ; count++){
        charnum++;
      }
      if (line[charnum] == ' ' && count==6){
        valid++;
      }
      else if (line[charnum] == '\0' && count==6){
        valid++;
      }
    }
  }
  else if (command == "ecl"){
    string color;
    while (line[charnum] != ' ' && line[charnum] != '\0'){
      color = color + line[charnum];
      charnum++;
    }
    if (color == "amb" || 
        color == "blu" || 
        color == "gry" || 
        color == "grn" || 
        color == "hzl" || 
        color == "oth" || 
        color == "brn"){
      valid++;
    }
  }
  else if (command == "pid"){
    int tmp=0;
    while (line[charnum] != ' ' && line[charnum] != '\0'){
      if (!isdigit(line[charnum])){
        break;
      }
      charnum++;
      tmp++;
    }
    if (tmp == 9){
      valid++;
    }
  }
  return (valid==1);
}

////////////
//  MAIN  //
////////////

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
// vector lecture ends //
  string command;
  int accept=0;
  int result=0;

  for (int linecheck=0; linecheck < data.size(); linecheck++){

    string line = data[linecheck];
    int charnum=0;

    while (!line.empty()){   

      while (line[charnum] != ':'){
        char tmp = line[charnum];
        command = command + tmp;
        charnum++;
      }
      charnum++; 

      if (isvalid(line, command, charnum)){
          accept++;
      }

      command="";

      while (line[charnum] != ' '){
        if (line[charnum] == '\0'){
          break;
        }
        charnum++;
      }
      if (line[charnum] == '\0'){
        break;
      }
      if (line[charnum] == ' '){
        charnum++;
      }
    } 
    if (line.empty()){
      cout << accept << endl;
      if (accept == 7){
        result++;
      }
      accept = 0;
    }
  }
  cout << endl << result << endl;
  return 0;
  //if last chunk of data is valid therefore result++, since no condition
  //line.empty() is given, no value is added to result and final result
  //will be 1 lower.
}



