
#include <iostream>
#include <math.h>


using namespace std;


bool isPrimeDE(unsigned int);



int main(int argc, const char * argv[])
{
    // 10以下の素数の和は 2 + 3 + 5 + 7 = 17 である.
    // 200万以下の全ての素数の和を求めよ.

    const int MAX_VAL = 2000000;
    long sum = 2;
    for (int i = 1; i < MAX_VAL; i += 2) {
        if (isPrimeDE(i)) {
            sum = sum + i ;
        }
    }
    
    cout << "Answer :" << sum << endl ;

    return 0;
}

bool isPrimeDE(unsigned int n)  // DE: divide every number
{
    //　試し割りでの素数判定
    // 引数が 素数なら true，合成数なら false を返す
    
    if (n < 2) {
        return false ;
    } else if (n == 2){
        return true ;
    } else if (n % 2 ==0) {
        return false ;
    }else {
        for (long i=3; i <= sqrt(n); i += 2) {
            if ( n % i == 0) {
                return false ;
            }
        } return true ;
    }
    
}