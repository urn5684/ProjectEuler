

#include <iostream>


using namespace std;


int collatz(unsigned int);


int main(int argc, const char * argv[])
{

//    正の整数に以下の式で繰り返し生成する数列を定義する.
//    
//    n → n/2 (n が偶数)
//    n → 3n + 1 (n が奇数)
//    
//    13からはじめるとこの数列は以下のようになる.
//    13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
//    
//    13から1まで10個の項になる. この数列はどのような数字からはじめても最終的には 1 になると考えられているが,
//    まだそのことは証明されていない(コラッツ問題)
//    
//    さて, 100万未満の数字の中でどの数字からはじめれば最長の数列を生成するか.
//    注意: 数列の途中で100万以上になってもよい

    
    const unsigned int MAX_NUM = 1000000;
    unsigned int StartNum = 0;
    int maxStep = 0;

    
    for (unsigned int i = 3; i < MAX_NUM; i++) {
        int step = collatz(i);
        
        if (maxStep < step) {
            maxStep = step;
            StartNum = i;
        }
    }
    
    // 今度　Vector を使ってはじめの数とStep数を格納・一覧作成してみよう。

    cout << "StartNum: " << StartNum << "   Step: " << maxStep << endl;
    
    return 0;
}

int collatz(unsigned int n)
{
    int step = 0;
    
    while (true) {
        if (n == 1)
            break;
        else {
            if (n % 2 == 0)
                n = n / 2;
             else
                n = 3*n + 1;
            
            step++;
        }
    }
    return step;
}

