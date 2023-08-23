/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:27:46 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/23 13:45:08 by irifarac         ###   ########.fr       */
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
	int	tmp;

	tmp = 0;
	if (m_numbers.size() % 2 != 0)
	{
		tmp = m_numbers.back();
		m_numbers.pop_back();
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
	/*std::cout << "------final result----" << std::endl;
	std::vector<int>	result = createSequence(sortedPairs, tmp, true);
	for (size_t i = 0; i < result.size(); i++)
		std::cout << result[i] << " ";*/
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

	if (len > 0)
		insertionSort(pairs);
}

//std::vector<std::vector<int> >	PmergeMe::insertionSort(std::vector<std::vector<int> > &pair,
//int len)
void	PmergeMe::insertionSort(std::vector<std::vector<int> > &pair)
{
//	std::cout << "len en insertionSort: " << len << std::endl;
	/*if (len < 1)
		return (pair);
	else
	{
		insertionSort(pair, len - 1);
		std::cout << "entro aqui len es: " << len  << std::endl;
	//	std::cout << "pair len key es: " << pair[len][0] << std::endl;
		insert(pair[len], pair, len - 1);
		return (pair);
	}*/
	int					j;
	std::vector<int>	key;

	for (size_t i = 1; i <= pair.size(); i++)
	{
		key = pair[i];
		std::cout << "key 0: " << key[0] << " key 1 es: " << key[1] << std::endl;
		j = i - 1;
		std::cout << "pair j 1 es: " << pair[j][1] << std::endl;
		std::cout << "j es: " << j << std::endl;
		while (j >= 0 && key[1] < pair[j][1])
		{
			pair[j + 1] = pair[j];
			std::cout << "pair j es: " << pair[j][1] << std::endl;
			std::cout << "pair j + 1 es: " << pair[j+1][1] << std::endl;
			j = j - 1;
		}
		pair[j + 1] = key;
	}
}

/*void	PmergeMe::insert(std::vector<int> &element,
std::vector<std::vector<int> > &pairs, int len)
{
	std::vector<int>	elementCopy = element;

	std::cout << "len es: " << len << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		for (size_t j = 0; j < pairs[i].size(); j++)
			std::cout << "value: " << pairs[i][j] << std::endl;
	}
	if (len < 0)
	{
		std::cout << "entro en len 0" << std::endl;
		pairs.insert(pairs.begin(), element);
	}
	else if (element[1] >= pairs[len][1])
	{
		std::cout << "entro en element 1 > pairs len 1" << std::endl;
		std::cout << "element 1: " << element[1] << std::endl;
		std::cout << " len es: " << len << std::endl;
		std::cout << "pairs len es: " << pairs[len][1] << std::endl;
		for (size_t i = 0; i < pairs.size(); i++)
		{
			for (size_t j = 0; j < pairs[i].size(); j++)
				std::cout << "value: " << pairs[i][j] << std::endl;
			std::cout << "pair: " << i << std::endl;
		}
		pairs.insert(pairs.begin() + len + 1, element);
	}
	else
	{
	//	std::cout << " entro en else" << std::endl;
		for (size_t i = 0; i < pairs.size(); i++)
		{
			for (size_t j = 0; j < pairs[i].size(); j++)
				std::cout << "value: " << pairs[i][j] << std::endl;
			std::cout << "pair: " << i << std::endl;
		}
		int	tmpLen = len;
	//	std::cout << "len antes while: " << len << std::endl;
	//	std::cout << "element 1 es: " <<  element[1] << " pair es: " << pairs[len][1] << std::endl;
		while (len >= 0 && element[1] < pairs[len][1])
			len--;
	//	std::cout << "element es: " <<  element[0] << " " <<  element[1] << std::endl;
	//	std::cout << "len es: " << len << " y tmplen: " << tmpLen <<  std::endl;
		pairs.insert(pairs.begin() + len + 1, element);
	//	std::cout << "element copy es: " <<  elementCopy[0] << elementCopy[1] << std::endl;
	//	std::cout << "pairs es: " << pairs[tmpLen + 2][1] << std::endl;
		if (elementCopy[1] == pairs[tmpLen + 2][1])
		{
			std::cout << "entro en if" <<std::endl;
			pairs.erase(pairs.begin() + tmpLen + 2);
		}
		for (size_t i = 0; i < pairs.size(); i++)
		{
			for (size_t j = 0; j < pairs[i].size(); j++)
				std::cout << "value despues: " << pairs[i][j] << std::endl;
	//		std::cout << "pair: " << i << std::endl;
		}

	}
}*/

int	PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n -1) + 2 * jacobsthal(n - 2));
}

std::vector<int>	PmergeMe::build_jacob_seq(const std::vector<int> &pairs)
{
	int					pair_len = pairs.size();
	std::vector<int>	end_seq;
	int					jacob_index = 3;

	while (jacobsthal(jacob_index) < pair_len - 1)
	{
		end_seq.push_back(jacobsthal(jacob_index));
		jacob_index++;
	}
	return (end_seq);
}

std::vector<int>	PmergeMe::createSequence(std::vector<std::vector<int> > &sortedPairs,
int tmp, bool print)
{
	std::vector<int>	sequence;
	std::vector<int>	pend;
	int					comparisons_made;
	int					item;

	comparisons_made = 0;
	item = 0;
	for (size_t i = 0; i < sortedPairs.size(); i++)
	{
		sequence.push_back(sortedPairs[i][1]);
		pend.push_back(sortedPairs[i][0]);
	}
	sequence.insert(sequence.begin(), pend[0]);
	int					it = 0;
	int					jacob_index = 3;
	std::vector<int>	index_sequence;
	std::string			last = "default";
	std::vector<int>	jacob_insert_seq = build_jacob_seq(pend);
	while (it <= static_cast<int>(pend.size()))
	{
		if (!jacob_insert_seq.empty() && last != "jacob")
		{
			int	jacob_value = jacob_insert_seq[0];
			index_sequence.push_back(jacob_value);
			item = pend[jacob_value - 1];
			jacob_insert_seq.erase(jacob_insert_seq.begin());
			last = "jacob";
		}
		else
		{
			item = pend[it];
			if (std::find(index_sequence.begin(), index_sequence.end(), it) != index_sequence.end())
				it++;
			index_sequence.push_back(it);
			last = "not-jacob";
		}
		int	insertion_point = std::lower_bound(sequence.begin(), sequence.end(), item) - sequence.begin();
		sequence.insert(sequence.begin() + insertion_point, item);
		it++;
		jacob_index++;
		comparisons_made += 2;
	}
	if (tmp)
	{
		int	insertion_point = std::lower_bound(sequence.begin(), sequence.end(), tmp) - sequence.begin();
		sequence.insert(sequence.begin() + insertion_point, tmp);
		comparisons_made += 2;
	}
	if (print)
	{
		std::cout << "approximate comparisons made: " << comparisons_made << std::endl;
	}
	return (sequence);
}
