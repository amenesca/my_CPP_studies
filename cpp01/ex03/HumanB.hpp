#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {

private:
	Weapon weapon;
	std::string name;
public:
	HumanB(void);
	~HumanB(void);
	void attack(void);
};

#endif