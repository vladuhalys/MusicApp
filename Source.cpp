#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
struct Track {
    string name;
    string author;
    string duration;
};
const int MAX_TRACKS = 100;
int readTracksFromCSV(const string& filename, Track* tracks) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file.\n";
        return 0;
    }
    int trackCount = 0;
    string line;
    while (std::getline(file, line) && trackCount < MAX_TRACKS) {
        stringstream ss(line);
        string name, author, duration;
        if (getline(ss, name, ',') && getline(ss, author, ',') && getline(ss, duration, ',')) {
            tracks[trackCount] = { name, author, duration };
            trackCount++;
        }
    }
    file.close();
    return trackCount;
}
void displayMenu(const Track* tracks, int numTracks) {
    cout << "Music menu:\n";
    for (int i = 0; i < numTracks; i++) {
        const Track& track = tracks[i];
        cout << "-------------------------\n";
        cout << "Track " << (i + 1) << ":\n";
        cout << "Name: " << track.name << "\n";
        cout << "Author: " << track.author << "\n";
        cout << "Duration: " << track.duration << "\n";
    }
    cout << "-------------------------\n";
    cout << "Select a track by sequence (1-" << numTracks << "): ";
}
int main() {
    Track tracks[MAX_TRACKS];
    int numTracks = readTracksFromCSV("music.csv", tracks);
    if (numTracks == 0) {
        cout << "Failed to read tracks from file.\n";
        return 0;
    }
    displayMenu(tracks, numTracks);
    int choice;
    cin >> choice;
    if (choice >= 1 && choice <= numTracks) {
        const Track& selectedTrack = tracks[choice - 1];
        cout << "\nYou have selected a track:\n";
        cout << "Name: " << selectedTrack.name << "\n";
        cout << "Author: " << selectedTrack.author << "\n";
        cout << "Duration: " << selectedTrack.duration << "\n";
    }
    else {
        cout << "Incorrect track selection.\n";
    }
    return 0;
}