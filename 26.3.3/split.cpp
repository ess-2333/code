#include <iostream>
#include <vector>   // 必须包含，因为用到vector
#include <sstream>  // 必须包含，因为用到stringstream
#include <string>   // 必须包含，因为用到string
using namespace std;

//字符串切割
vector<string> split(string str, char del){
    stringstream ss(str);
    string temp;
    vector<string> ret;
    //getline(输入，保存切割后的，分隔符)
    while(getline(ss,temp,del)){
        ret.push_back(temp);
    }
    return ret;
}

int main(){
    string ss = "one#two#three";
    vector<string> res = split(ss, '#');
    for(auto c : res){
        cout << c << endl;
    }
}