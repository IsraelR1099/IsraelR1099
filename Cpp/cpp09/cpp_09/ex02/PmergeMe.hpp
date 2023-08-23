/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:25:56 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/23 13:45:11 by irifarac         ###   ########.fr       */
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
		std::vector<std::vector<int> >	createPairs(const std::vector<int> &numbers);
		std::vector<std::vector<int> >	sort_pairs(std::vector<std::vector<int> > &pairs);
		void
		sortByLarger(std::vector<std::vector<int> > &pairs);
	//	std::vector<std::vector<int> >
	//	insertionSort(std::vector<std::vector<int> > &pair, int len);
		void							insertionSort(std::vector<std::vector<int> > &pair);
		void							insert(std::vector<int> &element,
		std::vector<std::vector<int> > &pairs, int len);
		std::vector<int>				createSequence(std::vector<std::vector<int> > &sortedPairs,											int tmp, bool print);
		std::vector<int>				build_jacob_seq(const std::vector<int> &pairs);
		int								jacobsthal(int n);
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
};
#endif
