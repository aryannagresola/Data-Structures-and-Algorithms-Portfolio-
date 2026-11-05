#ifndef CIRCULAR_LL_H
#define CIRCULAR_LL_H

#include <iostream>
#include <string> 

// playlist node

template <typename T>
class Playlist{
public:
    T songTitle;
    T artist;
    Playlist<T>* next = nullptr;
    
};

// creating a new song

template <typename T>
Playlist<T>* createSong(T songTitle, T artist){
    Playlist<T>* newSong = new Playlist<T>;
    newSong->songTitle = songTitle;
    newSong->artist = artist;
    newSong->next = newSong; 

    return newSong;
}

// playing all song (traversal)

template <typename T>
void playAllSongs(Playlist<T>* playlistHead){
    if(playlistHead == nullptr){
        std::cout << "The playlist is empty." << std::endl;
        return;
    }
    Playlist<T>* currentSong = playlistHead;
    int songNumber = 1;
    std::cout << "CURRENT PLAYLIST" << std::endl;
    std::cout << "------------------------" << std::endl;

    do{
        std::cout << songNumber << ". "
                  << currentSong->songTitle << " - " << currentSong->artist << std::endl;

        currentSong = currentSong->next;
        songNumber++;

    }while(currentSong != playlistHead);
    std::cout << "------------------------" << std::endl;
}

// inserting song (head)

template <typename T> 
void addSongToBeginning(T songTitle, T artist, Playlist<T>** playlistHead){
    Playlist<T>* newSong = createSong(songTitle, artist);

    if(*playlistHead == nullptr){
        *playlistHead = newSong;
        return;
    }

    Playlist<T>* lastSong = *playlistHead;
    while(lastSong->next != *playlistHead){
        lastSong = lastSong->next;

    }

    newSong->next = *playlistHead;
    lastSong->next = newSong;

    *playlistHead = newSong;
}

// inserting song (end)

template <typename T> 
void addSongToEnd(T songTitle, T artist, Playlist<T>* playlistHead){
    if(playlistHead == nullptr)
    return;

    Playlist<T>* newSong = createSong(songTitle, artist);
    Playlist<T>* lastSong = playlistHead;

    while(lastSong->next != playlistHead){
        lastSong = lastSong->next;
    }

    lastSong->next = newSong;
    newSong->next = playlistHead;
}

// inserting song (anywhere)

template <typename T>
void addSongAny(T songTitle, T artist, Playlist<T>* currentSong){
    if(currentSong == nullptr)
    return;

    Playlist<T>* newSong = createSong(songTitle, artist);

    newSong->next = currentSong->next;
    currentSong->next = newSong;
}

// deleting song

template <typename T>
void deleteSong(Playlist<T>** playlistHead, Playlist<T>* songToDelete){
    if(*playlistHead == nullptr || songToDelete == nullptr)
        return;

    // only one song
    if((*playlistHead)->next == *playlistHead){
        delete *playlistHead;
        *playlistHead = nullptr;
        return;
    }

    Playlist<T>* previousSong = nullptr;
    Playlist<T>* currentSong = *playlistHead;

    do{
        if(currentSong == songToDelete){
            if(previousSong == nullptr){
                Playlist<T>* lastSong = *playlistHead;

                while(lastSong->next != *playlistHead){
                    lastSong = lastSong->next;
                }
                *playlistHead = currentSong->next;
                lastSong->next = *playlistHead;
            }
            else{
                previousSong->next = currentSong->next;
            }
            delete currentSong;
            return;
        }
        previousSong = currentSong;
        currentSong = currentSong->next;
    }while(currentSong != *playlistHead);
 
    std::cout << "Song not found." << std::endl;
}

// play next song

template <typename T>
void nextSong(Playlist<T>* playlistHead, T currentTitle){
    if(playlistHead == nullptr)
        return;
    Playlist<T>* currentSong = playlistHead;

    do{
        if(currentSong->songTitle == currentTitle){
            std::cout << "Current Song : " << currentSong->songTitle << std::endl;
            std::cout << "Next Song    : " << currentSong->next->songTitle << std::endl;
            return;
        }
        currentSong = currentSong->next;
    }while(currentSong != playlistHead);
    std::cout << "Song not found." << std::endl;
}

// play previous song
template <typename T>
void previousSong(Playlist<T>* playlistHead, T currentTitle){
    if(playlistHead == nullptr)
        return;

    Playlist<T>* previousSongNode = nullptr;
    Playlist<T>* currentSong = playlistHead;

    do{

        if(currentSong->songTitle == currentTitle){
            if(previousSongNode == nullptr){
                Playlist<T>* lastSong = playlistHead;

                while(lastSong->next != playlistHead){
                    lastSong = lastSong->next;
                }

                std::cout << "Current Song  : " << currentSong->songTitle << std::endl;

                std::cout << "Previous Song : " << lastSong->songTitle << std::endl;
            }else{
                std::cout << "Current Song  : " << currentSong->songTitle << std::endl;
                std::cout << "Previous Song : " << previousSongNode->songTitle << std::endl;
            }
            return;
        }

        previousSongNode = currentSong;
        currentSong = currentSong->next;

    }while(currentSong != playlistHead);
    std::cout << "Song not found." << std::endl;
}

// clear playlist
template <typename T>
void clearPlaylist(Playlist<T>** playlistHead){
    if(*playlistHead == nullptr)
        return;

    Playlist<T>* currentSong = (*playlistHead)->next;

    while(currentSong != *playlistHead){

        Playlist<T>* temp = currentSong;
        currentSong = currentSong->next;
        delete temp;
    }

    delete *playlistHead;
    *playlistHead = nullptr;

    std::cout << "Playlist cleared." << std::endl;
}

#endif