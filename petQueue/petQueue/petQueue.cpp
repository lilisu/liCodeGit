// petQueue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<deque>
#include<list>
using namespace std;
class Pet {
private:
	string type;
public:
	Pet() {}
	Pet(string type)
	{
		this->type = type;
	}
	string getPetType()
	{
		return this->type;
	}
};
class Dog: Pet {
public:
	Dog() :Pet("dog") {}
};
class Cat :Pet {
public:
	Cat():Pet("cat") {}
};
class PetEnterQueue {
private:
	Pet pet;
	long count;
public:
	PetEnterQueue(Pet pet, long count)
	{
		this->pet = pet;
		this->count = count;
	}
	Pet getPet()
	{
		return this->pet;
	}
	long getCount()
	{
		return this->count;
	}
	string getEnterPetType()
	{
		return this->pet.getPetType();
	}
};
class DogCatQueue {
private:
	deque<PetEnterQueue> dogQ;
	deque<PetEnterQueue> catQ;
	long count;
public:
	DogCatQueue()
	{
		this->count = 0;
	}
	void add(Pet pet)
	{
		if (pet.getPetType() == "dog")
		{
			this->dogQ.push_back(PetEnterQueue(pet, this->count++));
		}
		else if (pet.getPetType() == "cat")
		{
			this->catQ.push_back(PetEnterQueue(pet, this->count++));
		}
		else {
			throw runtime_error("err,not dog or cat");
		}
	}
	Pet pollAll()
	{
		if (!this->catQ.empty() && !this->dogQ.empty())
		{
			if (this->catQ.front().getCount() < this->dogQ.front().getCount())
			{
				Pet t = this->catQ.front().getPet();
				this->catQ.pop_front();
				return t;
			}
			else {
				Pet t =  this->dogQ.front().getPet();
				this->dogQ.pop_front();
				return t;
			}

		}
		else if (!this->dogQ.empty())
		{
			Pet t = this->dogQ.front().getPet();
			this->dogQ.pop_front();
			return t;
		}
		else if (!this->catQ.empty())
		{
			Pet t = this->catQ.front().getPet();
			this->catQ.pop_front();
			return t;
		}
		else
		{
			throw runtime_error("err,queue is empty");
		}
	}
	Dog pollDog()
	{
		if (!this->dogQ.empty())
		{
			Pet t = this->dogQ.front().getPet();
			this->dogQ.pop_front();
			return (Dog)t;
		}
	}
};
int main()
{
    return 0;
}

