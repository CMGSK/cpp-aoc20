#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

void printmap (map<string, vector<string>> instruction); 
int recParse (map<string, vector<string>> instruction);

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

    // getting instruction bag into a string
    // -1 to avoid a blank space at the end of the bag name
    // cout << bag << endl; //sanity check 

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
  printmap(instruction); //sanity check print map
}

void printmap (map<string, vector<string>> instruction){

  for (auto& x : instruction){
    cout << x.first << " contains \n";
    for (auto& y : x.second){
      cout << '\t' << y << endl;
    }
    cout << endl;
  }
}

int recParse (map<string, vector<string>> instruction){
  int res=0;
  if( instruction.first == "shiny gold" || find(instruction.second.begin(), instruction.second.end(), "shiny gold")) res++ && return 1;
  else {
    // res++;
    recParse(map<string, vector<string>> instruction);
  }
  /*
  bool a=false;
  while (a==false) {
    for(auto& x : instruction.second){
      if (x=="shiny gold") {
        a=true;
        return 1;
      }
    }
  }
  */
  

}
