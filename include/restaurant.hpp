/**
 ******************************************************************************
 * @file     restaurant.hpp
 * @brief    Header file for the restaurant functions
 *           
 ******************************************************************************
 * @attention
 * 
 *  Licensed under the Apache License v2.0
 *  Contributor(s): Vincent TEMPLIER
 * 
 ******************************************************************************
 */

#ifndef __RESTAURANT_HPP__
#define __RESTAURANT_HPP__

#include "recipe.hpp"
#include "inventory.hpp"

/**
 * @brief Add a recipe to the cookbook from a stream
 * 
 * @param orderfile Stream to get the recipe
 * @param book      Cookbook where to add the recipe
*/
void add_recipe(std::istream& orderFile, Cookbook& book);

/**
 * @brief Receive food items from a stream and place them in the inventory
 * 
 * @param orderfile Stream to get the items
 * @param inventory Inventory where to add food items
 * @param date      Reception date of the items 
 *                  (used to update the current date)
*/
void receive_food(std::istream& orderFile, Inventory& inventory, Date& date);

/**
 * @brief Check if the order can be prepared
 * @details The function performs the following actions
 *          1. Update the current date (used to remove all expired food)
 *          2. Get from @p orderfile all required ingredients
 *          3. Remove all expired ingredients
 *          4. Analyse the inventory to see if the order is possible
 *          5. If the order is possible, remove all required ingredients
 * 
 * @param orderFile     Stream to get the items
 * @param book          Cookbook where to check required food items
 * @param inventory     Inventory where to check food items
 * @param current_date  Date of the order (used for comparison with exiperd ingredients)
 * @return              Returns true if the order is possible
*/
bool book_order(std::istream& orderFile, 
                Cookbook book, 
                Inventory& inventory,
                Date& current_date);

/**
 * @brief Interpret the orders from the stream
 * @details Gets the order and perform one of these actions
 *          * Add a recipe if the order is "recipe"
 *          * Place food items in the inventory if the order is "reception"
 *          * Check if a booking is possible if the order is "booking"
 *          For every order, it repeats the process
 * 
 * @param orderFile Stream of the order file
 * @return          Status of the order (1 if error, 0 otherwise)
*/
int restaurant_manager(std::istream& orderFile);


#endif // __RESTAURANT_HPP__