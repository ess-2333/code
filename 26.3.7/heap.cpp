#include <iostream>
#include <queue>
using namespace std;

int main(){
    //default(max heap)
    priority_queue<int> q1;
    //max heap
    priority_queue<int,vector<int>,less<int>> q2;
    //min heap
    priority_queue<int, vector<int>,greater<int>> q3;

    for(int i = 0; i < 10; i++){
        q1.push(i);
        q2.push(i);
        q3.push(i);
    }
    cout << "q1(default)";
    while(!q1.empty()){
        cout << q1.top() << " ";
        q1.pop();
    }
    cout << endl << "q2 max heap(less)";
    while(!q2.empty()){
        cout << q2.top() << " ";
        q2.pop();
    }
    cout << endl << "q3 min heap(greater)";
    while(!q3.empty()){
        cout << q3.top() << " ";
        q3.pop();
    }
}