#include <iostream>
#include <vector>
#include <time.h>

#include "PoBaRoTe/pokemon.cpp"

using namespace std;

typedef unsigned short int poke;
typedef vector<poke> trainer;

vector<unsigned short int> validPokemons;
vector<trainer> trainers;

vector<pokemon> pokedex;


// SETTINGS
unsigned short int teamSize = 3;
unsigned short int trainersNumber = 4;

unsigned short int firstPokeNumber = 1;
unsigned short int lastPokeNumber = 719;
// END SETTINGS

void fillPokedex();
void getGenerationSettingsFromUser();
void fillVectorWithValidPokemons();
bool isValidPokemonAccordingToSettings(unsigned short int p);
void randomizeTeams();
	unsigned short int selectRandomPokemon();
void printResults();
	void printTrainer(unsigned short int t);

int main()
{
	// Initialize random seed.
	srand (time(NULL));
	// Fill pokedex
	fillPokedex();

	// Get settings from user
	getGenerationSettingsFromUser();
	// Prepare set of valid Pokemon numbers
	fillVectorWithValidPokemons();
	// Randomize teams
	randomizeTeams();
	// Print results
	printResults();

	system("pause");


	return 0;
}

void fillPokedex()
{
	// TR TODO: Make some database for dat shieeet

	// pokemon(int number, string name, int generation, int type1, int type2, vector<unsigned short int> additionalTypes,
	// bool isLegendary, bool hasEvolution, bool hasMegaEvolution, bool hasAlolaForm);

	pokedex.push_back(pokemon(1, "Bulbasaur", 1, GRASS, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(2, "Ivysaur", 1, GRASS, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(3, "Venusaur", 1, GRASS, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasMegaEvolution(true);
	pokedex.push_back(pokemon(4, "Charmander", 1, FIRE, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(5, "Charmeleon", 1, FIRE, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(6, "Charizard", 1, FIRE, FLYING, {DRAGON}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasMegaEvolution(true);
	pokedex.push_back(pokemon(7, "Squirtle", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(8, "Wartortle", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(9, "Blastoise", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasMegaEvolution(true);
	pokedex.push_back(pokemon(10, "Caterpie", 1, BUG, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(11, "Metapod", 1, BUG, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(12, "Butterfree", 1, BUG, FLYING, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(13, "Weedle", 1, BUG, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(14, "Kakuna", 1, BUG, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(15, "Beedrill", 1, BUG, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasMegaEvolution(true);
	pokedex.push_back(pokemon(16, "Pidgey", 1, NORMAL, FLYING, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(17, "Pidgeotto", 1, NORMAL, FLYING, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(18, "Pidgeot", 1, NORMAL, FLYING, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasMegaEvolution(true);
	pokedex.push_back(pokemon(19, "Rattata", 1, NORMAL, NONE, {DARK}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasAlolaForm(true);
	pokedex.push_back(pokemon(20, "Raticate", 1, NORMAL, NONE, {DARK}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasAlolaForm(true);
	pokedex.push_back(pokemon(21, "Spearow", 1, NORMAL, FLYING, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(22, "Fearow", 1, NORMAL, FLYING, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(23, "Ekans", 1, POISON, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(24, "Arbok", 1, POISON, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(25, "Pikachu", 1, ELECTRIC, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(26, "Raichu", 1, ELECTRIC, NONE, {PSYCHIC}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasAlolaForm(true);
	pokedex.push_back(pokemon(27, "Sandshrew", 1, GROUND, NONE, {ICE, STEEL}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasAlolaForm(true);
	pokedex.push_back(pokemon(28, "Sandslash", 1, GROUND, NONE, {ICE, STEEL}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasAlolaForm(true);
	pokedex.push_back(pokemon(29, "Nidoran F", 1, POISON, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(30, "Nidorina", 1, POISON, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(31, "Nidoqueen", 1, POISON, GROUND, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(32, "Nidoran M", 1, POISON, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(33, "Nidorino", 1, POISON, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(34, "Nidoking", 1, POISON, GROUND, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(35, "Clefairy", 1, FAIRY, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(36, "Clefable", 1, FAIRY, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(37, "Vulpix", 1, FIRE, NONE, {ICE}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasAlolaForm(true);
	pokedex.push_back(pokemon(38, "Ninetails", 1, FIRE, NONE, {ICE, FAIRY}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasAlolaForm(true);
	pokedex.push_back(pokemon(39, "Jigglypuff", 1, NORMAL, FAIRY, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(40, "Wigglytuff", 1, NORMAL, FAIRY, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(41, "Zubat", 1, POISON, FLYING, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(42, "Golbat", 1, POISON, FLYING, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(43, "Oddish", 1, GRASS, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(44, "Gloom", 1, GRASS, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(45, "Vileplume", 1, GRASS, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(46, "Paras", 1, BUG, GRASS, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(47, "Parasect", 1, BUG, GRASS, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(48, "Venonat", 1, BUG, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(49, "Venomoth", 1, BUG, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(50, "Diglett", 1, GROUND, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(51, "Dugtrio", 1, GROUND, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(52, "Meowth", 1, NORMAL, NONE, {DARK}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasAlolaForm(true);
	pokedex.push_back(pokemon(53, "Persian", 1, NORMAL, NONE, {DARK}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasAlolaForm(true);
	pokedex.push_back(pokemon(54, "Psyduck", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(55, "Golduck", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(56, "Mankey", 1, FIGHTING, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(57, "Primeape", 1, FIGHTING, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(58, "Growlithe", 1, FIRE, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(59, "Arcanine", 1, FIRE, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(60, "Poliwag", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(61, "Poliwhirl", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(62, "Poliwrath", 1, WATER, FIGHTING, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(63, "Abra", 1, PSYCHIC, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(64, "Kadabra", 1, PSYCHIC, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(65, "Alakazam", 1, PSYCHIC, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(66, "Machop", 1, FIGHTING, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(67, "Machoke", 1, FIGHTING, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(68, "Machamp", 1, FIGHTING, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(69, "Bellsprout", 1, GRASS, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(70, "Weepinbell", 1, GRASS, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(71, "Victreebell", 1, GRASS, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(72, "Tentacool", 1, WATER, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(73, "Tentacruel", 1, WATER, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(74, "Geodude", 1, ROCK, GROUND, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(75, "Graveler", 1, ROCK, GROUND, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(76, "Golem", 1, ROCK, GROUND, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(77, "Ponyta", 1, FIRE, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(78, "Rapidash", 1, FIRE, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(79, "Slowpoke", 1, WATER, PSYCHIC, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(80, "Slowbro", 1, WATER, PSYCHIC, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(81, "Magnemite", 1, ELECTRIC, STEEL, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(82, "Magneton", 1, ELECTRIC, STEEL, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(83, "Farfetch'd", 1, NORMAL, FLYING, {}));
	pokedex.push_back(pokemon(84, "Doduo", 1, NORMAL, FLYING, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(85, "Dodrio", 1, NORMAL, FLYING, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(86, "Seel", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(87, "Dewgong", 1, WATER, ICE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(88, "Grimer", 1, POISON, NONE, {DARK}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(89, "Dodrio", 1, POISON, NONE, {DARK}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(90, "Shellder", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(91, "Cloyster", 1, WATER, ICE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(92, "Gastly", 1, GHOST, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(93, "Haunter", 1, GHOST, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(94, "Gengar", 1, GHOST, POISON, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasMegaEvolution(true);
	pokedex.push_back(pokemon(95, "Onix", 1, ROCK, GROUND, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(96, "Drowzee", 1, PSYCHIC, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(97, "Hypno", 1, PSYCHIC, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(98, "Krabby", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(99, "Kingler", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(100, "Voltorb", 1, ELECTRIC, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(101, "Electrode", 1, ELECTRIC, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(102, "Exeggcute", 1, GRASS, PSYCHIC, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(103, "Exeggutor", 1, GRASS, PSYCHIC, {DRAGON}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasAlolaForm(true);
	pokedex.push_back(pokemon(104, "Cubone", 1, GROUND, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(105, "Marowak", 1, GROUND, NONE, {FIRE, GHOST}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasAlolaForm(true);
	pokedex.push_back(pokemon(106, "Hitmonlee", 1, FIGHTING, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(107, "Hitmonchan", 1, FIGHTING, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(108, "Lickitung", 1, NORMAL, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(109, "Koffing", 1, POISON, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(110, "Weezing", 1, POISON, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(111, "Rhyhorn", 1, GROUND, ROCK, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(112, "Rhydon", 1, GROUND, ROCK, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(113, "Chansey", 1, NORMAL, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(114, "Tangela", 1, GRASS, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(115, "Kangaskhan", 1, NORMAL, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasMegaEvolution(true);
	pokedex.push_back(pokemon(116, "Horsea", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(117, "Seadra", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(118, "Goldeen", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(119, "Seaking", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(120, "Staryu", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(121, "Starmie", 1, WATER, PSYCHIC, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(122, "Mr. Mime", 1, PSYCHIC, FAIRY, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(123, "Scyther", 1, BUG, FLYING, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(124, "Jynx", 1, ICE, PSYCHIC, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(125, "Electabuzz", 1, ELECTRIC, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(126, "Magmar", 1, FIRE, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(127, "Pinsir", 1, BUG, NONE, {FLYING}));
	pokedex.at(pokedex.size()-1).setHasMegaEvolution(true);
	pokedex.push_back(pokemon(128, "Tauros", 1, NORMAL, NONE, {}));
	pokedex.push_back(pokemon(129, "Magikarp", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(130, "Gyarados", 1, WATER, FLYING, {DARK}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasMegaEvolution(true);
	pokedex.push_back(pokemon(131, "Lapras", 1, WATER, ICE, {}));
	pokedex.push_back(pokemon(132, "Ditto", 1, NORMAL, NONE, {}));
	pokedex.push_back(pokemon(133, "Eevee", 1, NORMAL, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(134, "Vaporeon", 1, WATER, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(135, "Jolteon", 1, ELECTRIC, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(136, "Flareon", 1, FIRE, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(137, "Porygon", 1, NORMAL, NONE, {}));
	pokedex.push_back(pokemon(138, "Omanyte", 1, ROCK, WATER, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(139, "Omastar", 1, ROCK, WATER, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(140, "Kabuto", 1, ROCK, WATER, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(141, "Kabutops", 1, ROCK, WATER, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(142, "Aerodactyl", 1, ROCK, FLYING, {}));
	pokedex.at(pokedex.size()-1).setHasMegaEvolution(true);
	pokedex.push_back(pokemon(143, "Snorlax", 1, NORMAL, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(144, "Articuno", 1, ICE, FLYING, {}));
	pokedex.at(pokedex.size()-1).setIsLegendary(true);
	pokedex.push_back(pokemon(145, "Zapdos", 1, ELECTRIC, FLYING, {}));
	pokedex.at(pokedex.size()-1).setIsLegendary(true);
	pokedex.push_back(pokemon(146, "Moltres", 1, FIRE, FLYING, {}));
	pokedex.at(pokedex.size()-1).setIsLegendary(true);
	pokedex.push_back(pokemon(147, "Dratini", 1, DRAGON, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(148, "Dragonair", 1, DRAGON, NONE, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.at(pokedex.size()-1).setHasEvolution(true);
	pokedex.push_back(pokemon(149, "Dragonite", 1, DRAGON, FLYING, {}));
	pokedex.at(pokedex.size()-1).setHasPreevolution(true);
	pokedex.push_back(pokemon(150, "Mewtwo", 1, PSYCHIC, NONE, {}));
	pokedex.at(pokedex.size()-1).setIsLegendary(true);
	pokedex.push_back(pokemon(151, "Mew", 1, PSYCHIC, NONE, {}));
	pokedex.at(pokedex.size()-1).setIsLegendary(true);

























}

//
void getGenerationSettingsFromUser()
{

}

// Method used to fill validPokemons.
void fillVectorWithValidPokemons()
{
	// For each Pokemon number
	for(unsigned short int p = firstPokeNumber; p < lastPokeNumber; ++p)
	{
		// Check if this Pokemon is valid in terms of settings.
		if(isValidPokemonAccordingToSettings(p))
		{
			// If it is add it to list
			validPokemons.push_back(p);
		}
	}
}

// Check if Pokemon (given by no.) is a valid Pokemon according to user settings.
bool isValidPokemonAccordingToSettings(unsigned short int p)
{
	return true;
}

// Create randomized team according to user defined settings.
void randomizeTeams()
{
	// For each trainer
	for(unsigned short int t = 0; t < trainersNumber; ++t)
	{
		// Add new trainer to trainers vector
		trainers.push_back(trainer());

		// For each Pokemon that trainer should have
		for(unsigned short int p = 0; p < teamSize; ++p)
		{
			// Select random Pokemon from valid Pokemons and add it to trainer
			trainers.at(t).push_back(selectRandomPokemon());
		}
	}
}

// Draws Pokemon from validPokemons vector.
unsigned short int selectRandomPokemon()
{
	unsigned short int pokemonIndex = rand() % validPokemons.size();
	return validPokemons.at(pokemonIndex);
}

// Prints all trainers with their teams.
void printResults()
{
	// For each trainer
	for(unsigned short int t = 0; t < trainers.size(); ++t)
	{
		// Print this trainer and his/hers Pokemons
		printTrainer(t);
	}
}

// Prints single trainer's data.
void printTrainer(unsigned short int t)
{
	// Initialize trainers data with the number of trainer.
	string trainersData = "Trainer " + to_string(t) + ": ";

	// For each Pokemon in trainers team.
	for(unsigned short int p = 0; p < trainers.at(t).size(); ++p)
	{
		// Add its number to trainersData.
		trainersData += to_string(trainers.at(t).at(p)) +", ";
	}

	// Delete last 2 chars (as it's only coma and space).
	trainersData = trainersData.substr(0, trainersData.size()-2);

	// Print trainer's data.
	cout << trainersData << endl;
}