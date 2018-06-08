#include <iostream>
#include "Movie.h"
//#include "TheaterSorted.h"
#include "TheaterUnsorted.h"
using namespace std;

int main()
{
	//Note: you should not need to alter this code at all for your tests to pass.
	const int MOVIECOUNT = 11;
	Movie movieListing[] = {
		Movie("Bull Durham", "Comedy", 0), Movie("Ocean's Eleven", "Action", 2),
		Movie("Solo: A Star Wars Story", "Sci-Fi", 5), Movie("Jaws", "Horror", 7),
		Movie("Fletch", "Comedy", 10), Movie("Usual Suspects", "Action", 12),
		Movie("Bull Durham", "Comedy", 14), Movie("Ocean's Eleven", "Action", 16),
		Movie("Monte Python's Meaning of Life", "Comedy", 19), Movie("Jaws", "Horror", 21),
		Movie("Usual Suspects", "Action", 23),
	};

	//TheaterSorted garland("The Garland", "509-327-2509");
	TheaterUnsorted garland("The Garland", "509-327-2509");

	for (int m = 0; m < MOVIECOUNT; m++) {
		garland.AddMovie(movieListing[m]);
	}

	int errors = 0;
	if (garland.GetMovieForHour(-1) != "") {
		errors++;
		cout << "error: not handling -1 correctly\n";
	}
	if (garland.GetMovieForHour(25) != "") {
		errors++;
		cout << "error: not handling 25 correctly\n";
	}
	//Find the movie starting on or after the hour 18
	if (garland.GetMovieForHour(18) != "Monte Python's Meaning of Life") {
		errors++;
		cout << "error: incorrect movie for 18th hour\n";
	}
	if (garland.GetShowTimeForGenre("Comedy") != 0) {
		errors++;
		cout << "error: incorrect Comedy\n";
	}

	if (errors == 0) cout << "Passed\n";
	else cout << "Errors: " << errors << endl;
}
