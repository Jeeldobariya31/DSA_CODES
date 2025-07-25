#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100


struct Song {
    char name[MAX_NAME];
    struct Song* prev;
    struct Song* next;
};

struct Song* head = NULL;
struct Song* current = NULL;


struct Song* createSong(char* name) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    if (!newSong) {
        printf("     Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newSong->name, name);
    newSong->prev = newSong->next = NULL;
    return newSong;
}

// Add song to the end of the playlist
void addSong(char* name) {
    struct Song* newSong = createSong(name);
    if (head == NULL) {
        head = current = newSong;
    } else {
        struct Song* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newSong;
        newSong->prev = temp;
    }
    printf(" '%s' added to the playlist.\n", name);
}

// Delete a song by name
void deleteSong(char* name) {
    struct Song* temp = head;
    while (temp != NULL && strcmp(temp->name, name) != 0)
        temp = temp->next;

    if (temp == NULL) {
        printf(" Song not found!\n");
        return;
    }

    if (temp == head) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    } else if (temp->next == NULL) {
        temp->prev->next = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    if (current == temp)
        current = head;

    printf(" '%s' deleted from the playlist.\n", temp->name);
    free(temp);
}

// Display the playlist
void displayPlaylist() {
    struct Song* temp = head;
    if (temp == NULL) {
        printf(" Playlist is empty.\n");
        return;
    }
    printf(" Playlist:\n");
    while (temp != NULL) {
        if (temp == current)
            printf(" -> %s (Now Playing)\n", temp->name);
        else
            printf(" - %s\n", temp->name);
        temp = temp->next;
    }
}

// Play the current song
void playCurrent() {
    if (current != NULL)
        printf("▶ Now playing: %s\n", current->name);
    else
        printf(" No song is selected!\n");
}

// Play next song
void playNext() {
    if (current && current->next) {
        current = current->next;
        playCurrent();
    } else {
        printf("⏭ No next song!\n");
    }
}

// Play previous song
void playPrevious() {
    if (current && current->prev) {
        current = current->prev;
        playCurrent();
    } else {
        printf("⏮ No previous song!\n");
    }
}

// Search for a song
void searchSong(char* name) {
    struct Song* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf(" Found '%s' at position %d\n", name, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf(" Song '%s' not found.\n", name);
}

// Main Menu
int main() {
    int choice;
    char name[MAX_NAME];

    do {
        printf("\n=== Music Player Menu ===\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Display Playlist\n");
        printf("4. Play Current Song\n");
        printf("5. Play Next Song\n");
        printf("6. Play Previous Song\n");
        printf("7. Search Song\n");
        printf("8. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter song name to add: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = '\0';
                addSong(name);
                break;
            case 2:
                printf("Enter song name to delete: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = '\0';
                deleteSong(name);
                break;
            case 3:
                displayPlaylist();
                break;
            case 4:
                playCurrent();
                break;
            case 5:
                playNext();
                break;
            case 6:
                playPrevious();
                break;
            case 7:
                printf("Enter song name to search: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = '\0';
                searchSong(name);
                break;
            case 8:
                printf(" Exiting Music Player. Goodbye!\n");
                break;
            default:
                printf(" Invalid choice! Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
