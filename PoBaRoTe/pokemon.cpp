#include "pokemon.h"

pokemon::pokemon(unsigned short number, string name, unsigned short generation, unsigned short type1, int type2,
                 vector<unsigned short int> additionalTypes, bool isLegendary, bool hasPreevolution, bool hasEvolution,
                 bool hasMegaEvolution, bool hasAlolaForm) :
	number(number), name(name), generation(generation), type1(type1), type2(type2),
	additionalTypes(additionalTypes),	isLegendary(isLegendary), hasPreevolution(hasPreevolution),
	hasEvolution(hasEvolution), hasMegaEvolution(hasMegaEvolution), hasAlolaForm(hasAlolaForm)
{}

pokemon::pokemon(unsigned short number, string name, unsigned short generation, unsigned short type1, int type2,
                 vector<unsigned short int> additionalTypes) :
	number(number), name(name), generation(generation), type1(type1), type2(type2),	additionalTypes(additionalTypes)
{}

void pokemon::setIsLegendary(bool flag)
{
	this->isLegendary = flag;
}

void pokemon::setHasPreevolution(bool flag)
{
	this->hasPreevolution = flag;
}

void pokemon::setHasEvolution(bool flag)
{
	this->hasEvolution = flag;
}

void pokemon::setHasMegaEvolution(bool flag)
{
	this->hasMegaEvolution = flag;
}

void pokemon::setHasAlolaForm(bool flag)
{
	this->hasAlolaForm = flag;
}

string pokemon::getInfo()
{
	return "pokemonInfo";
}