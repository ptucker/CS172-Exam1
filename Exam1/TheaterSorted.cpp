#include "TheaterSorted.h"

TheaterSorted::TheaterSorted(string Name, string Phone) {
	name = Name;
	phone = Phone;
}

void TheaterSorted::AddMovie(Movie& Movie) {
	//Make sure there's room for this new movie
	if (count < size) {
		int insert = count;
		//We'll keep the movies in order based on their showtime. So find where it should go.
		while (insert > 0 && movies[insert - 1].GetShowtime() > Movie.GetShowtime()) {
			movies[insert] = movies[insert - 1]; //Slide the movie out one 
			insert--;
		}
		movies[insert] = Movie;

		count++;
	}
}

string TheaterSorted::GetMovieForHour(int hour) {
	string ret = "";
	if (hour < 0 || hour > 23)
		return ret;

	for (int i = 0; i < count; i++) {
		if (movies[i].GetShowtime() > hour) {
			ret = movies[i].GetTitle();
			break;
		}
	}
	
	return ret;
}

int TheaterSorted::GetShowTimeForGenre(string Genre) {
	int s = -1;
	for (int i = 0; i < count; i++) {
		if (movies[i].GetGenre() == Genre) {
			s = movies[i].GetShowtime();
			break;
		}
	}

	return s;
}
