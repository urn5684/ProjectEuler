

#include <iostream>




int main(int argc, const char * argv[])
{

    using namespace std;
    
    const int glidLength = 1001;
    
    long UR = 1;
    long DR = 1;
    long UL = 1;
    long DL = 1;
    long sum = 0;
    
    for (int i=2; 2*i-1 <= glidLength; i++) {  // 終了条件について　最初が1で以降Gridが一つ大きくなるたびに一辺の数は2n-1ずつ増加する。よって最終的なGridの大きさが　1001 であるので　2n-1 = 1001 を満たした場合が最後となる。だったら501って書けよ。
        UR +=     8*(i-1) ;
        DR += 2 + 8*(i-2) ;
        DL += 4 + 8*(i-2) ;
        UL += 6 + 8*(i-2) ;
        sum += UR+DR+UL+DL ;
        
        //int lineNum =  1 + 2*(i-1);
        //cout << lineNum << " DR : "<< DR << " DL : "  << DL << " UL : " << UL << " UR : " << UR << endl;
    }
    
    cout << "Answer : " << 1 +  sum << endl;
    
    return 0;
}