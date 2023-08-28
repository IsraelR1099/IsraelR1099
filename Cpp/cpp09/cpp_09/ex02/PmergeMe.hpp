/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:25:56 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/25 11:28:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <exception>
# include <vector>
# include <list>
# include <deque>
# include <sstream>
# include <cstdlib>
# include <cstring>
# include <algorithm>

template <typename OuterContainer, typename InnerContainer>
class	PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(int counter, char **str);
		PmergeMe(const PmergeMe &obj);
		~PmergeMe(void);
		PmergeMe &operator=(const PmergeMe &obj);

		bool							validData(std::string &str);
		void							mergeInsertionSort(void);
		OuterContainer					createPairs(const InnerContainer &numbers);
		OuterContainer					sort_pairs(OuterContainer &pairs);
		void							sortByLarger(OuterContainer &pairs);
		void							insertionSort(OuterContainer &pair);
		void							insert(InnerContainer &element,
													OuterContainer &pairs, int len);
		void							mergeSort(InnerContainer &array,
													const int begin, const int end);
		void							merge(InnerContainer &array, const int left,
													const int middle, const int right);
		void							insertElement(InnerContainer &array, const int element);
		int								findPosition(InnerContainer &array, const int element);
		void							setClock(void);
		void							endClock(void);
		void							setClockDiff(void);
		void							endClockDiff(void);
		void							print(const std::string str, const std::string str2, double result, double result2);
		class	BadArgument : public std::exception
		{
			public:
				BadArgument(const std::string &m_msg) : m_error(m_msg) {}
				virtual const char *what() const throw()
				{
					return (m_error.c_str());
				}
				~BadArgument() throw() {}
			private:
				std::string	m_error;
		};
	private:
		InnerContainer		m_numbers;
		InnerContainer		m_numbersBefore;
};
#include "PmergeMe.tpp"
#endif
