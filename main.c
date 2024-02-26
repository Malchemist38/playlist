#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PlaylistNode.h"

void PrintMenu(char playlistTitle[]) {
    printf("%s PLAYLIST MENU\n", playlistTitle);
    printf("a - Add song\n");
    printf("r - Remove song\n");
    printf("c - Change position of song\n");
    printf("s - Output songs by specific artist\n");
    printf("t - Output total time of playlist (in seconds)\n");
    printf("o - Output full playlist\n");
    printf("q - Quit\n");
}

PlaylistNode* ExecuteMenu(char option, char playlistTitle[], PlaylistNode* headNode) {
    switch (option) {
        case 'a':
            // Add song
            headNode = AddSong(headNode);
            break;
        case 'r':
            // Remove song
            headNode = RemoveSong(headNode);
            break;
        case 'c':
            // Change position of song
            ChangePositionOfSong(headNode);
            break;
        case 's':
            // Output songs by specific artist
            OutputSongsByArtist(headNode);
            break;
        case 't':
            // Output total time of playlist
            OutputTotalTime(headNode);
            break;
        case 'o':
            // Output full playlist
            OutputFullPlaylist(headNode);
            break;
        case 'q':
            // Quit
            printf("Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid option. Please try again.\n");
    }

    return headNode;
}

int main(void) {
    char playlistTitle[50];
    printf("Enter playlist's title: ");
    scanf("%s", playlistTitle);

    PlaylistNode* headNode = NULL;

    char option;
    do {
        PrintMenu(playlistTitle);
        printf("Choose an option: ");
        scanf(" %c", &option);
        headNode = ExecuteMenu(option, playlistTitle, headNode);
    } while (option != 'q');

    return 0;
}
