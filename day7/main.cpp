#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isin (string bag, vector<string> possitive){
  for (int i=0; i<possitive.size(); i++){
    if (bag == possitive[i]) return true;
  }
  return false;
}

bool posparse (string line, vector<string> possitive){
  for (int i=0; i<possitive.size(); i++){
    if(line.find(possitive[i])!=string::npos) return true;
  }
  return false;
}

int main (){

  vector<string> data;
  string temp;
  fstream input;
  input.open("small.txt", ios::in);
  if (input.is_open()){
    while (getline(input, temp)){
      data.push_back(temp);
    }
  }
  else{
    std::cout << "failed vector" << endl; //sanity check
  }
  
  vector<string> possitive;
  
  int res = 1;
  int rescheck = possitive.size(); 

  while (res!=rescheck){
    for (int i=0; i<data.size(); i++){


      string line = data[i];
      int upTo = line.find("bags");
      string bag = line.substr (0, upTo -1); 

      // getting instruction bag into a string
      // -1 to avoid a blank space at the end of the bag name
      // cout << bag << endl; //sanity check 
      
      if (line.find("shiny gold") != string::npos && bag!="shiny gold"){
        // cout<<"yes"<<endl;
        if (!isin(bag, possitive)){
          possitive.push_back(bag);
        }
      }
      else if (bag!="shiny gold"){
        if (posparse(line, possitive)){
          possitive.push_back(bag);
        }
      }
      res = possitive.size();
    } 
  }
  for (string x : possitive){
    cout << x << endl;
  }
}
