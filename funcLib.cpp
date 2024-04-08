#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
const int n=2;
#include "myLib.cpp"

int main(){
    srand((unsigned)time(NULL));
    int mat[n][n];
    //int mat[2][2]={{10,2},{5,6}};
    llenar(mat,n);
    printx(mat,n);
}