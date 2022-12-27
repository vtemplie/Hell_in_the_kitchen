/**
 ******************************************************************************
 * @file     restaurant.cpp
 * @brief    Source file for the restaurant functions
 *           
 ******************************************************************************
 * @attention
 * 
 *  Licensed under the Apache License v2.0
 *  Contributor(s): Vincent TEMPLIER
 * 
 ******************************************************************************
 */

#include "restaurant.hpp"
#include <iostream>

void add_recipe(std::istream& orderFile, Cookbook& book)
{
    Recipe recipe;
    orderFile >> recipe;
    book[recipe.getName()] = recipe;
}


void receive_food(std::istream& orderFile, Inventory& inventory, Date& date)
{
    // Date update
    Date date_reception;
    orderFile >> date_reception;
    date = date_reception;

    std::string food;
    int quantity;
    Date date_exp;
    
    orderFile >> food;
    while (orderFile && food != "---") {
        orderFile >> quantity >> date_exp;
        inventory.add(food, date_exp, quantity);
        orderFile >> food;
    }
}


bool book_order(std::istream& orderFile, 
                Cookbook book, 
                Inventory& inventory,
                Date& current_date)
{
    // Date update
    Date date_order;
    orderFile >> date_order;
    current_date = date_order;

    std::string order;
    int nb_recipe;
    bool isOrderable = true;

    std::map<Food, unsigned int> food_order;
    
    // Retrieve all the orders
    // and calculate the total quantity of each food
    orderFile >> order;
    while (orderFile && order != "---") {
        orderFile >> nb_recipe;
        
        std::vector<std::pair<std::string, int>> ingredients = book[order].getIngredients();
        for (unsigned int i = 0; i < ingredients.size(); ++i) {
            Food food = (Food)ingredients[i].first;
            unsigned int quantity_needed = ingredients[i].second * nb_recipe;
            
            if (food_order.find(food) == food_order.end()) {
                food_order[food] = quantity_needed;
            } else {
                food_order[food] += quantity_needed;
            }
        }
        orderFile >> order;    
    }

    // Clean the inventory depending on the date and the food selected
    for (std::map<Food, unsigned int>::iterator it = food_order.begin();
         it != food_order.end(); 
         ++it) 
    {
        inventory.clean(it->first, current_date);
    }

    // Check if the inventory is enough for the order
    for (std::map<Food, unsigned int>::iterator it = food_order.begin();
         it != food_order.end(); ++it) {
        if (!inventory.check(it->first, it->second)) {
            isOrderable = false;
            break;
        }
    }

    // If the order is possible, remove each food from the inventory
    if (isOrderable) {
        for (std::map<Food, unsigned int>::iterator it = food_order.begin();
             it != food_order.end(); 
             ++it) 
        {
            inventory.remove(it->first, it->second);
        }
    }

    return isOrderable;
}    


int restaurant_manager(std::istream& orderFile)
{
    Cookbook book;
    Inventory inventory;
    
    unsigned int num_order = 0;
    Date current_date;

    while (orderFile) {
        std::string order;
        orderFile >> order;

        if (!orderFile)
            break;

        if (order == "recipe") 
        {
            add_recipe(orderFile, book);
        } 
        else if (order == "reception") 
        {
            receive_food(orderFile, inventory, current_date);
        } 
        else if (order == "booking") 
        {
            bool isOrderable = book_order(orderFile, book, inventory, current_date);
            std::string msg = isOrderable ? "OK" : "FAIL";
            std::cout << num_order << " : " << msg << std::endl;
            ++num_order;
        } 
        else 
        {
            std::cerr << "Unknown order: " << order << std::endl;
            return 1;
        }
    }
    return 0;
}


