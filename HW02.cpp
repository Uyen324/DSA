#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
struct song_node {
    string song_name;
    song_node* next;
    song_node* prev;
    song_node(string name) {
        song_name = name;
        next = NULL;
        prev = NULL;
    }
};

struct music_player {
    song_node* head;
    song_node* tail;
    song_node* current;
    unordered_map<string, song_node*> song_map;
};

void create_player(music_player& player) {
    player.head = NULL;
    player.tail = NULL;
    player.current = NULL;
}

void add_song(music_player& player, const string& song_name) {
    if (player.song_map.find(song_name) != player.song_map.end()) {
        return; 
    }
    song_node* new_node = new song_node(song_name);
    player.song_map[song_name] = new_node;

    if (!player.head) {
        player.head = player.tail = player.current = new_node;
    } else {
        player.tail->next = new_node;
        new_node->prev = player.tail;
        player.tail = new_node;
    }
}

void play_next(music_player& player) {
    if (!player.current) return;
    player.current = player.current->next ? player.current->next : player.head;
}

void play_previous(music_player& player) {
    if (!player.current) return;
    player.current = player.current->prev ? player.current->prev : player.tail;
}

void remove_song(music_player& player, const string& song_name) {
    if (player.song_map.find(song_name) == player.song_map.end()) {
        return;
    }

    song_node* node_to_delete = player.song_map[song_name];

    if (node_to_delete == player.head && node_to_delete == player.tail) {
        player.head = player.tail = player.current = NULL;
    } else if (node_to_delete == player.head) {
        player.head = player.head->next;
        player.head->prev = NULL;
        if (player.current == node_to_delete) player.current = player.head;
    } else if (node_to_delete == player.tail) {
        player.tail = player.tail->prev;
        player.tail->next = NULL;
        if (player.current == node_to_delete) player.current = player.tail;
    } else {
        node_to_delete->prev->next = node_to_delete->next;
        node_to_delete->next->prev = node_to_delete->prev;
        if (player.current == node_to_delete) player.current = node_to_delete->next;
    }

    player.song_map.erase(song_name);
    delete node_to_delete;
}

void display_playlist(music_player& player) {
    song_node* temp = player.head;
    while (temp) {
        cout << temp->song_name << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    music_player player;
    create_player(player);

    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;
        if (operation == "ADD") {
            string song_name;
            cin >> song_name;
            add_song(player, song_name);
        } else if (operation == "NEXT") {
            play_next(player);
        } else if (operation == "PREV") {
            play_previous(player);
        } else if (operation == "REMOVE") {
            string song_name;
            cin >> song_name;
            remove_song(player, song_name);
        } else if (operation == "DISPLAY") {
            display_playlist(player);
        }
    }
    return 0;
}

