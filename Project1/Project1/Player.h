#pragma once


class Player
{
private:
	int number;
	int age;
public:
	Player();

	Player(int age, int number);

	~Player();

	const int& getNumber() const { return number; }
	const int& getAge() const { return age; }

	void setNumber(const int number);

	void setAge(const int age);

	void info();
	
};

