
#include <iostream>



double factorial(double);


int main(int argc, const char * argv[])
{
    using namespace std;

    double n = 0;
    
    n = factorial(20);  // 100!なんて計算できねーよ！！
    cout << n << endl;
    return 0;
}

double factorial(double n)
{
    double result = 1;
    double k;
        
        for(k = 1; k <= n; k++) {
            result *= k;
        }
    return result;
}
