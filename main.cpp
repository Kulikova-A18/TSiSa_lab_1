/**
 ******************************************************************************
 *
 *   Copyright (C) 2023, Kulikova Alyona, IU8-11M, variant.5
 *
 ******************************************************************************
 *
 * @name Laboratory No. 1
 *
 * @file main.cpp
 *
 * <b>Modification History</b>
 *
 *   Date        Name        Description
 *
 ******************************************************************************
 * encoding:   UTF-8 BOM
 * tab size:   4
 */
// -------------
/*
    variant № 5
    Initial data:
        - unimodal function f(x)=-cos0.5x-1 [a,b]=[-2,4]
        - the largest length of the uncertainty interval e = 0.1
    Search method:
        - optimal passive search;
        - golden section
*/

/**
* @brief unimodal_function
* unimodal function f(x)=(x-2)^2 on the segment [a,b]=[0,3]
*
* @param a - minimum, b - maximum on the segment
*
* @return null
*/

#include <iostream>
#include <cmath>
#include <iomanip>

#define CONST_A -2
#define CONST_B 4
#define CONST_E 0.1

/**
* @brief optimal_passive_method
* optimal passive method
*
* @param a - minimum, b - maximum on the segment, E - epsilon
*
* @return null
*/
void optimal_passive_method(double begin, double end, double epsilon);

/**
* @brief golden_ratio_method
* golden ratio method
*
* @param a - minimum, b - maximum on the segment, E - epsilon
*
* @return null
*/
void golden_ratio_method(double begin, double end, double epsilon);

void info() {
    std::cout << "=========================\nKULIKOVA ALYONA IU8-11M\n=========================\n\n";
    std::cout << "variant #5\n";

    std::cout << "=========================\n";
    std::cout << "Initial data:\n";
    std::cout << "- unimodal function f(x)=-cos0.5x-1 [a,b]=[-2,4]\n";
    std::cout << "- the largest length of the uncertainty interval e = 0.1\n";
    std::cout << "Search method:\n";
    std::cout << "- optimal passive search;\n";
    std::cout << "- golden section\n";
    std::cout << "=========================\n";
}

int main() {
    info();
    optimal_passive_method(CONST_A, CONST_B, CONST_E);
    golden_ratio_method(CONST_A, CONST_B, CONST_E);
    return 0;
}
