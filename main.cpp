#include <iostream>
#include "matrix.h"

using namespace std;

int main(int argc, char *argv[])
{
    NSpaceVector nsv;
        nsv[2][4][7][4] = 2;
        cout << nsv[2][4][7][4] << endl; //-> 2
    //Matrix<int, -1> matrix;
    /*cout<<"matrix.size() = "<<matrix.size()<<endl;
    matrix[100][100]=300;
    matrix.size();
    cout<<"matrix.size() = "<<matrix.size()<<endl;*/
    //cout<<matrix[0][0]<<endl;
    //matrix[0][0]=300;
    //cout<<matrix.size();

    /*for(Matrix<int, -1>::iterator i= matrix.begin();i!=matrix.end();i++)
    {
        int x;
        int y;
        int v;
        std::tie(x, y, v) = i.tup;
        std::cout << x << y << v << std::endl;
    }*/
}
