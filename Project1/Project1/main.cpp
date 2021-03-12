#include <iostream>
#include "Player.h"


int main() 
{
#ifdef _DEBUG
	std::cout << "Hello" << std::endl;
#endif 

	Player player1;

	// player1.age; - C2248 error próba dostêpu do prywatnego atrybutu klasy Player
	// b³¹d wykryty podczas kompilacji, wiêc program siê nie uruchomi

	player1.setAge(26);
	player1.setNumber(13);
	player1.info();

	Player player2;
	player2.info();
	
	// x = 5;  C2065 error undelared identifier; niezadeklarowany identyfikator,
	// b³¹d wykryty podczas kompilacji

	/*
	*char finished = 'y';
	*while (finished = 'y')
	*{
	*	std::cout << "continue? (y/n)" << std::endl;
	*	std::cin >> finished;
	*}
	* C6282 warning, przypisanie sta³ej w kontekœcie Boolean, program siê uruchomi, 
	* ale pêtla bêdzie wykonywana w nieskoñczonoœæ
	*/ 

	float bank_balance{ FLT_MAX };
	std::cout.precision(2);
	std::cout << std::fixed << bank_balance << std::endl;
}


