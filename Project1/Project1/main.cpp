#include <iostream>
#include <cfloat>
#include "Player.h"


int main()
{
#ifdef _DEBUG
	std::cout << "Hello" << std::endl;
#endif

	Player player1;

	// player1.age; - C2248 error proba dostepu do prywatnego atrybutu klasy Player
	// blad wykryty podczas kompilacji, wiec program sie nie uruchomi

	player1.setAge(26);
	player1.setNumber(13);
	player1.info();

	Player player2;
	player2.info();

	// x = 5;  C2065 error undelared identifier; niezadeklarowany identyfikator,
	// blad wykryty podczas kompilacji

	/*
	*char finished = 'y';
	*while (finished = 'y')
	*{
	*	std::cout << "continue? (y/n)" << std::endl;
	*	std::cin >> finished;
	*}
	* C6282 warning, przypisanie stalej w kontekscie Boolean, program sie uruchomi,
	* ale petla bedzie wykonywana w nieskonczonosc
	*/

	float bank_balance{ FLT_MAX };
	std::cout.precision(2);
	std::cout << std::fixed << bank_balance << std::endl;
}


