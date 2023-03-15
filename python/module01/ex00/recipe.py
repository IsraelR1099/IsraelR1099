# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    recipe.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 18:43:39 by irifarac          #+#    #+#              #
#    Updated: 2023/03/15 21:07:26 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

class Recipe:
	def	__init__(self, name, cooking_lvl, cooking_time, ingredients,
	description, recipe_type):
		if not isinstance(name, str):
			sys.exit("name has to be a string")
		elif not isinstance(cooking_lvl, int) or not isinstance(cooking_time, int):
			sys.exit("cooking lvl and cooking time have to be int")
		self.name = name
		self.cooking_lvl = cooking_lvl
		self.cooking_lvl = cooking_lvl
		self.ingredients = ingredients
		self.description = description
		self.recipe_type = recipe_type
	def __str__(self):
		'''Return the string to print with the recipe infor'''
		txt = ""
		return txt

if __name__ == '__main__':
	paella = Recipe("Paella", 3, "hola", ["pollo", "arroz"], "Todo", "lunch")
	print(paella.name, paella.cooking_lvl)
