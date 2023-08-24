/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:25:56 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/24 23:42:56 by irifarac         ###   ########.fr       */
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

/*class	PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(int counter, char **str);
		PmergeMe(const PmergeMe &obj);
		~PmergeMe(void);
		PmergeMe &operator=(const PmergeMe &obj);

		bool							validData(std::string &str);
		void							mergeInsertionSort(void);
		std::vector<std::vector<int> >	createPairs(const std::vector<int> &numbers);
		std::vector<std::vector<int> >	sort_pairs(std::vector<std::vector<int> > &pairs);
		void
		sortByLarger(std::vector<std::vector<int> > &pairs);
		void							insertionSort(std::vector<std::vector<int> > &pair);
		void							insert(std::vector<int> &element,
		std::vector<std::vector<int> > &pairs, int len);
		void							mergeSort(std::vector<int> &array,
		const int begin, const int end);
		void							merge(std::vector<int> &array, const int left, const int middle, const int right);
		void							insertElement(std::vector<int> &array, const int element);
		int								findPosition(std::vector<int> &array, const int element);
		void							print(void);
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
		std::vector<int>	m_numbers;
		std::vector<int>	m_numbersBefore;
		clock_t				m_start;
		clock_t				m_end;
};*/

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
		std::vector<std::vector<int> >	createPairs(const InnerContainer &numbers);
		std::vector<std::vector<int> >	sort_pairs(OuterContainer &pairs);
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
		void							print(void);
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
		std::vector<int>	m_numbers;
		std::vector<int>	m_numbersBefore;
		std::deque<int>		m_numbersDeque;
		std::deque<int>		m_numbersDequeBefore;
		clock_t				m_start;
		clock_t				m_end;
};
#endif
