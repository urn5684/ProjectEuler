//
//  main.cpp
//
//  Created by urn5684 on 2013/01/27.
//  Copyright (c) 2013年 urn5684. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{

    // ProjectEuler problem1
    // 1000 未満の 3 か 5 の倍数になっている数字の合計を求めよ.
 
    static const int MAX_CNT = 1000;
    int sum = 0;
    
    for (int i=1; i<MAX_CNT;i++){
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    
    std::cout << sum <<std::endl;
    return 0;
}

