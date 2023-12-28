/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/28 18:38:34 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
	std::srand(std::time(NULL) - std::rand());
    int rnd = std::rand() % 3;
	switch(rnd)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p){
	try {
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception&) {}
	try {
		B& a = dynamic_cast<B&>(p);
		(void) a;
		std::cout << "B" << std::endl;
	}
	catch (std::exception&) {}
	try {
		C& a = dynamic_cast<C&>(p);
		(void) a;
		std::cout << "C" << std::endl;
	}
	catch (std::exception&) {}
}

void print_ptr_ref(Base *r)
{
	std::cout << "ptr: ";
	identify(r);
	std::cout << "reference: ";
	identify(*r);
	std::cout << "-----" << std::endl;
}
int main() {
	
	std::cout << "============" << std::endl;
	std::cout << "=  Normal  =" << std::endl;
	std::cout << "============" << std::endl;
	std::cout << std::endl;
	Base *a = new A();
	Base *b = new B();
	Base *c = new C();
	
	print_ptr_ref(a);
	print_ptr_ref(b);
	print_ptr_ref(c);

	delete a;
	delete b;
	delete c;
	
	std::cout << std::endl;
	std::cout << "============" << std::endl;
	std::cout << "=  RANDOM  =" << std::endl;
	std::cout << "============" << std::endl;
	std::cout << std::endl;
	
	for (int i(0); i < 5; i++)
	{
		Base *rnd = generate();
		print_ptr_ref(rnd);
		delete rnd;
	}
	
    return (0);
}
