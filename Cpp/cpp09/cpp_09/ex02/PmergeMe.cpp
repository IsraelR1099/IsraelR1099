/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:27:46 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/22 23:34:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(int counter, char **str)
{
	int	i;

	i = 1;
	while (i < counter)
	{
		std::string			tmp(str[i]);
		std::istringstream	iss(tmp);
		std::string			buff;

		while (std::getline(iss, buff, ' '))
		{
			if (!buff.empty() && validData(buff) == false)
			{
				throw (BadArgument("Error: invalid data"));
			}
			if (buff.empty())
				continue ;
			m_numbers.push_back(static_cast<int>(std::strtod(buff.c_str(), NULL)));
		}
		i++;
	}
	mergeInsertionSort();
}

PmergeMe::PmergeMe(const PmergeMe &obj) : m_numbers(obj.m_numbers)
{
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	if (this == &obj)
		return (*this);
	m_numbers = obj.m_numbers;
	return (*this);
}

bool	PmergeMe::validData(std::string &str)
{
	char	*tmp = NULL;
	double	value;

	value = std::strtod(str.c_str(), &tmp);
	if (value == 0.0 && !std::isdigit(str[0]))
		return (false);
	if (tmp[0] != '\0' && std::strcmp(tmp, "f"))
		return (false);
	if (value < 0)
		return (false);
	return (value == static_cast<int>(value));
}

void	PmergeMe::mergeInsertionSort(void)
{

	if (m_numbers.size() % 2 != 0)
	{
		int tmp = m_numbers.back();
		m_numbers.pop_back();
		(void)tmp;
	}
	std::vector<std::vector<int> >	pairs = createPairs(m_numbers);
	std::cout << "---------unsorted pairs" << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		for (size_t j = 0; j < pairs[i].size(); j++)
		{
			std::cout << pairs[i][j] << " ";
			std::cout << "first pair" << std::endl;
		}
		std::cout << "second pair" << std::endl;
	}
	std::vector<std::vector<int> >	sortedPairs = sort_pairs(pairs);
	std::cout << "-----sorted pairs---------" << std::endl;
	for (size_t i = 0; i < sortedPairs.size(); i++)
	{
		for (size_t j = 0; j < sortedPairs[i].size(); j++)
		{
			std::cout << sortedPairs[i][j] << " ";
			std::cout << "first pair" << std::endl;
		}
		std::cout << "second pair" << std::endl;
	}
	std::cout << "---------sorted by larger------" << std::endl;
	sortByLarger(sortedPairs);
	for (size_t i = 0; i < sortedPairs.size(); i++)
	{
		for (size_t j = 0; j < sortedPairs[i].size(); j++)
		{
			std::cout << sortedPairs[i][j] << " ";
			std::cout << "first pair" << std::endl;
		}
		std::cout << "second pair" << std::endl;
	}
	createSequence(sortedPairs);

}

//in order to follow the FJMI, the values must be arbitrarily sorted into
//pairs. We use the functions createPairs, which loops through the vector
std::vector<std::vector<int> > PmergeMe::createPairs(const std::vector<int> &numbers)
{
	std::vector<std::vector<int> >	pairs;
	std::vector<int>				tmp;

	for (size_t i = 0; i < numbers.size(); i++)
	{
		size_t	tmpLen = tmp.size();

		if (tmpLen == 1)
		{
			tmp.push_back(numbers[i]);
			pairs.push_back(tmp);
			tmp.clear();
		}
		else if (pairs.size() * 2 == numbers.size() - 1)
			tmp.push_back(numbers[i]);
		else if (tmpLen == 0)
			tmp.push_back(numbers[i]);
	}
	return (pairs);
}

//Once the array is created and paired, we use sort_pairs to sort the pairs.
//This functions loops through the pairs and place the smaller number on the
//left and the larger number on the right.
std::vector<std::vector<int> >
PmergeMe::sort_pairs(std::vector<std::vector<int> > &pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].size() != 1 && pairs[i][0] > pairs[i][1])
		{
			int tmp = pairs[i][0];
			pairs[i][0] = pairs[i][1];
			pairs[i][1] = tmp;
		}
	}
	return (pairs);
}

//We recursively sort all the pairs by their largest element.
void	PmergeMe::sortByLarger(std::vector<std::vector<int> > &pairs)
{
	int	len = pairs.size();

	insertionSort(pairs, len - 1);
}
void	PmergeMe::insertionSort(std::vector<std::vector<int> > &pair, int len)
{
	if (len < 1)
		return ;
	else
	{
		insertionSort(pair, len - 1);
		insert(pair[len], pair, len - 1);
	}
}

void	PmergeMe::insert(std::vector<int> &element,
std::vector<std::vector<int> > &pairs, int len)
{
	if (len < 0)
		pairs[0] = element;
	else if (element[1] >= pairs[len][1])
	{
		if (len == static_cast<int>(pairs.size() - 1))
			pairs.push_back(element);
		else
			pairs[len + 1] = element;
	}
	else
	{
		if (len == static_cast<int>(pairs.size() - 1))
			pairs.push_back(pairs[len]);
		else
		{
			pairs[len + 1] = pairs[len];
			insert(element, pairs, len - 1);
		}
	}
}
