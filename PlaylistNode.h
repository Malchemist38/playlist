#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

struct PlaylistNode {
    char uniqueID[50];
    char songName[50];
    char artistName[50];
    int songLength;
    struct PlaylistNode* nextNodePtr;
};

typedef struct PlaylistNode PlaylistNode;

PlaylistNode* AddSong(PlaylistNode* headNode);
PlaylistNode* RemoveSong(PlaylistNode* headNode);
void ChangePositionOfSong(PlaylistNode* headNode);
void OutputSongsByArtist(PlaylistNode* headNode);
void OutputTotalTime(PlaylistNode* headNode);
void OutputFullPlaylist(PlaylistNode* headNode);

void CreatePlaylistNode(PlaylistNode* thisNode, char[], char[], char[], int, PlaylistNode* nextNode);
void InsertPlaylistNodeAfter(PlaylistNode* thisNode, PlaylistNode* newNode);
void SetNextPlaylistNode(PlaylistNode* thisNode, PlaylistNode* newNode);
PlaylistNode* GetNextPlaylistNode(PlaylistNode* thisNode);
void PrintPlaylistNode(PlaylistNode* thisNode);

#endif
