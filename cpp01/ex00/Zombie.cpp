#include "./Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	return ;
}

void Zombie::announce( void )
{
	std::cout << this->name << "Brainzzz" << std::endl;
}

Zombie *Zombie::newZombie( std::string name )
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}

void Zombie::randomChump( std::string name )
{
	Zombie zombie = Zombie(name);
	zombie.announce();
}