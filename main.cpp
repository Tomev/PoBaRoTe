#include <iostream>
#include <vector>
#include <time.h>

#include "PoBaRoTe/pokemon.h"

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