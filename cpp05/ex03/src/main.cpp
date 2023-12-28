/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/27 18:52:20 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{

    {
    Intern RandomIntern;
    AForm* rrf;
    rrf = RandomIntern.makeForm("robotomy request", "Bender");
    delete rrf;
    }
    std::cout << std::endl;
    // Create bureaucrats
    Bureaucrat highGradeBureaucrat("HighGrade", 1);
    Bureaucrat lowGradeBureaucrat("LowGrade", 50);
	
    // Create forms directly
    ShrubberyCreationForm shrubberyForm("Garden");
    RobotomyRequestForm robotomyForm("John Doe");
    PresidentialPardonForm pardonForm("Some Criminal");

    // Create an instance of the Intern
    Intern someRandomIntern;

    // Use the intern to create forms
    AForm *shrubberyFormByIntern = someRandomIntern.makeForm("shrubbery request", "Garden");
    AForm *robotomyFormByIntern = someRandomIntern.makeForm("robotomy request", "John Doe");
    AForm *pardonFormByIntern = someRandomIntern.makeForm("presidential request", "Some Criminal");
    AForm *wrongForm = someRandomIntern.makeForm("NonExistantForm", "Intern"); //Cannot create
    std::cout << std::endl;
    // Attempt to sign/execute forms with bureaucrats
    try {
        highGradeBureaucrat.signForm(shrubberyForm);
        highGradeBureaucrat.signForm(robotomyForm);
        highGradeBureaucrat.signForm(pardonForm);

        // Try to sign a form that doesn't exist
        if (wrongForm)
            highGradeBureaucrat.signForm(*wrongForm);

        highGradeBureaucrat.executeForm(shrubberyForm);
        highGradeBureaucrat.executeForm(robotomyForm);
        highGradeBureaucrat.executeForm(pardonForm);

        // Try to execute forms created by the intern to show they're different than the ones created directly
        if (shrubberyFormByIntern)
            highGradeBureaucrat.executeForm(*shrubberyFormByIntern);
        if (robotomyFormByIntern)
            highGradeBureaucrat.executeForm(*robotomyFormByIntern);
        if (pardonFormByIntern)
            highGradeBureaucrat.executeForm(*pardonFormByIntern);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    // Clean up memory
    delete shrubberyFormByIntern;
    delete robotomyFormByIntern;
    delete pardonFormByIntern;

    return (0);
}
