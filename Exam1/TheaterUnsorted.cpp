#include "TheaterUnsorted.h"

TheaterUnsorted::TheaterUnsorted(string Name, string Phone) {
	name = Name;
	phone = Phone;
}

void TheaterUnsorted::AddMovie(Movie& Movie) {
	//Make sure there's room for this new movie
	if (count < size) {
		//Since we're not sorting the movies, just add it to the end
		movies[count] = Movie;
		count++;
	}
}

string TheaterUnsorted::GetMovieForHour(int hour) {
	string ret = "";
	if (hour < 0 || hour > 23)
		return ret;

	int closest = 1000;
	for (int i = 0; i < count; i++) {
		//Since these aren't sorted, we need to find the movie closest to the given hour
		int diff = movies[i].GetShowtime() - hour;
		if (diff > 0 && diff < closest) {
			ret = movies[i].GetTitle();
			closest = diff;
		}
	}

	return ret;
}

int TheaterUnsorted::GetShowTimeForGenre(string Genre) {
	int s = -1;
	for (int i = 0; i < count; i++) {
		if (movies[i].GetGenre() == Genre) {
			s = movies[i].GetShowtime();
			break;
		}
	}

	return s;
}
