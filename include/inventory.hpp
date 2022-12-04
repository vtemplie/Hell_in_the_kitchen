/**
 ******************************************************************************
 * @file     inventory.hpp
 * @brief    Header file for the Inventory class
 *           
 ******************************************************************************
 * @attention
 * 
 *  Licensed under the Apache License v2.0
 *  Contributor(s): Vincent TEMPLIER
 * 
 ******************************************************************************
 */

#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__

#include <map>
#include "date.hpp"

typedef std::string Food;

class Inventory {
public:
    Inventory();

    /// @brief Add a Food item into the inventory
    /// @param item Name of the item
    /// @param date_exp Expiration date of the item
    /// @param quantity Number of items to add
    void add(Food item, Date date_exp, int quantity);

    /// @brief Remove each item with a expiration date lower than @p date
    /// @param item Name of the item
    /// @param date Date from which the product is expired
    void clean(Food item, Date date);

    /// @brief Check if the item is present in the inventory 
    ///        with the correct quantity
    /// @param item Name of the item
    /// @param quantity Number of items required
    /// @return True if the item is present with the demanded quantity
    bool check(Food item, int quantity);

    /// @brief Remove a @p quantity number of items
    /// @param item Name of the item
    /// @param quantity Number of items to remove
    void remove(Food item, int quantity);

    /// @brief Display the current state of the inventory
    void display();

    ~Inventory(){};
    
private:
    /// Stock to reference the total number of each item in the inventory
    std::map<Food, int> stockTotal;
    /// Stock to note the expiration dates of each item
    std::map<Food, std::map<Date, int>> stockPackage;

};


#endif  // __INVENTORY_HPP__