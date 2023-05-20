#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void displayMenu(const string& title, const string& artist, const string& duration) {
    cout << "Music Menu" << endl;
    cout << "Title: " << title << endl;
    cout << "Artist: " << artist << endl;
    cout << "Duration: " << duration << endl;
    cout << endl;
}
void readMusicTracksFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        string title, artist, duration;
        size_t comma1 = line.find(',');
        size_t comma2 = line.find(',', comma1 + 1);
        if (comma1 != string::npos && comma2 != string::npos) {
            title = line.substr(0, comma1);
            artist = line.substr(comma1 + 1, comma2 - comma1 - 1);
            duration = line.substr(comma2 + 1);
            displayMenu(title, artist, duration);
        }
    }
    file.close();
}
int main() {
    string filename = "music_tracks.csv";
    readMusicTracksFromCSV(filename);
    return 0;
}