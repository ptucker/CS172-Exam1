#pragma once
#include <string>
using namespace std;

class Movie {
private:
	string title;
	string genre;
	int showtime;

public:
	Movie() {
		title = "Ocean's 8";
		genre = "Action";
		showtime = 0;
	}

	Movie(string Title, string Genre, int ShowTime) {
		title = Title;
		genre = Genre;
		if (!(genre == "Action" || genre == "Comedy" || genre == "Horror" || genre == "Documentary"))
			genre = "Comedy";
		showtime = ShowTime;
		if (showtime < 0 || showtime > 23)
			showtime = 0;
	}

	string GetTitle() { return title; }
	string GetGenre() { return genre; }
	int GetShowtime() { return showtime; }
};