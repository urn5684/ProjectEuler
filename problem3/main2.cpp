

#include <iostream>

int main(int argc, const char * argv[])
{

    // 13195 の素因数は 5, 7, 13, 29 である.
    // 600851475143 の素因数のうち最大のものを求めよ.

    using namespace std;
 
    // まずは普通に思いつく試し割りで。
    const unsigned long long BIG_NUM = 600851475143;
    
    unsigned long long i=2;
    unsigned long long buf = BIG_NUM;
    while (i < BIG_NUM) {
        if (buf % i == 0) {
            cout << i << endl ;
            buf = buf / i;
        }
        cout << "out: " << i << endl;
        i++;
    }

    return 0;
}

