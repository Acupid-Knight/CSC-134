#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// ===== Item Class =====
// Represents an item in the game (can be picked up and used)
class Item {
public:
    string name;
    string description;
    bool usable;

    Item(string n, string d, bool u = false)
        : name(n), description(d), usable(u) {}
};

// ===== Room Class =====
// Represents a room in the dungeon with options to travel to other rooms
class Room {
public:
    string name;
    string description;
    vector<Room*> options;
    bool hasTreasure = false;
    bool hasTrap = false;
    Item* item = nullptr;

    Room(string name, string desc) : name(name), description(desc) {}

    void AddOption(Room* option) {
        options.push_back(option);
    }
};

// ===== Player Class =====
// Manages player's state, current room, and inventory
class Player {
public:
    Room* currentRoom;
    bool alive = true;
    vector<Item> inventory;

    Player(Room* startRoom) {
        currentRoom = startRoom;
    }

    // Handles movement logic and room interaction (trap, treasure, or item)
    void Move(int choice) {
        if (choice >= 1 && choice <= currentRoom->options.size()) {
            currentRoom = currentRoom->options[choice - 1];
            cout << "\nYou enter: " << currentRoom->name << "\n";
            cout << currentRoom->description << "\n";

            // Check for traps
            if (currentRoom->hasTrap) {
                cout << "A deadly trap triggers! Blood splatters the walls...\n";
                alive = false;
            }
            // Check for treasure (triggers an ending)
            else if (currentRoom->hasTreasure) {
                cout << "You discover a sacred relic glowing with power!\n";
                alive = false;
            }
            // Check for item in the room
            else if (currentRoom->item) {
                cout << "You found an item: " << currentRoom->item->name << "\n";
                cout << currentRoom->item->description << "\n";
                cout << "Take it? (1. Yes / 2. No): ";
                int choice;
                cin >> choice;
                if (choice == 1) {
                    inventory.push_back(*currentRoom->item);
                    currentRoom->item = nullptr;
                    cout << "Item added to your inventory.\n";
                }
            }
        } else {
            cout << "You hesitate... but the house urges you forward. Try again.\n";
        }
    }

    // Checks if the player has a specific item
    bool hasItem(const string& itemName) {
        for (auto& item : inventory) {
            if (item.name == itemName) return true;
        }
        return false;
    }
};

// ===== Utility Function =====
// Prompts and validates player input from a list of numbered options
int get_choice(int size) {
    int choice = 0;
    while (choice < 1 || choice > size) {
        cout << "Choose (1-" << size << "): ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Invalid input. Try again.\n";
        }
    }
    return choice;
}

