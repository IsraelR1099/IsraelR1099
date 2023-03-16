# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    recipe.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 18:43:39 by irifarac          #+#    #+#              #
#    Updated: 2023/03/16 12:03:48 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

class Recipe:
    def    __init__(self, name, cooking_lvl, cooking_time, ingredients,
    recipe_type, description=None):
        if not isinstance(name, str):
            sys.exit("name has to be a string")
        elif not isinstance(cooking_lvl, int) or not isinstance(cooking_time, int):
            sys.exit("cooking lvl and cooking time have to be int")
        self.name = name
        if cooking_lvl < 0 or cooking_lvl > 5:
            sys.exit("cooking level must be between 1 and 5")
        self.cooking_lvl = cooking_lvl
        self.cooking_time = cooking_time
        if not isinstance(ingredients, list):
            sys.exit("ingredients must be a list")
        self.ingredients = ingredients
        if recipe_type != "comida" and recipe_type != "entrante" and recipe_type != "postre":
           sys.exit("recipe type must be entrante, comida or postre")
        self.recipe_type = recipe_type
        if description:
            self.description = description
    def __str__(self):
        '''Return the string to print with the recipe infor'''
        txt = "Recipe name: " + self.name + "\n"
        txt += "Cooking level: " + str(self.cooking_lvl) + "\n"
        txt += "Cooking time: " + str(self.cooking_time) + " minutes" + "\n"
        txt += "Ingredients: " + ' '.join(self.ingredients) + "\n"
        return txt

if __name__ == '__main__':
    paella = Recipe("Paella", 5, 60, ["pollo", "arroz"], "comida")
    print(str(paella))
