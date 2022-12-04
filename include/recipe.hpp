/**
 ******************************************************************************
 * @file     recipe.hpp
 * @brief    Header file for the Recipe class
 *           
 ******************************************************************************
 * @attention
 * 
 *  Licensed under the Apache License v2.0
 *  Contributor(s): Vincent TEMPLIER
 * 
 ******************************************************************************
 */

#ifndef __RECIPE_HPP__
#define __RECIPE_HPP__

#include <map>
#include <vector>

class Recipe;

// A Cookbook is a list of recipes
typedef std::map<std::string, Recipe> Cookbook;

class Recipe {
public:
    Recipe();
    Recipe(std::string name, 
           std::vector<std::pair<std::string, int>> ingredients);

    bool operator< (const Recipe& recipe) const;
    bool operator<= (const Recipe& recipe) const;
    bool operator== (const Recipe& recipe) const;

    std::string getName() const;
    std::vector<std::pair<std::string, int>> getIngredients() const;

    ~Recipe(){};

    friend std::ostream& operator<< (std::ostream& os, const Recipe& recipe);
    friend std::istream& operator>> (std::istream& is, Recipe& recipe);

private:
    std::string name;
    std::vector<std::pair<std::string, int>> ingredients;

};

#endif  // __RECIPE_HPP__