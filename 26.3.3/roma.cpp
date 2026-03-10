#include <iostream>
#include <map>
using namespace std;

map<char, int> romanmap{
    {'I',1},
    {'V',5},
    {'X',10},
    {'L',50},
    {'C',100},
    {'D',500},
    {'M',1000}
};

int roma_to_int(string s){
    int res = 0;
    for(int i = 0; i < s.size(); i++){
        if(i != s.size() - 1 && romanmap[s[i]] < romanmap[s[i+1]]){
            res -= romanmap[s[i]];
        }
        else res += romanmap[s[i]];
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    int result = roma_to_int(s);
    cout << result;
}