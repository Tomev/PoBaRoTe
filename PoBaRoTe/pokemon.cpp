#include "pokemon.h"

pokemon::pokemon(int number, string name, int generation, int type1, int type2,
                 vector<unsigned short int> additionalTypes, bool isLegendary, bool hasEvolution, bool hasMegaEvolution,
                 bool hasAlolaForm) :
								number(number), name(name), generation(generation), type1(type1), type2(type2),
								additionalTypes(additionalTypes),	isLegendary(isLegendary), hasEvolution(hasEvolution),
								hasMegaEvolution(hasMegaEvolution), hasAlolaForm(hasAlolaForm)
{}

string pokemon::getInfo()
{
	return "pokemonInfo";
}