#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PlaylistNode.h"

void CreatePlaylistNode(PlaylistNode* thisNode, char uniqueID[], char songName[], char artistName[], int songLength, PlaylistNode* nextNode) {
    strcpy(thisNode->uniqueID, uniqueID);
    strcpy(thisNode->songName, songName);
    strcpy(thisNode->artistName, artistName);
    thisNode->songLength = songLength;
    thisNode->nextNodePtr = nextNode;
}

void InsertPlaylistNodeAfter(PlaylistNode* thisNode, PlaylistNode* newNode) {
    PlaylistNode* temp = thisNode->nextNodePtr;
    thisNode->nextNodePtr = newNode;
    newNode->nextNodePtr = temp;
}

void SetNextPlaylistNode(PlaylistNode* thisNode, PlaylistNode* newNode) {
    thisNode->nextNodePtr = newNode;
}

PlaylistNode* GetNextPlaylistNode(PlaylistNode* thisNode) {
    return thisNode->nextNodePtr;
}

void PrintPlaylistNode(PlaylistNode* thisNode) {
    printf("Unique ID: %s\n", thisNode->uniqueID);
    printf("Song Name: %s\n", thisNode->songName);
    printf("Artist Name: %s\n", thisNode->artistName);
    printf("Song Length (in seconds): %d\n", thisNode->songLength);
}

void OutputFullPlaylist(PlaylistNode* headNode) {
    if (headNode == NULL) {
        printf("Playlist is empty\n");
        return;
    }

    int position = 1;
    PlaylistNode* current = headNode;
    while (current != NULL) {
        printf("%d.\n", position);
        PrintPlaylistNode(current);
        printf("\n");
        current = GetNextPlaylistNode(current);
        position++;
    }
}

PlaylistNode* AddSong(PlaylistNode* headNode) {
    PlaylistNode* newNode = (PlaylistNode*)malloc(sizeof(PlaylistNode));

    char uniqueID[50];
    char songName[50];
    char artistName[50];
    int songLength;

    printf("ADD SONG\n");
    printf("Enter song's unique ID: ");
    scanf("%s", uniqueID);
    printf("Enter song's name: ");
    scanf("%s", songName);
    printf("Enter artist's name: ");
    scanf("%s", artistName);
    printf("Enter song's length (in seconds): ");
    scanf("%d", &songLength);

    CreatePlaylistNode(newNode, uniqueID, songName, artistName, songLength, NULL);

    // Add the new node to the end of the list
    if (headNode == NULL) {
        headNode = newNode;
    } else {
        PlaylistNode* current = headNode;
        while (GetNextPlaylistNode(current) != NULL) {
            current = GetNextPlaylistNode(current);
        }
        SetNextPlaylistNode(current, newNode);
    }

    return headNode;
}

PlaylistNode* RemoveSong(PlaylistNode* headNode) {
    if (headNode == NULL) {
        printf("Playlist is empty\n");
        return headNode;
    }

    char uniqueID[50];
    printf("REMOVE SONG\n");
    printf("Enter song's unique ID: ");
    scanf("%s", uniqueID);

    PlaylistNode* current = headNode;
    PlaylistNode* previous = NULL;

    // Search for the node to be removed
    while (current != NULL && strcmp(current->uniqueID, uniqueID) != 0) {
        previous = current;
        current = GetNextPlaylistNode(current);
    }

    // If the node is found, remove it
    if (current != NULL) {
        if (previous != NULL) {
            SetNextPlaylistNode(previous, GetNextPlaylistNode(current));
        } else {
            // If the node to be removed is the head
            headNode = GetNextPlaylistNode(current);
        }
        free(current);
        printf("\"%s\" removed.\n", current->songName);
    } else {
        printf("Song with ID \"%s\" not found.\n", uniqueID);
    }

    return headNode;
}

void ChangePositionOfSong(PlaylistNode* headNode) {
    if (headNode == NULL) {
        printf("Playlist is empty\n");
        return;
    }

    int currentPosition, newPosition;
    printf("CHANGE POSITION OF SONG\n");
    printf("Enter song's current position: ");
    scanf("%d", &currentPosition);
    printf("Enter new position for song: ");
    scanf("%d", &newPosition);

    if (currentPosition < 1) {
        currentPosition = 1;
    }

    int position = 1;
    PlaylistNode* current = headNode;
    PlaylistNode* previous = NULL;

    // Traverse the list to find the current position
    while (position < currentPosition && current != NULL) {
        previous = current;
        current = GetNextPlaylistNode(current);
        position++;
    }

    if (current == NULL) {
        printf("Invalid current position.\n");
        return;
    }

    // Remove the node from the current position
    if (previous != NULL) {
        SetNextPlaylistNode(previous, GetNextPlaylistNode(current));
    } else {
        // If removing the head, update headNode
        headNode = GetNextPlaylistNode(current);
    }

    // Move the node to the new position
    position = 1;
    current = headNode;
    previous = NULL;

    while (position < newPosition && current != NULL) {
        previous = current;
        current = GetNextPlaylistNode(current);
        position++;
    }

    // Insert the node at the new position
    if (previous != NULL) {
        InsertPlaylistNodeAfter(previous, current);
        InsertPlaylistNodeAfter(previous, current);
    } else {
        // If inserting at the head, update headNode
        InsertPlaylistNodeAfter(current, headNode);
        headNode = current;
    }

    printf("\"%s\" moved to position %d\n", current->songName, newPosition);
}

void OutputSongsByArtist(PlaylistNode* headNode) {
    char artistName[50];
    printf("OUTPUT SONGS BY SPECIFIC ARTIST\n");
    printf("Enter artist's name: ");
    scanf("%s", artistName);

    PlaylistNode* current = headNode;
    int position = 1;

    while (current != NULL) {
        if (strcmp(current->artistName, artistName) == 0) {
            printf("%d.\n", position);
            PrintPlaylistNode(current);
            printf("\n");
        }

        current = GetNextPlaylistNode(current);
        position++;
    }
}

void OutputTotalTime(PlaylistNode* headNode) {
    int totalTime = 0;
    PlaylistNode* current = headNode;

    while (current != NULL) {
        totalTime += current->songLength;
        current = GetNextPlaylistNode(current);
    }

    printf("OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\n");
    printf("Total time: %d seconds\n", totalTime);
}
