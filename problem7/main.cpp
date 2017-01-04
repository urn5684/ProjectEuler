
#include <iostream>
#include <math.h>

bool isPrimeDE(unsigned int);


int main(int argc, const char * argv[])
{

    // 素数を小さい方から6つ並べると 2, 3, 5, 7, 11, 13 であり, 6番目の素数は 13 である.
    // 10001 番目の素数を求めよ.
    
    // まずは試し割りで
    using namespace std;
 
    const int MAX = 10001;
    int cnt = 0;
    int i=1 ;         // ループの外に値を持ち出すため
    while (cnt < MAX) {
        if (isPrimeDE(i)) {
            cnt++;
            //cout << cnt << " : " << i << endl;
        }
        i++;
    }

    cout <<"Answer: "  << cnt << "st Prime numder is : " <<  i-1 << endl ;

    return 0;
}


bool isPrimeDE(unsigned int n)  // DE: divide every number
{
    //　試し割りでの素数判定
    // 引数が 素数なら true，合成数なら false を返す
    
    if (n == 1) {
        return false ;
    } else if (n == 2){
        return true ;
    } else if (n % 2 ==0) {
        return false ;
    } else {
        for (long i=3; i <= sqrt(n); i += 2) {
            if ( n % i == 0) {
                return false ;
            }
        } return true ;
    }

}
