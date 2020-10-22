#include <iostream>
#include <stdio.h>
#include "Stream.hpp"
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char **argv) {
    if(argc != 2){
        printf("usage: %s <data_file>\n", argv[0]);
        return 0;
    }
    ifstream fin(argv[1]);
    if(!fin){
        cout << "ERROR: 1" << endl;
        return 0;
    }
    string t;
    vector<string> ori_data;
    while(!fin.eof()){
        fin >> t;
        ori_data.push_back(t);
    }
    Stream<string> s(ori_data);
    auto group = s.filter([](const string& ss){return ss[0]=='a';}).map<pair<string, int>>([](const string& ss){return make_pair(ss, 1);}).group_by_key<string, int>([](const pair<string, int>& p){return p.first;}, [](const pair<string, int>& p){return p.second;});
    for(auto it=group.begin(); it!=group.end(); it++){
        auto sum = it->second.reduce(0, [](const int& t1, const int& t2){return t1 + t2;});
        cout << it->first << " " << sum << endl;
    }
    return 0;
}

