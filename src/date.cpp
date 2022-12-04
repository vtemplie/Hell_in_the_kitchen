/**
 ******************************************************************************
 * @file     date.cpp
 * @brief    Source file for the Date class
 *           
 ******************************************************************************
 * @attention
 * 
 *  Licensed under the Apache License v2.0
 *  Contributor(s): Vincent TEMPLIER
 * 
 ******************************************************************************
 */

#include "date.hpp"

Date::Date()
    : days(0), hours(0), minutes(0)
{
    // ctor
}

Date::Date(int d, int h, int m)
    : days(d), hours(h), minutes(m)
{
    // ctor
}

bool Date::operator<(const Date& other) const
{
    if (days < other.days)
        return true;
    else if (days == other.days)
    {
        if (hours < other.hours)
            return true;
        else if (hours == other.hours)
        {
            if (minutes < other.minutes)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool Date::operator<=(const Date& other) const
{
    return (*this < other) || (*this == other);
}

bool Date::operator==(const Date& other) const
{
    return (days == other.days) && 
           (hours == other.hours) && 
           (minutes == other.minutes);
}


std::ostream& operator<< (std::ostream& os, const Date& date)
{
    char chaine[40];
    sprintf(chaine, "%dd_%02dh%02dm", date.days, date.hours, date.minutes);
    os << chaine;
    return os;
}

std::istream& operator>> (std::istream& is, Date& date)
{
    char d, m, h, underscore;
    is >> date.days >> d >> underscore >> date.hours >> h >> date.minutes >> m;
    assert(d=='d' && m=='m' && h=='h' && underscore=='_');
    return is;
}