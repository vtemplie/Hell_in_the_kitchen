/**
 ******************************************************************************
 * @file     recipe.cpp
 * @brief    Source file for the Recipe class
 *           
 ******************************************************************************
 * @attention
 * 
 *  Licensed under the Apache License v2.0
 *  Contributor(s): Vincent TEMPLIER
 * 
 ******************************************************************************
 */

#include "recipe.hpp"
#include <iostream>

Recipe::Recipe()
{
    // ctor
}

Recipe::Recipe(std::string name, std::vector<std::pair<std::string, int>> ingredients)
{
    this->name = name;
    this->ingredients = ingredients;
}

bool Recipe::operator< (const Recipe& recipe) const
{
    return name < recipe.name;
}

bool Recipe::operator<= (const Recipe& recipe) const
{
    return name <= recipe.name;
}

bool Recipe::operator== (const Recipe& recipe) const
{
    return name == recipe.name;
}

std::string Recipe::getName() const
{
    return name;
}

std::vector<std::pair<std::string, int>> Recipe::getIngredients() const
{
    return ingredients;
}

std::ostream& operator<< (std::ostream& os, const Recipe& recipe)
{
    os << recipe.name << ":" << std::endl;
    for (auto ingredient : recipe.ingredients) {
        os << ingredient.first << " " << ingredient.second << std::endl;
    }
    return os;
}

std::istream& operator>> (std::istream& is, Recipe& recipe)
{
    is >> recipe.name;

    std::string line;
    int quantite;

    is >> line;
    while(is && line!="---") {
        is >> quantite;
        recipe.ingredients.push_back(std::make_pair(line, quantite));
        is >> line;
    }
    return is;
}