int main() {
    cout << "Welcome to 'Thief: A Haunted Mystery'\n";

    // === ACT I: The Dare ===
    // Sets up the initial choice at the front of the haunted house
    cout << "\n=== ACT I: The Dare ===\n";
    cout << "You're in front of a spooky old house...\n";
    cout << "1. Try the front door\n2. Sneak around back\n3. Forget it, and go home\n4. Circle the property cautiously\n";
    int choice = get_choice(4);

    if (choice == 3) {
        cout << "\n=== ACT I, Scene 2: Coward's Retreat ===\n";
        cout << "As you turn away, a cold wind brushes your neck...\n";
        cout << "The trees rustle and you hear the word... 'coward...'\n";
        return 0; // Ends game early
    } else if (choice == 4) {
        cout << "\n=== ACT I, Scene 3: Surveyor's Path ===\n";
        cout << "The windows flicker, and a figure watches from inside...\n";
    } else {
        cout << "\nYou press onward...\n";
    }

    // Final part of ACT I
    cout << "\n=== ACT I, Scene 4: Omen ===\n";
    cout << "You find strange runes scratched into the doorframe... someone tried to keep something in.\n";

    // === ACT II: Entry ===
    // Player enters the house and chooses where to go next
    cout << "\n=== ACT II: Entry ===\n";
    cout << "The back door is slightly ajar... creaking. You step in.\n";
    cout << "Suddenly, the door slams shut. A chill grips your spine.\n";
    cout << "Do you:\n1. Hide under the stairwell\n2. Investigate the sound upstairs\n3. Leave while you can\n4. Enter the hallway to your right\n";
    choice = get_choice(4);

    if (choice == 1) {
        cout << "\n=== ACT II, Scene 1: Under the Stairs ===\n";
        cout << "You crouch beneath the old stairwell, heart pounding...\n";
    } else if (choice == 2) {
        cout << "\n=== ACT II, Scene 2: Footsteps Above ===\n";
        cout << "You ascend slowly, each creak louder than the last.\n";
    } else if (choice == 4) {
        cout << "\n=== ACT II, Scene 4: Narrow Hall ===\n";
        cout << "The hallway is tight and twisting. Portraits watch with hollow eyes.\n";
    } else {
        cout << "\nYou reach for the handle... it's locked. You're trapped.\n";
    }

    // All paths lead to this shared atmospheric scene
    cout << "\n=== ACT II, Scene 3: A Portrait Cries ===\n";
    cout << "One painting seems to weep... blood drips from its frame.\n";

    // === ACT III: The Dungeon Descent ===
    // Build dungeon rooms and connections between them
    Room* foyer = new Room("Foyer", "The dusty entry glows with an eerie blue light.");
    Room* cell = new Room("Old Cell", "Chains clatter though no one's there.");
    Room* pit = new Room("Bottomless Pit", "You hear something breathing beneath the void.");
    Room* shrine = new Room("Desecrated Shrine", "The idols are broken, but you feel watched.");
    Room* relic = new Room("Chamber of Relics", "A relic floats midair, humming softly.");
    Room* mirror = new Room("Hall of Mirrors", "Reflections move without you.");
    Room* study = new Room("Dusty Study", "Books whisper forgotten spells.");
    Room* altar = new Room("Cursed Altar", "The air shimmers with old power.");

    // Establish pathways between rooms
    foyer->AddOption(cell);
    foyer->AddOption(pit);
    foyer->AddOption(mirror);
    foyer->AddOption(study);
    cell->AddOption(shrine);
    pit->AddOption(shrine);
    shrine->AddOption(relic);
    study->AddOption(altar);
    altar->AddOption(relic);

    // Set traps, treasures, and items in rooms
    relic->hasTreasure = true;
    pit->hasTrap = true;
    mirror->hasTrap = true;
    cell->item = new Item("Silver Fang", "A fang wrapped in ritual cloth.", true);
    altar->item = new Item("Black Candle", "Drips shadows instead of wax.", true);

    // Create the player and start room exploration loop
    Player player(foyer);
    cout << "\nYou are in: " << player.currentRoom->name << "\n";
    cout << player.currentRoom->description << "\n";

    while (player.alive) {
        cout << "\nWhere will you go next?\n";
        for (int i = 0; i < player.currentRoom->options.size(); ++i) {
            cout << i + 1 << ". " << player.currentRoom->options[i]->name << "\n";
        }
        int move = get_choice(player.currentRoom->options.size());
        player.Move(move);
        if (!player.alive) break;
    }

    // === ACT IV: Lore Revealed ===
    // Player uncovers hidden story background
    cout << "\n=== ACT IV: Lore Revealed ===\n";
    cout << "Your vision spins. Memories not your own flood in.\n";
    cout << "1. Read the journal on the altar\n2. Whisper the name Selene\n3. Touch the wall glyphs\n4. Sit silently\n";
    choice = get_choice(4);

    if (choice == 1) {
        cout << "You read the tragic tale of Selene, betrayed and bound by relic magic...\n";
    } else if (choice == 2) {
        cout << "The name echoes. Selene's sorrow becomes your burden.\n";
    } else if (choice == 3) {
        cout << "The glyphs light up... revealing a hidden chamber below.\n";
    } else {
        cout << "Silence speaks. A tear falls from the air.\n";
    }

    // === ACT V: Echoes and Revelation ===
    cout << "\n=== ACT V: Echoes and Revelation ===\n";
    cout << "You see fragments of a girl... Selene. She trusted someone...\n";
    cout << "Do you: \n1. Follow the voice deeper\n2. Retreat to safety\n3. Call Selene's name\n4. Smash the relic\n";
    choice = get_choice(4);

    if (choice == 1) {
        cout << "You press forward through darkness, trusting the voice...\n";
    } else if (choice == 2) {
        cout << "You try to run, but the shadows grab you. Coward.\n";
        return 0;
    } else if (choice == 3) {
        cout << "A light flickers—Selene appears. She smiles faintly.\n";
    } else {
        cout << "The relic cracks... the house screams. Reality warps.\n";
    }

    // === ACT VI: Final Trial ===
    cout << "\n=== ACT VI: Final Trial ===\n";
    cout << "The true heart of the house awaits.\n";
    cout << "Selene watches, her eyes unreadable.\n";
    cout << "Choose your fate:\n1. Trust Selene\n2. Sacrifice an item\n3. Escape alone\n4. Offer yourself\n";
    choice = get_choice(4);

    if (choice == 1) {
        if (player.hasItem("Silver Fang")) {
            cout << "Selene accepts your gift and leads you out safely.\n";
        } else {
            cout << "Selene vanishes. You’re lost forever in the dark.\n";
        }
    } else if (choice == 2) {
        if (!player.inventory.empty()) {
            cout << "You offer your most valuable item. The house relents.\n";
        } else {
            cout << "You have nothing. The house consumes you.\n";
        }
    } else if (choice == 3) {
        cout << "You dash for the exit, alone. The whispers scream 'coward!'\n";
    } else {
        cout << "You kneel and surrender. The house accepts your soul.\n";
    }

    // === Game End ===
    cout << "\n=== END ===\n";
    cout << "Thank you for playing. Every choice you made shaped this ending.\n";
    return 0;
}
