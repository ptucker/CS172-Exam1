#pragma once
#include <string>
#include "Movie.h"
using namespace std;

class TheaterUnsorted {
private:
	int count = 0;			//How many movies are in the theater?
	static const int size = 11;	//How many movies can we hold?
	Movie movies[size];
	const int popcorn = 1;
	const int coke = 2;
	string name;
	string phone;

public:
	TheaterUnsorted(string Name, string Phone);
	void AddMovie(Movie& Movie);
	string GetMovieForHour(int hour);
	int GetShowTimeForGenre(string Genre);

	int GetPopcornPrice() { return popcorn; }
	int GetCokePrice() { return coke; }
};