
#include <iostream>
#include <sstream>
#include <string>

bool IsLoopNum(unsigned int);

int main(int argc, const char * argv[])
{

    // 左右どちらから読んでも同じ値になる数を回文数という. 2桁の数の積で表される回文数のうち, 最大のものは 9009 = 91 × 99 である.
    // では, 3桁の数の積で表される回文数のうち最大のものを求めよ.
 
    // 積を求めて回文数になっているかどうかの手法で

    unsigned int num = 0;
    
    for (int i=999; i>0; i--) {
        for (int j=999; j>-1; j--) {
            num = i*j;
            if (IsLoopNum(num) == true) {
                std::cout << num << std::endl;
            }
        }
    }
 
    return 0;
}


//回文数になっているかのチェック
bool  IsLoopNum(unsigned int n)
{
    
    // c++には文字列反転のメソッドとかない？
    // まだなれてないので後回し

    std::stringstream ss ;
    ss << n << std::endl ;
    
    return 0;
}

