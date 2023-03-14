# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    recipe.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 17:13:04 by irifarac          #+#    #+#              #
#    Updated: 2023/03/14 21:33:29 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

cookbook = { 'Bocadillo': {'ingredients': ['jamon', 'pan', 'queso', 'tomate'], 'meal': 'lunch', 'prep_time': '10'},
			'Tarta': {'ingredients': ['harina', 'azucar', 'huevos'], 'meal': 'dessert', 'prep_time': '60'},
			'Ensalada': {'ingredients': ['aguacate', 'rucula', 'tomates',
			'espinacas'], 'meal': 'lunch', 'prep_time': '15'}}

def	print_name():
	for key in cookbook:
		print(key)

def	print_details():
	print("Please enter a recipe to get its details:")
	for name in sys.stdin:
		name = name.rstrip()
		break
	print(" Recipe for  {0}".format(name))
	print(" Ingredients list: {0}".format(cookbook[name]['ingredients']))
	print(" To be eaten for {0}.".format(cookbook[name]['meal']))
	print(" Takes {0} minutes of cooking.".format(cookbook[name]['prep_time']))


def	delete_key():
	print("Please enter a recipe name to delete:")
	for name in sys.stdin:
		name = name.rstrip()
		break
	if name in cookbook:
		del cookbook[name]

def	take_argv():
	print("Process to add a new recipe")
	print("Enter a name:")
	for name in sys.stdin:
		name = name.rstrip()
		break
	print("Enter ingredients:")
	i = 0
	lst = []
	for ingredients in sys.stdin:
		if i >= 2:
			break
		else:
			i += 1
		ingredients = ingredients.rstrip('\n')
		lst.append(ingredients.strip())

	print("Enter a meal type:")
	for meal in sys.stdin:
		meal = meal.rstrip()
		break
	print("Enter a preparation time:")
	prep = input()
	ingre = {'ingredients': [lst[0], lst[1]], 'meal': meal, 'prep_time': prep}
	cookbook[name] = ingre

if __name__ == '__main__':
	#take_argv()
	print("Welcome to the Python Cookbook !")
	print("List of available option:")
	print("	1: Add a recipe")
	print("	2: Delete a recipe")
	print("	3: Print a recipe")
	print("	4: Print the cookbook")
	print("	5: Quit")
	while True:
		print("Please select an option:")
		choice = int(input())
		if (choice == 1):
			take_argv()
		elif (choice == 2):
			delete_key()
		elif (choice == 3):
			print_details()
		elif (choice == 4):
			print(cookbook)
		elif (choice == 5):
			print("Cookbook closed. Goodbye !")
			break
		else:
			print('\033[91m' + "Sorry, this option does not exist." + '\033[0m')
