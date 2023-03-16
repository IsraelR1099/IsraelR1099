# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    book.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 10:49:03 by irifarac          #+#    #+#              #
#    Updated: 2023/03/16 19:56:41 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import datetime
import sys
from recipe import Recipe


class Book:
    def __init__(self, name,
            last_update, creation_date,
            recipes_list):
        if isinstance(name, str):
            self.name = name
        else:
            sys.exit("Name must be a string")
        if isinstance(last_update, datetime.date):
            self.last_update = last_update
        else:
            sys.exit("Last update must be a valid date time")
        if isinstance(creation_date, datetime.date):
            self.creation_date = creation_date
        else:
            sys.exit("Creation date must be a valida date time")
        if isinstance(recipes_list, dict):
            self.recipes_list = recipes_list
        else:
            sys.exit("Recipe list must be a valid list")
    def get_recipe_by_name(self, name):
        '''Imprime la receta con el nombre y devuelve la instancia'''
        for i in self.recipes_list:
            if self.recipes_list[i].name == name:
                print(str(self.recipes_list[i]))
                return (self.recipes_list[i])
    def get_recipes_by_types(self, recipe_type):
        '''Devuelve todas las recetas dado un recipe type'''
        print("entro")
        for i in self.recipes_list:
            if self.recipes_list[i].recipe_type == recipe_type:
                print(str(self.recipes_list[i]))

    def add_recipe(self, recipe):
        '''Agrega una receta al libro y actualiza last update'''
        if isinstance(recipe, Recipe):
            print(recipe.recipe_type)
            self.recipes_list[recipe.recipe_type] = recipe
            self.last_update = date.today()
        else:
            print("Not a recipe")


if __name__ == '__main__':
    date = datetime.date(2009, 9, 1)
    creation = datetime.date(2000,10,23)
    patatas = Recipe("Bravas", 2, 30, ["patatas", "salsa"], "entrante")
    paella = Recipe("Paella", 5, 60, ["pollo", "arroz"], "comida")
    arroz = Recipe("Arroz", 1, 20, ["arroz", "sal"], "comida")
    tiramisu = Recipe("Tiramisu", 3, 40, ["cafe", "biscocho"], "postre")
    recipe = { 'entrante': patatas,
            'comida': paella,
            'postre': tiramisu}
    #print(recipe['lunch'].name)
    Potter = Book("Harry Potter", date, creation, recipe)
    history = Book("History", date, creation, recipe)
    #Potter.get_recipe_by_name("Paella")
    Potter.get_recipes_by_types("comida")
    Potter.add_recipe(arroz)
    Potter.get_recipes_by_types("comida")
