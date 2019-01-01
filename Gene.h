#pragma once
#include<vector>
class Gene
{
	int hp;
	float speed;
	int reproduceChance;
	std::vector<int> steps;
	//fitness?
	int fitness;
public:
	Gene(int hp, float speed, int reproduceChance);
	int GetHp();
	float GetSpeed();
	int GetReproduceChance();
	std::vector<int> GetStepsVector();
	void AddStepToVector(int step);
	void SetHp(int hp);
	void SetSpeed(float speed);
	void SetReproductionChance(int repChance);
	void SetFitness(int fitness);
	~Gene();
};

