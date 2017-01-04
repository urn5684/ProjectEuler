
#include <iostream>
#include <map>
#include "math.h"


std::map<int, int> factorize(unsigned int n);
int divisor(unsigned int n,long i);
int AmicableNumbers(std::map<int,int> dic);
int calTrueAliquot(std::map<int,int> factMap);
void showFactlialPair(std::map<int,int> MAP);


int main(int argc, const char * argv[])
{
    
    // problem21
    //    d(n) を n の真の約数の和と定義する. (真の約数とは n 以外の約数のことである. )
    //    もし, d(a) = b かつ d(b) = a (a ≠ b のとき) を満たすとき, a と b は友愛数(親和数)であるという.
    //    
    //    例えば, 220 の約数は 1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110 なので d(220) = 284 である.
    //    また, 284 の約数は 1, 2, 4, 71, 142 なので d(284) = 220 である.
    //    
    //    それでは10000未満の友愛数の和を求めよ.
    
    using namespace std;
    
    const int mLIMT = 10000;
    map<int,int> aliquotMAP; // i,d(i) のmap
    int i = 1;
    
    // mLimtまでの因数分解を行い，正の整数とそれの真の約数の和のmapを作る。
    while (i < mLIMT) {
        aliquotMAP.insert( map<int,int>::value_type(i, calTrueAliquot(factorize(i))) );
        ++i;
    }
    
    // 友愛数があるかどうかを調査し，存在すればその和を求める.
    unsigned int sumOfAliquot = 0;

    map<int,int>::iterator it = aliquotMAP.begin();
    while (it != aliquotMAP.end()) {
        int i = it -> first;
        int d = it -> second;
        if (i != d && i == aliquotMAP[d]) {
            sumOfAliquot += i ;
        }
        ++it;
    }
    cout << "Answer: "  << sumOfAliquot ;
    return 0;
}


std::map<int, int> factorize(unsigned int n)
{
    // 引数を因数分解して 因数とその乗数を返す
    // map<int,int> で first が因数，secondが乗数
    
    using namespace std;

    map<int, int> divDic ;
    
    divDic.insert(map<int, int>::value_type(1,1)) ; // 1は必ず約数になるので無条件に入れる
    if (n == 1) {
        return divDic;
    } else if (n % 2 == 0){
        divDic.insert(map<int,int>::value_type(2,divisor(n, 2))) ; // まずは2で割れるだけ割っておく。
        n = n / pow(2,divDic[2]); //divDic[2]は2の指数
    }
    
    for (int i = 3; i <= sqrt(n); i += 2) {
        if ( n % i == 0) {
            divDic.insert(map<int,int>::value_type(i,divisor(n, i)));
            n = n / pow(i, divDic[i]);
        }
    }
    if (n != 1) {
        divDic.insert(map<int,int>::value_type(n,1));
    }
    
    return divDic ;
}


int divisor(unsigned int n,long i)
{
    // 被除数 n と除数 i を受け取って n が何回 i で割れたかを返す。
    
    int index = 0 ;
    
    while (n % i == 0) {
        n = n / i;
        index++;
    }
    
    return index;
}

int calTrueAliquot(std::map<int,int> factMap)
{
    // 真の約数の和を求める。真の約数の和はすべての約数の和から自分自身を減じたもの。d(n)
    // 約数の和は ある自然数 N が N = ｐaｑb・・・ｒc 　　（p<q<・・・<r　は素数、a,b, ... ,c　は 0 以上の整数）
    // と表現されるとき以下で求められる。
    //  S = (p^(a+1)-1/p-1) * (q^(b+1)-1/q-1) … *(r^(c+1)-1/r-1)
    
    using namespace std;
    unsigned int sum = 1;
    unsigned int mySelf = 1;
    
    map<int,int>::iterator it = factMap.begin();
    while (it != factMap.end()) {
        int p = it -> first;
        int a = it -> second;
        if (p > 1) {
            mySelf *= pow(p,a);
            sum *= (pow(p,a+1)-1)/(p-1);
        }
        ++it;
    }

    int amicableN = sum - mySelf ;
    return amicableN;
}

void showFactlialPair(std::map<int,int> Map)
{
    // 受け取ったmapの要素のすべて(firstとsecond)を出力する。
    // デバッグ用

    using namespace std;
    
    map<int,int>::iterator it = factMap.begin();
    while (it != factMap.end()) {
        cout << it->first << " : " << it->second << endl;
        ++it;
    }
    cout << endl;
}





