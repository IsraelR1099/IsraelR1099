/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:27:46 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/25 09:40:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename OuterContainer, typename InnerContainer>
PmergeMe<OuterContainer, InnerContainer>::PmergeMe(void) : m_numbers(), m_numbersBefore()
{
	return ;
}

template <typename OuterContainer, typename InnerContainer>
PmergeMe<OuterContainer, InnerContainer>::PmergeMe(int counter, char **str)
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
			m_numbersBefore.push_back(static_cast<int>(std::strtod(buff.c_str(), NULL)));
		}
		i++;
	}
	//mergeInsertionSort();
}

template <typename OuterContainer, typename InnerContainer>
PmergeMe<OuterContainer, InnerContainer>::PmergeMe(const PmergeMe &obj) : m_numbers(obj.m_numbers)
{
}

template <typename OuterContainer, typename InnerContainer>
PmergeMe<OuterContainer, InnerContainer>::~PmergeMe(void)
{
	return ;
}

template <typename OuterContainer, typename InnerContainer>
PmergeMe<OuterContainer, InnerContainer> &PmergeMe<OuterContainer, InnerContainer>::operator=(const PmergeMe &obj)
{
	if (this == &obj)
		return (*this);
	m_numbers = obj.m_numbers;
	return (*this);
}

template <typename OuterContainer, typename InnerContainer>
bool	PmergeMe<OuterContainer, InnerContainer>::validData(std::string &str)
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

template <typename OuterContainer, typename InnerContainer>
void	PmergeMe<OuterContainer, InnerContainer>::mergeInsertionSort(void)
{
	int		tmp;
	bool	odd = false;

	tmp = 0;
	if (m_numbers.size() % 2 != 0)
	{
		odd = true;
		tmp = m_numbers.back();
		m_numbers.pop_back();
	}
	OuterContainer	pairs = createPairs(m_numbers);
	OuterContainer	sortedPairs = sort_pairs(pairs);
	sortByLarger(sortedPairs);
	m_numbers.clear();
	for (size_t i = 0; i < sortedPairs.size(); i++)
	{
		for (size_t j = 0; j < sortedPairs[i].size(); j++)
			m_numbers.push_back(sortedPairs[i][j]);
	}
	mergeSort(m_numbers, 0, m_numbers.size() - 1);
	if (odd == true)
		insertElement(m_numbers, tmp);
}

//in order to follow the FJMI, the values must be arbitrarily sorted into
//pairs. We use the functions createPairs, which loops through the vector
template <typename OuterContainer, typename InnerContainer>
OuterContainer	PmergeMe<OuterContainer, InnerContainer>::createPairs(const InnerContainer &numbers)
{
	OuterContainer	pairs;
	InnerContainer	tmp;

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
template <typename OuterContainer, typename InnerContainer>
OuterContainer	PmergeMe<OuterContainer, InnerContainer>::sort_pairs(OuterContainer &pairs)
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

template <typename OuterContainer, typename InnerContainer>
void	PmergeMe<OuterContainer, InnerContainer>::sortByLarger(OuterContainer &pairs)
{
	int	len = pairs.size();

	if (len > 0)
		insertionSort(pairs);
}

template <typename OuterContainer, typename InnerContainer>
void	PmergeMe<OuterContainer, InnerContainer>::insertionSort(OuterContainer &pair)
{
	int					j;

	for (size_t i = 1; i < pair.size(); i++)
	{
		InnerContainer key = pair[i];
		j = i - 1;
		while (j >= 0 && key[1] < pair[j][1])
		{
			pair[j + 1] = pair[j];
			j--;
		}
		pair[j + 1] = key;
	}
}

template <typename OuterContainer, typename InnerContainer>
void	PmergeMe<OuterContainer, InnerContainer>::mergeSort(InnerContainer &array, const int begin, const int end)
{
	if (begin >= end)
		return ;
	int	mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

template <typename OuterContainer, typename InnerContainer>
void	PmergeMe<OuterContainer, InnerContainer>::merge(InnerContainer &array, const int left, const int mid, const int right)
{
	const int	subArrayOne = mid - left + 1;
	const int	subArrayTwo = right - mid;

	InnerContainer	leftArray(subArrayOne);
	InnerContainer	rightArray(subArrayTwo);

	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];
	int	indexOne = 0;
	int	indexTwo = 0;
	int	indexMerged = left;

	while (indexOne < subArrayOne && indexTwo < subArrayTwo)
	{
		if (leftArray[indexOne] <= rightArray[indexTwo])
		{
			array[indexMerged] = leftArray[indexOne];
			indexOne++;
		}
		else
		{
			array[indexMerged] = rightArray[indexTwo];
			indexTwo++;
		}
		indexMerged++;
	}
	while (indexOne < subArrayOne)
	{
		array[indexMerged] = leftArray[indexOne];
		indexOne++;
		indexMerged++;
	}
	while (indexTwo < subArrayTwo)
	{
		array[indexMerged] = rightArray[indexTwo];
		indexTwo++;
		indexMerged++;
	}
}

template <typename OuterContainer, typename InnerContainer>
void	PmergeMe<OuterContainer, InnerContainer>::insertElement(InnerContainer &array, const int element)
{
	int	position = findPosition(array, element);
	array.insert(array.begin() + position, element);
}

template <typename OuterContainer, typename InnerContainer>
int	PmergeMe<OuterContainer, InnerContainer>::findPosition(InnerContainer &array, const int element)
{
	for (size_t i = 0; i < array.size(); i++)
	{
		if (element <= array[i])
			return (i);
	}
	return (array.size());
}

template <typename OuterContainer, typename InnerContainer>
void
PmergeMe<OuterContainer, InnerContainer>::print(const std::string str, const std::string str2, double result, double result2)
{
	std::cout << "Before: ";
	for (size_t i = 0; i < m_numbersBefore.size(); i++)
		std::cout << m_numbersBefore[i] << " ";
	std::cout << std::endl;
	std::cout << "After: ";
	for (size_t i = 0; i < m_numbers.size(); i++)
		std::cout << m_numbers[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << m_numbers.size()
	<< " elements with " << str << " is "
	<< result / CLOCKS_PER_SEC << " seconds" << std::endl;
	std::cout << "Time to process a range of " << m_numbers.size()
	<< " elements with " << str2 << " is "
	<< result2 / CLOCKS_PER_SEC << " seconds" << std::endl;
}
