

#include <iostream>

using namespace std;


int main(int argc, const char * argv[])
{
    
    long long self2 = 0;
    long long sum2 = 0;

    for (int i=1; i<=100; i++) {
        self2 = i*i + self2;
        sum2 = i+sum2;
    }
    
    sum2 = sum2*sum2;
    
    long long ans = 0;
    if (self2 > sum2) {
        ans =self2-sum2;
    }else{
        ans = sum2 - self2;
    }
    
    cout << ans << endl ;
    
    
    return 0;
}

