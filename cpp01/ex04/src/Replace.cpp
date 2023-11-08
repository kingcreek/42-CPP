/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:08:46 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/07 04:35:15 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string file) : _infile(file)
{
	this->_outFile = this->_infile + ".replace";
}

Replace::~Replace(void){}

void	Replace::search_and_replace(std::string s1, std::string s2)
{
	std::ifstream   ifs(this->_infile.c_str());
	if(ifs.is_open())
	{
		std::string reading;
		if(std::getline(ifs, reading, '\0'))
		{
			std::ofstream   ofs(this->_outFile.c_str());
			size_t	idx = reading.find(s1);
			if(idx == 0)
			{
				std::cout << "No se puede buscar un texto vacio" << std::endl;
				ifs.close();
				exit(EXIT_FAILURE);
			}
			while(idx != std::string::npos)
			{
				reading.erase(idx, s1.length());
				reading.insert(idx, s2);
				//start after insert to prevent infinite loop, ex: s1 = "o", s2 = "paco"
				idx = reading.find(s1, idx + s2.length());
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
