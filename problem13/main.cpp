
#include <gmpxx.h>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;



const int FIFTY_DIGIT_NUMs = 100;  // 問題文中で50桁の数が100個と指定されている



int main(int argc, const char * argv[])
{
    mpz_class ln50dig[FIFTY_DIGIT_NUMs];
    mpz_class sum = 0;
    
    ifstream ifs("/Users/taka/tmp/pep13BugnumList.txt");
    string buf;
    
    int i=0;
    while (getline(ifs,buf)) {
        ln50dig[i] = buf;
        sum += ln50dig[i];
        i++;
    }

    string ans;
    ans = sum.get_str();
                                        // 先頭(0)から10文字分
    cout << "Sum: "<< sum << "\nAns: " << ans.substr(0,10) << "  (first ten digits)" << endl;
    
    
    return 0;
}

