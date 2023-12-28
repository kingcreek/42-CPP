/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:31:18 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/28 17:45:03 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <stdint.h>

typedef struct {
	int value;
    char character;
}	Data;

class Serializer{
	
	private:
		Serializer();
		~Serializer();
		Serializer(Serializer &src);
		Serializer &operator=(Serializer &src);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		
};
#endif
