
#include <gmpxx.h>
#include <gmp.h>
#include <iostream>
#include <string>
#include <sstream>
	

using namespace std;


int main(int argc, const char * argv[])
{

    mpz_class r;
//    mpz_t r;
//    mpz_init(r);
    mpz_ui_pow_ui(r,2,1000);
    
    //string s = "10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376";

    string s ;
    mpz_get_str(s,10,r);

    int sum = 0;
    for (int i = 0; i< s.length(); i++) {
        sum +=  char(s.at(i) - '0');
    }
    
    cout << sum << endl;
    
    return 0;
}

