#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int goldParse (string p, map<string, vector<pair<string, int>>> instruction);

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
  
  map <string, vector<pair<string, int>>> instruction;

  for (int i=0; i<data.size(); i++){

    string line = data[i];
    int upTo = line.find("bags");
    string bag = line.substr (0, upTo -1); 

    vector<pair<string, int>> content;
    string bagIn;
    int j=upTo;
    for(j; j<line.size(); j++){
      if (line[j] >= '1' && line[j] <= '9'){
        int quantity = line[j] - '0';
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
        content.push_back(make_pair(bagIn, quantity));
        bagIn = "";
      }
    }
    instruction.insert({bag, content});
  }
  int res = goldParse("shiny gold", instruction);
  cout << res << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int goldParse (string p, map<string, vector<pair<string, int>>> instruction){
  if (instruction[p].empty()) return 0;
  int res=0;
  for(auto& i : instruction[p]){
    if (goldParse(i.first, instruction) == 0) res+=i.second;
    else res+= i.second + (i.second*goldParse(i.first, instruction));
  }
  return res;
}

