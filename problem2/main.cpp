//
//  main.cpp
//  PEP002
//
//  Created by urn5684 on 2013/01/27.
//  Copyright (c) 2013年 urn5684 . All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{

    /* problem2
        フィボナッチ数列の項は前の2つの項の和である. 最初の2項を 1, 2 とすれば, 最初の10項は以下の通りである.
        1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
    
        数列の項の値が400万を超えない範囲で, 偶数値の項の総和を求めよ.
        Note:この問題は最近更新されました. お使いのパラメータが正しいかどうか確認してください.
    */
    

    // まずやってみる
    //　フィボナッチ数を生成し偶数だったら順次足し合わせていく
    
    const int MAX_CNT = 4000000;
    int sum = 0;
    
    int fn=0,fn1=0,fn2=1;
    for (int i=1; fn<MAX_CNT; i++) {
        fn = fn1+fn2;
        fn2 = fn1;
        fn1 = fn;
        if (fn % 2 == 0) {
            sum += fn;
        }
    }
    
    std::cout << sum << std::endl;
    return 0;
}

