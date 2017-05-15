#include<iostream>
using namespace std;
int pow(int x, int e){
    int res = 1;
    for (int i=0 ; i < e ; ++i){
        res *= x;
    }
    return res;
}

int main(){
    int _pow = pow(2, 31);
    int a = - _pow;
     cout<< _pow << " " << a<< endl;
}
