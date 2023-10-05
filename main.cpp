#include <iostream>
#include "main.h"
#include<cmath>

int main()
{
    //For value; 1012.22;                                               Expected output
    double value_1 = 1012.22;
    double value_2 = 152666.52;

    std::cout<<count_digits(value_1)<<std::endl;                          //      4
    std::cout<<extract_decimal(value_1)<<std::endl;                       //      22
    std::cout<<sum_of_digits(extract_decimal(value_1))<<std::endl;        //      4
    std::cout<<is_valid(value_1)<<std::endl;                              //      1
//###########################################################
    //For value; 152666.52
    std::cout<<"#########################"<<std::endl;
    std::cout<<count_digits(value_2)<<std::endl;                          //    6
    std::cout<<extract_decimal(value_2)<<std::endl;                       //    52
    std::cout<<sum_of_digits(extract_decimal(value_2))<<std::endl;        //    7
    std::cout<<is_valid(value_2)<<std::endl;                              //    0
    return 0;
}

