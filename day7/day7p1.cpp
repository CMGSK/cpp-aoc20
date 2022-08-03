#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

void printmap (map<string, vector<string>> instruction); 
bool recParse (string p, map<string, vector<string>> instruction);

int main (){

  vector<string> data;
  string temp;
  fstream input;
  input.open("input.txt", ios::in);
  if (input.is_open()){
    while (getline(input, temp)){
      data.push_back(temp);
    }
  }
  else{
    std::cout << "failed vector" << endl; //sanity check
  }
  
  map <string, vector<string>> instruction;

  for (int i=0; i<data.size(); i++){

    string line = data[i];
    int upTo = line.find("bags");
    string bag = line.substr (0, upTo -1); 

    vector<string> content;
    string bagIn;
    int j=upTo;
    for(j; j<line.size(); j++){
      if (line[j] >= '1' && line[j] <= '9'){
        j = j+2;
        int spc=0;
        while (spc != 2){
          if (line[j]==' '){
            spc++;
          }
          if (spc==2) break;
          bagIn = bagIn + line[j];
          j++;
        }
        content.push_back(bagIn);
        bagIn = "";
      }
    }
    instruction.insert({bag, content});
  }
  int res = 0;
  for (auto& p : instruction){
    if (recParse(p.first, instruction)) res++;
  }
  cout << res << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool recParse (string p, map<string, vector<string>> instruction){
  if(p == "shiny gold") return false;
  if(find(instruction[p].begin(), instruction[p].end(), "shiny gold") != instruction[p].end()) return true;
  for (auto& i : instruction[p]){
    if (recParse(instruction[p][i], instruction)) return true; 
  }
  return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void printmap (map<string, vector<string>> instruction){
  for (auto& x : instruction){
    cout << x.first << " contains \n";
    for (auto& y : x.second){
      cout << '\t' << y << endl;
    }
    cout << endl;
  }
}

