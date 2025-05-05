
#include <iostream>
#include <string>
#include <unordered_map>
#include <ctime>
#include <cstdlib>

using namespace std;

class Room {
public:
    string name;
    string description;
    unordered_map<string, Room*> exits;
    bool hasTreasure = false;
    bool hasTrap = false;

    Room(string name, string desc) {
        this->name = name;
        this->description = desc;
    }

    void Connect(string direction, Room* neighbor) {
        exits[direction] = neighbor;
    }

    Room* GetExit(string direction) {
        if (exits.count(direction)) return exits[direction];
        return nullptr;
    }
};

class Player {
public:
    Room* currentRoom;
    bool alive = true;

    Player(Room* startRoom) {
        currentRoom = startRoom;
    }

    void Move(string direction) {
        Room* nextRoom = currentRoom->GetExit(direction);
        if (nextRoom) {
            currentRoom = nextRoom;
            cout << "\nYou move to " << currentRoom->name << ".\n";
            cout << currentRoom->description << "\n";

            if (currentRoom->hasTrap) {
                cout << "Oh no! You fell into a trap! Game over.\n";
                alive = false;
            } else if (currentRoom->hasTreasure) {
                cout << "Congratulations! You found the treasure!\n";
                alive = false;
            }
        } else {
            cout << "\nYou can't go that way.\n";
        }
    }
};

void BuildMap(Room*& startRoom) {
    Room* foyer = new Room("Foyer", "A dimly lit entrance.");
    Room* hall = new Room("Hall", "A long corridor with echoing footsteps.");
    Room* armory = new Room("Armory", "Old weapons hang on the wall.");
    Room* vault = new Room("Vault", "A thick door leads inside a secure room.");
    Room* trapRoom = new Room("Trap Room", "You have a bad feeling about this...");

    foyer->Connect("north", hall);
    hall->Connect("south", foyer);
    hall->Connect("east", armory);
    hall->Connect("west", trapRoom);
    armory->Connect("west", hall);
    trapRoom->Connect("east", hall);
    armory->Connect("north", vault);
    vault->Connect("south", armory);

    // Randomly assign treasure and trap
    srand(time(0));
    int treasureIndex = rand() % 3;
    int trapIndex = (treasureIndex + 1) % 3;

    Room* potentialRooms[3] = {vault, trapRoom, armory};
    potentialRooms[treasureIndex]->hasTreasure = true;
    potentialRooms[trapIndex]->hasTrap = true;

    startRoom = foyer;
}

int main() {
    cout << "Welcome to M7HW: Dungeon Explorer!\n";
    cout << "Find the treasure and avoid traps. Use commands: north, south, east, west, quit\n\n";

    Room* startRoom;
    BuildMap(startRoom);

    Player player(startRoom);
    cout << "You are in " << player.currentRoom->name << ".\n";
    cout << player.currentRoom->description << "\n";

    string command;
    while (player.alive) {
        cout << "\n> ";
        cin >> command;
        if (command == "quit") {
            cout << "Goodbye!\n";
            break;
        } else {
            player.Move(command);
        }
    }

    cout << "\nThanks for playing M7HW!\n";
    return 0;
}
