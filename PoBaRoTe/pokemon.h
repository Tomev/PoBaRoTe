#ifndef POBAROTE_POKEMON_H
#define POBAROTE_POKEMON_H

#include <string>

using namespace std;

enum types
{
	BUG, DARK, DRAGON, ELECTRIC, FAIRY, FIGHTING, FIRE,	FLYING, GHOST, GRASS, GROUND, ICE,  NORMAL, POISON,	PSYCHIC, ROCK,
	STEEL, WATER
};

#define NONE -1

class pokemon
{
public:
	pokemon(unsigned short number, string name, unsigned short generation, unsigned short type1, int type2,
	        vector<unsigned short int> additionalTypes, bool isLegendary, bool hasPreevolution, bool hasEvolution,
	        bool hasMegaEvolution, bool hasAlolaForm);

	pokemon(unsigned short number, string name, unsigned short generation, unsigned short type1, int type2,
	        vector<unsigned short int> additionalTypes);

	string getInfo();

	void setIsLegendary(bool flag);
	void setHasPreevolution(bool flag);
	void setHasEvolution(bool flag);
	void setHasMegaEvolution(bool flag);
	void setHasAlolaForm(bool flag);

private:
	unsigned short int number;
	unsigned short int generation;

	string name;

	short int type1;
	short int type2;

	vector<unsigned short int> additionalTypes;

	bool isLegendary = false;
	bool hasPreevolution = false;
	bool hasEvolution = false;
	bool hasMegaEvolution = false;
	bool hasAlolaForm = false;
};


#endif //POBAROTE_POKEMON_H
