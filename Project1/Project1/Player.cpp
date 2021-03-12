#include "Player.h"
#include <iostream>

Player::Player()
	: number(0), age(0)
{
	std::cout << "One way of building initializer" << std::endl;
}

Player::Player(int age, int number)
{
	this->number = number;
	this->age = age;
	std::cout << "Other way of building initializer" << std::endl;
}

Player::~Player()
{
	std::cout << "Destructor called!" <<std::endl;
}

void Player::setNumber(const int number)
{
	this->number = number;
}

void Player::setAge(const int age)
{
	this->age = age;
}

void Player::info()
{
	std::cout << "Number: " << this->number << "  Age: " << this->age << std::endl;
}

