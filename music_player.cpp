#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Song {
private:
    string title, artist;
    float duration;

public:
    Song(string t="", string a="", float d=0.0) {
        title = t;
        artist = a;
        duration = d;
    }

    void display() {
        cout << "Title: " << title 
             << " | Artist: " << artist 
             << " | Duration: " << duration << " mins\n";
    }

    string getTitle() { return title; }
};

class MusicPlayer {
private:
    vector<Song> playlist;

public:
    void addSong() {
        string t, a;
        float d;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "\n🎵 Enter Song Title: ";
        getline(cin, t);
        cout << "🎤 Enter Artist Name: ";
        getline(cin, a);
        cout << "⏱ Enter Duration (mins): ";
        cin >> d;

        playlist.push_back(Song(t, a, d));
        cout << "\n✔ Song Added Successfully!\n";
    }

    void showPlaylist() {
        if(playlist.empty()) {
            cout << "\n📁 Playlist is empty!\n";
            return;
        }
        cout << "\n-------- YOUR PLAYLIST --------\n";
        for(int i = 0; i < playlist.size(); i++) {
            cout << i+1 << ". ";
            playlist[i].display();
        }
    }

    void removeSong() {
        if(playlist.empty()) {
            cout << "\n❗ Playlist is empty!\n";
            return;
        }
        showPlaylist();
        int choice;
        cout << "\nEnter Song Number to Remove: ";
        cin >> choice;

        if(choice < 1 || choice > playlist.size()) {
            cout << "❌ Invalid Choice!\n";
            return;
        }

        playlist.erase(playlist.begin() + (choice - 1));
        cout << "🗑 Song Removed Successfully!\n";
    }

    void searchSong() {
        if(playlist.empty()) {
            cout << "\n❗ Playlist is empty!\n";
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string key;
        cout << "\n🔍 Enter Song Title to Search: ";
        getline(cin, key);

        for(auto &s : playlist) {
            if(s.getTitle() == key) {
                cout << "\n🎶 Song Found!\n";
                s.display();
                return;
            }
        }
        cout << "❌ Song Not Found!\n";
    }

    void playSong() {
        if(playlist.empty()) {
            cout << "\nNo Songs to Play!\n";
            return;
        }
        showPlaylist();
        int n;
        cout << "\n▶ Enter Song Number to Play: ";
        cin >> n;

        if(n < 1 || n > playlist.size()) {
            cout << "❌ Invalid Song Number!\n";
            return;
        }

        cout << "\n🔊 Now Playing: ";
        playlist[n-1].display();
    }
};

int main() {
    MusicPlayer mp;
    int choice;

    while(true) {
        cout << "\n========= MUSIC PLAYER =========";
        cout << "\n1. Add Song";
        cout << "\n2. Show Playlist";
        cout << "\n3. Remove Song";
        cout << "\n4. Search Song";
        cout << "\n5. Play Song";
        cout << "\n6. Exit";
        cout << "\n--------------------------------";
        cout << "\nEnter Choice: ";

        cin >> choice;

        switch(choice) {
            case 1: mp.addSong(); break;
            case 2: mp.showPlaylist(); break;
            case 3: mp.removeSong(); break;
            case 4: mp.searchSong(); break;
            case 5: mp.playSong(); break;
            case 6: 
                cout << "\n🎧 Exiting Music Player... Goodbye!\n";
                return 0;

            default:
                cout << "❌ Invalid Choice! Try Again.\n";
        }
    }
}

