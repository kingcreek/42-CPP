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
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
}

/*
Better, but using a pointer? "<A*>..."
void identify(Base& p);
It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden

void identify(Base& p) {
    if (dynamic_cast<A*>(&p))
        std::cout << "A";
    else if (dynamic_cast<B*>(&p))
        std::cout << "B";
    else if (dynamic_cast<C*>(&p))
        std::cout << "C";
}
*/

void identify(Base& p){
	try {
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A";
	}
	catch (std::exception&) {}
	try {
		B& b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "B";
	}
	catch (std::exception&) {}
	try {
		C& c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "C";
	}
	catch (std::exception&) {}
}

void print_ptr_ref(Base *r)
{
	std::cout << "ptr: ";
	identify(r);
	std::cout << std::endl;
	std::cout << "reference: ";
	identify(*r);
	std::cout << std::endl;
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
		if (!rnd)
			continue ;
		print_ptr_ref(rnd);
		std::cout << "-----" << std::endl;
		delete rnd;
	}
	
	std::cout << "============" << std::endl;
	std::cout << "=  ERRORS  =" << std::endl;
	std::cout << "============" << std::endl;
	std::cout << std::endl;
	
	std::cout << "TEST NULL:" << std::endl;
	identify(NULL);
	std::cout << "TEST 0:" << std::endl;
	identify(0);
    return (0);
}
