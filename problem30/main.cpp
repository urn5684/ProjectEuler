

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>


using namespace std;


int main(int argc, const char * argv[])
{
    
    // 各桁を5乗したものの和が元の値に等しいもの
    //　はじめは5桁と思い込んでやってしまって間違えた。
    // 9の5乗の和は7つ足しても　413343 にしかならず，7桁に到達できない。検索上限は　9^5 x 6 まで。
    
    long sum = 0;
    long product = 0;
    long wholeSum = 0;
    
    for (int a = 0; a < 10; a++) {
        for (int b=0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {
                for (int d = 0; d < 10; d++) {
                    for (int e = 0; e < 10; e++) {
                        for (int f = 0; f < 10; f++) {
                            sum = pow(a,5)+pow(b,5)+pow(c,5)+pow(d,5)+pow(e,5)+pow(f,5);
                            product = 100000*a+10000*b+1000*c+100*d+10*e+f;
                            if (product > pow(9, 5)*6) {
                                break;
                            }
                            if (sum > 1 && sum == product) {
                                // cout<< a << b << c << d << e << f << endl;
                                wholeSum += sum;
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    cout << "Sum: " << wholeSum << endl;
    
    
    return 0;
}
