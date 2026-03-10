#include <stdio.h>
#include <string.h>

struct Stu{
    char name[20];
    int age;
    double score;
};

void set_struct(struct Stu* ps){
    // strcpy((*ps).name, "123");
    // (*ps).age = 20;
    // (*ps).score = 100;
    strcpy(ps -> name,"123");
    ps->age = 20;
    ps->score = 100;
}

void print_stu(struct Stu ss){
   printf("%s %d %lf\n",ss.name,ss.age,ss.score);
}

int main(){
    struct Stu s = {0};
    set_struct(&s);
    print_stu(s);
}