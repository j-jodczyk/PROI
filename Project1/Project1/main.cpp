#include <iostream>
#include <cfloat>
#include "Player.h"


int main()
{
#ifdef _DEBUG
	std::cout << "Hello" << std::endl;
#endif

	Player player1;

	// player1.age; - C2248 error pr�ba dost�pu do prywatnego atrybutu klasy Player
	// b��d wykryty podczas kompilacji, wi�c program si� nie uruchomi

	player1.setAge(26);
	player1.setNumber(13);
	player1.info();

	Player player2;
	player2.info();

	// x = 5;  C2065 error undelared identifier; niezadeklarowany identyfikator,
	// b��d wykryty podczas kompilacji

	/*
	*char finished = 'y';
	*while (finished = 'y')
	*{
	*	std::cout << "continue? (y/n)" << std::endl;
	*	std::cin >> finished;
	*}
	* C6282 warning, przypisanie sta�ej w kontek�cie Boolean, program si� uruchomi,
	* ale p�tla b�dzie wykonywana w niesko�czono��
	*/

	float bank_balance{ FLT_MAX };
	std::cout.precision(2);
	std::cout << std::fixed << bank_balance << std::endl;
}


