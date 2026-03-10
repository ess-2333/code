#include <stdio.h>

// int main(){
//     int a = 2;
//     printf("%d",~a);
// }

// int main(){
//     int a = 2;
//     // int b = ++a; 3
//     int b = a++;
//     printf("%d",b);
// }

// int main(){
//     int a = 10;
//     int* p = &a;
//     *p = 20;
//     printf("%d",a);
// }

#include <time.h>
#include <stdlib.h>
int main(){
    srand((unsigned int)time(NULL));
    int a  = rand();
    printf("%d\n",a);

}