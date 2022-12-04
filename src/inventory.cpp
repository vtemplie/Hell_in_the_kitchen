/**
 ******************************************************************************
 * @file     inventory.cpp
 * @brief    Source file for the Inventory class
 *           
 ******************************************************************************
 * @attention
 * 
 *  Licensed under the Apache License v2.0
 *  Contributor(s): Vincent TEMPLIER
 * 
 ******************************************************************************
 */

#include "inventory.hpp"
#include <iostream>

Inventory::Inventory()
{
    // ctor
}

void Inventory::add(Food item, Date date_exp, int quantity)
{
    if (stockTotal.find(item) == stockTotal.end()) {
        stockTotal[item] = quantity;
        stockPackage[item][date_exp] = quantity;
    } else {
        stockTotal[item] += quantity;
        stockPackage[item][date_exp] += quantity;
    }
}

void Inventory::clean(Food item, Date date)
{
    unsigned int quantityToThrowAway = 0;

    if (stockPackage.find(item) != stockPackage.end()) {
        std::map<Date, int>::iterator itErase = stockPackage[item].begin();

        for (std::map<Date, int>::iterator it = stockPackage[item].begin(); 
             it != stockPackage[item].end(); 
             ++it) 
        {
            if (it->first <= date) {
                quantityToThrowAway += it->second;
                it->second = 0;
            } else {
                itErase = it;
                break;
            }
        }
        if (quantityToThrowAway > 0)
            stockPackage[item].erase(stockPackage[item].begin(), itErase);
    }

    stockTotal[item] -= quantityToThrowAway;
}

bool Inventory::check(Food item, int quantity)
{
    bool isTotalEnough = false;
    if (stockTotal.find(item) != stockTotal.end()) {
        isTotalEnough = (stockTotal[item] >= quantity);
    }
    return isTotalEnough;
}

void Inventory::remove(Food item, int quantity)
{
    stockTotal[item] -= quantity;

    if (stockPackage.find(item) != stockPackage.end() && quantity > 0) {
        std::map<Date, int>::iterator itErase = stockPackage[item].begin();
        
        for (std::map<Date, int>::iterator it = stockPackage[item].begin(); 
             it != stockPackage[item].end(); 
             ++it) 
        {
            if (it->second < quantity) {
                quantity -= it->second;
                it->second = 0;
            } else {
                it->second -= quantity;
                quantity = 0;
                itErase = it;
                break;
            }
        }
        stockPackage[item].erase(stockPackage[item].begin(), itErase);
    }
}

void Inventory::display()
{
    std::cout << "Inventory :" << std::endl;
    for (std::map<Food, int>::iterator it = stockTotal.begin();
         it != stockTotal.end();
         ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}
