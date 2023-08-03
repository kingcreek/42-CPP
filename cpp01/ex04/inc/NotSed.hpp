/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotSed.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:06:08 by imurugar          #+#    #+#             */
/*   Updated: 2023/07/31 10:15:12 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOTSED_HPP
#define NOTSED_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

class NotSed
{
	
	private:
		std::string _infile;
		std::string _outFile;

	public:
		NotSed(std::string file);
		~NotSed();
		
		void	search_and_replace(std::string s1, std::string s2);
};

#endif