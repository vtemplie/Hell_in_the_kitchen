/**
 ******************************************************************************
 * @file     date.hpp
 * @brief    Header file for the Date class
 *           
 ******************************************************************************
 * @attention
 * 
 *  Licensed under the Apache License v2.0
 *  Contributor(s): Vincent TEMPLIER
 * 
 ******************************************************************************
 */

#ifndef __DATE_HPP__
#define __DATE_HPP__

#include <iostream>
#include <cstdio>
#include <assert.h>

class Date{
public:
    Date();
    Date(int d, int h, int m);
    
    bool operator< (const Date& date) const;
    bool operator<= (const Date& date) const;
    bool operator== (const Date&) const;

    ~Date(){};
  
private:
    int days;
    int hours;
    int minutes;

friend std::ostream& operator<< (std::ostream& os, const Date& date);
friend std::istream& operator>> (std::istream& is, Date& date);
};

#endif  // __DATE_HPP__