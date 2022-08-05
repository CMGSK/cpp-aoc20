#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

bool run (vector<pair<string, bool>> data);

int main(){

  vector<pair <string, bool>> data;
  string temp;
  fstream input;
  input.open("input.txt", ios::in);
  if (input.is_open()){
    while (getline(input, temp)) data.push_back(make_pair(temp, false));
  }else{
    std::cout << "failed vector" << endl; //sanity check
  }

  // I hate this forloop so much it's unreal
  for (int i=0; i<data.size(); i++){
    if (data[i].first.find("jmp") != string::npos){
      data[i].first.replace(data[i].first.find("jmp"), 3, "nop");
      if (!run(data)) data[i].first.replace(data[i].first.find("nop"), 3, "jmp");
      else break;
    }
    else if (data[i].first.find("nop") != string::npos){
      data[i].first.replace(data[i].first.find("nop"), 3, "jmp");
      if (!run(data)) data[i].first.replace(data[i].first.find("jmp"), 3, "nop");
      else break;
    }
  }
  cout << "Success." << endl;
  return 0;
}
//////////////////////////////////////////////////////////////////////////////////
bool run (vector<pair<string, bool>> data){
  int acc=0;
  for (int i=0; i<data.size(); i++){
    if(data[i].second == true) return false;
    data[i].second = true;

    string line = data[i].first;
    string instruction = line.substr(0, line.find(" "));
    int value = stoi(line.substr(line.find(" "), line.length()));

    if (instruction == "acc"){
      acc += value;
    }
    else if (instruction == "jmp"){
      i += value-1; // -1 compensates the i++ within the forloop
    }
  }
  cout<<acc<<endl;
  return true;
}
