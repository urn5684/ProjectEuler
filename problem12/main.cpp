

#include <iostream>
#include <math.h>

using namespace std;


int factorize(unsigned int n);
int divisor(unsigned int n,long i);


int main(int argc, const char * argv[])
{
    /* 三角数の数列は自然数の和で表わされ, 7番目の三角数は 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28 である.
    // 三角数の最初の10項は: 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, .. となる.
    //
    // 最初の7項について, その約数を列挙すると, 以下のとおり.
    //    1: 1
    //    3: 1,3
    //    6: 1,2,3,6
    //    10: 1,2,5,10
    //    15: 1,3,5,15
    //    21: 1,3,7,21
    //    28: 1,2,4,7,14,28
    //
    //    これから, 7番目の三角数である28は, 6個以上の約数をもつ最初の三角数であることが分かる.
    //    では, 500個以上の約数をもつ最初の三角数はいくつか.
    */
    // 答え　76576500 : 576　個の約数を持っている
    
    const int mLIMT = 500;
    int cnt = 0;
    long i = 1;

    while (true) {
        cnt = factorize(i*(i+1)/2) ;
        if (cnt >= mLIMT) {
            cout << "Answer :  " << i*(i+1)/2 << " 約数の個数: " << cnt << " 　生成数: " << i << endl;
            break;
        }
        // cout << i*(i+1)/2 << " : " << cnt << endl;
        i++;
    }
    return 0;
}


int factorize(unsigned int n)
{
    int m = 1;
    int tmp = 0;

    if (n == 1) {
        return 1;
    } else if (n % 2 == 0){
        tmp = divisor(n, 2); // まずは2で割れるだけ割っておく。
        m *= (tmp + 1);
        n = n / pow(2, tmp );
    }
    
    long i;
    for (i = 3; i <= sqrt(n); i += 2) {
        if ( n % i == 0) {
            tmp = divisor(n, i);
            m *= (tmp + 1);
            n = n / pow(i, tmp);
        }
    }
    if (n != 1) {
        m *= 2 ;
    }

    return m;
}

int divisor(unsigned int n,long i)
{
    int index = 0 ;
    
    while (n % i == 0) {
        n = n / i;
        index++;
    }

    return index;
}


/*
*
*  引数をただ順番に割っていく力技。
*  正しい答えは得られるが遅く　53分かかった。
*
*/
/*
int divisor(long n)
{
    int cnt = 0;
    if (n == 1) {
        return 1;
    }
    
    for ( long i = n ; i> 0; i--) {
        if (n % i == 0) {
            cnt++;
        }
    }
    return cnt;
}
*/