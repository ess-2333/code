#include <iostream>
#include <stdlib.h>

using namespace std;

#define ST_INIT_SIZE 100
#define ST_increase 10
typedef int SElemType;

typedef struct{
    SElemType base;
    SElemType top;
    int stacksize;
}SqStack;

void InitStack(SqStack& st){
    st.base = new SElemType[ST_INIT_SIZE];
    st.top = st.base;
    st.stacksize = ST_INIT_SIZE;
    int num;
    cin >> num;
    while(num > st.stacksize){
        cout << "error" << endl;
        cin >> num; 
    }
    for(int i = 0; i < num; i++){
        cin >> *((st.top)-1);

    }
}

int main(){
    SqStack st;
    InitStack(st);
}