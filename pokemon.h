#ifndef POBAROTE_POKEMON_H
#define POBAROTE_POKEMON_H

#include <string>
using namespace std;

enum types
{
	BUG, DARK, DRAGON, ELECTRIC, FAIRY, FIGHTING, FIRE,	FLYING, GHOST, GRASS, GROUND, ICE,  NORMAL, POISON,	PSYCHIC, ROCK,
	STEEL, WATER
};

class pokemon
{
public:
	pokemon(int number, string name, int generation, int type1, int type2, bool hasEvolution,	bool hasMegaEvolution,
					bool hasAlolaForm);
	string getInfo();
private:
	int number;
	int generation;

	string name;

	int type1;
	int type2;

	bool hasEvolution;
	bool hasMegaEvolution;
	bool hasAlolaForm;


};


#endif //POBAROTE_POKEMON_H
