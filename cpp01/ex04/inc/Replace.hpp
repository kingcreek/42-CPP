/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:06:08 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/13 18:55:54 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

class Replace
{
	
	private:
		std::string _infile;
		std::string _outFile;

	public:
		Replace(std::string file);
		~Replace();
		
		void	search_and_replace(std::string s1, std::string s2);
};

#endif