#include "Gene.h"





Gene::Gene(int hp, float speed, int reproduceChance)
{
	fitness = 0;
}

int Gene::GetHp()
{
	return hp;
}

float Gene::GetSpeed()
{
	return speed;
}

int Gene::GetReproduceChance()
{
	return reproduceChance;
}

std::vector<int> Gene::GetStepsVector()
{
	return steps;
}

void Gene::AddStepToVector(int step)
{
	steps.push_back(step);
}

void Gene::SetHp(int hp)
{
	this->hp += hp;
}

void Gene::SetSpeed(float speed)
{
	this->speed = speed;
}

void Gene::SetReproductionChance(int repChance)
{
	this->reproduceChance = repChance;
}

void Gene::SetFitness(int fitness)
{
	this->fitness += fitness;
}

Gene::~Gene()
{
}
