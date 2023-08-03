/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotSed.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:08:46 by imurugar          #+#    #+#             */
/*   Updated: 2023/07/31 10:45:13 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NotSed.hpp"

NotSed::NotSed(std::string file) : _infile(file)
{
	this->_outFile = this->_infile + ".replace";
}

NotSed::~NotSed(void){}

void	NotSed::search_and_replace(std::string s1, std::string s2)
{
	std::ifstream   ifs(this->_infile.c_str());
	if(ifs.is_open())
	{
		std::string reading;
		if(std::getline(ifs, reading, '\0'))
		{
			std::ofstream   ofs(this->_outFile.c_str());
			size_t	idx = reading.find(s1);
			while(idx != std::string::npos)
			{
				reading.erase(idx, s1.length());
				reading.insert(idx, s2);
				idx = reading.find(s1);
			}
			ofs << reading;
			ofs.close();
		} else
			std::cout << "El archivo está vacio" << std::endl;
		ifs.close();
	} else {
		std::cout << "No se puede abrir el archivo" << std::endl;
		exit(EXIT_FAILURE);
	}
}