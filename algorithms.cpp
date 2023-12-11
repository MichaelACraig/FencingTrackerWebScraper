#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;

#define F 100000

int main() {
	ofstream file;
	file.open("C:/Users/rcest/Desktop/DAS/final/dataset.csv", ios::out);

	// names and club names generated by chatGPT
	string firstName;
	int firstNameIndex;
	string firstNames[100] = { "Emma", "Liam", "Olivia", "Noah", "Ava", "Sophia", "Jackson", "Isabella", "Lucas", "Mia", "Aiden", "Harper", "Elijah", "Abigail", "Ethan", "Emily", "Oliver",
		"Madison", "Amelia", "Logan", "Ella", "Carter", "Scarlett", "Benjamin", "Grace", "Henry", "Lily", "Samuel", "Chloe", "Alexander", "Avery", "Daniel", "Sofia", "Matthew", "Aria", "Joseph", "Layla", "David", "Addison", 
		"William", "Victoria", "James", "Lily", "Ava", "Mia", "Zoe", "Alexander", "Evelyn", "Sophia", "Benjamin", "Grace", "Olivia", "Harper", "Emma", "Aiden", "Liam", "Jackson", "Noah", "Lucas", "Mia", "Olivia", "Isabella", 
		"Sophia", "Ava", "Amelia", "Harper", "Evelyn", "Abigail", "Ella", "Scarlett", "Grace", "Lily", "Chloe", "Aria", "Isla", "Riley", "Zoe", "Nora", "Scarlett", "Lucy", "Hazel", "Ellie",
		"Stella", "Aaliyah", "Savannah", "Aubrey", "Penelope", "Victoria", "Madison", "Luna", "Aria", "Grace", "Skylar", "Evelyn", "Zara", "Aurora", "Bella", "Mila", "Hannah", "Paisley" };

	string lastName;
	int lastNameIndex;
	string lastNames[100] = { "Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor", "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Garcia", "Martinez",
		"Robinson", "Clark", "Rodriguez", "Lewis", "Lee", "Walker", "Hall", "Allen", "Young", "Hernandez", "King", "Wright", "Lopez", "Hill", "Scott", "Green", "Adams", "Baker", "Gonzalez", "Nelson", "Carter", "Mitchell",
		"Perez", "Roberts", "Turner", "Phillips", "Campbell", "Parker", "Evans", "Edwards", "Collins", "Stewart", "Sanchez", "Morris", "Rogers", "Reed", "Cook", "Morgan", "Bell", "Murphy", "Bailey", "Rivera", "Cooper",
		"Richardson", "Cox", "Howard", "Ward", "Torres", "Peterson", "Gray", "Ramirez", "James", "Watson", "Brooks", "Kelly", "Sanders", "Price", "Bennett", "Wood", "Barnes", "Ross", "Henderson", "Coleman", "Jenkins",
		"Perry", "Powell", "Long", "Patterson", "Hughes", "Flores", "Washington", "Butler", "Simmons", "Foster", "Gonzales", "Bryant", "Alexander", "Russell", "Griffin", "Diaz", "Hayes" };

	string club;
	int clubIndex;
	string clubs[100] = { "Swift Sabres Fencing Club", "Noble Foil Academy", "Steel Enclave Fencing Society", "Luminous �p�e Guild", "Rapid Riposte Institute", "Vanguard Blade Collective", "Celestial Rapier Consortium", 
		"Phoenix Parry Club", "Ethereal Edge Alliance", "Majestic Sabre Syndicate", "Valiant Vanguard Fencers", "Sapphire Slash Club", "Fierce Foil Fellowship", "Lunar Lunge League", "Crimson Clash Association", "Gallant Guard Guild",
		"Pinnacle Parry House", "Enigma �p�e Ensemble", "Stellar Sword Society", "Aegis Assault Club", "Noble Nimbus Fencing", "Virtuoso Vorpal Vault", "Onyx Olympiad Fencers", "Vivacious Vector Vanguards", "Zenith Zorro Zephyr", 
		"Ecliptic En Garde Academy", "Infinite Impale Institute", "Dynamic Duel Den", "Radiant Riposte Republic", "Sable Sabre Society", "Crestfallen Cutlass Club", "Fabled Fencer Fortress", "Epic �p�e Enclave", "Prowess Parry Pavilion", 
		"Mystic Marauder Ma�tre", "Ethereal Edge Ensemble", "Rogue Rapier Realm", "Lustrous Lunge Lodge", "Fervent Foil Fellowship", "Harmony Hilt Haven", "Seraphic Sabre Syndicate", "Lunar Lance Legion", "Blazing Blade Brigade", 
		"Astral Assault Academy", "Vivid Valiant Vortex", "Velvet Verge Vanguards", "Paragon Parry Pavilion", "Nimble Nimbus Network", "Mystical Musketeer Manor", "Jade Joust Jamboree", "Fabled Fencer Fraternity", "Zephyr Zenith Zorro",
		"Virtuoso Vector Vault", "Enchanted �p�e Empire", "Thunder Thrust Tribe", "Obsidian Olympiad Order", "Eternal Edge Ensemble", "Radiant Rapier Refuge", "Sapphire Slash Sanctuary", "Pinnacle Parry Palace", "Crimson Crest Club", 
		"Gallant Glaive Guild", "Onyx Olympiad Order", "Valiant Vector Vigil", "Ecliptic �p�e Escapade", "Infinite Impale Inn", "Dynamic Duel Den", "Radiant Riposte Retreat", "Sable Sabre Stronghold", "Crestfallen Cutlass Castle", 
		"Fabled Fencer Fortress", "Prowess Parry Palace", "Mystic Marauder Mansion", "Ethereal Edge Estate", "Rogue Rapier Retreat", "Lustrous Lunge Lodge", "Fervent Foil Fort", "Harmony Hilt Haven", "Seraphic Sabre Sanctuary", 
		"Lunar Lance Lair", "Blazing Blade Bastion", "Astral Assault Asylum", "Vivid Valiant Villa", "Velvet Verge Venue", "Paragon Parry Pavilion", "Nimble Nimbus Nest", "Mystical Musketeer Manor", "Jade Joust Jungle", "Fabled Fencer Fellowship", 
		"Zephyr Zenith Zorro Zone", "Virtuoso Vector Vortex", "Enchanted �p�e Enclave", "Thunder Thrust Territory", "Obsidian Olympiad Outpost", "Eternal Edge Edifice", "Radiant Rapier Refuge", "Sapphire Slash Shelter", "Pinnacle Parry Precinct", 
		"Crimson Crest Citadel", "Gallant Glaive Garrison" };

	int totalWins;
	int totalLoses;
	float winRatio;

	int poolWins;
	int poolLoses;
	float poolWinRatio;

	int deWins;
	int deLosses;
	float deWinRatio;

	srand(2);

	for (int i = 0; i < F; i++ ) {
		firstNameIndex = rand() % 100;
		firstName = firstNames[firstNameIndex];

		lastNameIndex = rand() % 100;
		lastName = lastNames[lastNameIndex];

		string name = "test " + firstName + " " + lastName;

		clubIndex = rand() % 100;
		club = clubs[clubIndex];

		int temp;

		totalWins = (rand() % 100) + 1;
		totalLoses = (rand() % 100) + 1;
		if (totalWins > totalLoses) {
			temp = totalLoses;
			totalLoses = totalWins;
			totalWins = temp;
		}
		winRatio = float(totalWins) / totalLoses * 100;

		poolWins = (rand() % 50) + 1;
		poolLoses = (rand() % 50) + 1;
		if (poolWins > poolLoses) {
			temp = poolLoses;
			poolLoses = poolWins;
			poolWins = temp;
		}
		poolWinRatio = float(poolWins) / poolLoses * 100;

		deWins = (rand() % 50) + 1;
		deLosses = (rand() % 50) + 1;
		if (deWins > deLosses) {
			temp = deLosses;
			deLosses = deWins;
			deWins = temp;
		}
		deWinRatio = float(deWins) / deLosses * 100;

		// add fencer to csv file
		file << name << "," << club << "," << totalWins << "," <<
			totalLoses << "," << winRatio << "%" << "," << poolWins << "," << poolLoses << "," <<
			poolWinRatio << "%" << "," << deWins << "," << deLosses << "," << deWinRatio << "%" << "\n";
		cout << "\%" << float(i) / F * 100 << endl;		
	}

	return 0;
}