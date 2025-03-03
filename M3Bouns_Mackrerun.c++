//CSC 134
//M3Bouns_Mack - 
//Antonio Mack Jr
// Start with dice rolls
//3/2/25

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>  // For file operations

using namespace std;

// Global variables for character stats
int strength, dexterity, constitution, intelligence, wisdom, charisma;
string name, char_class, race, background;
int level = 1, xp = 0, hp = 0, max_hp = 10;
int constitution_modifier = 0;

// Function prototypes
void inputStats();
void displayCharacter();
void saveCharacter();
int rollDice();
int rollStat();
void calculateHP();
void levelUp();
void chooseRace();
void chooseClass();
void printClassDetails();
void printBackgroundInfo();
void premadeCharacter();
void customCharacter();
void showMainMenu();

// Main function
int main() {
    srand(time(0)); // Seed random number generator

    showMainMenu();  // Show the menu for choosing character type

    return 0;
}

// Function to show the main menu for selecting character type
void showMainMenu() {
    int choice;

    cout << "Welcome to the D&D Character Generator!" << endl;
    cout << "Please choose an option:" << endl;
    cout << "1. Create a Custom Character" << endl;
    cout << "2. Choose a Premade Character" << endl;
    cout << "3. Exit" << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            customCharacter();  // Create a custom character
            break;
        case 2:
            premadeCharacter(); // Choose a premade character
            break;
        case 3:
            cout << "Thank you for using the D&D Character Generator!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            showMainMenu();  // Re-display the menu if input is invalid
            break;
    }
}

// Function for creating a premade character
void premadeCharacter() {
    int choice;
    cout << "\nChoose a premade character:\n";
    cout << "1. Rurik Ironfist, Dwarf Warrior\n";
    cout << "2. Arannis Starfire, Elf Mage\n";
    cout << "3. Kael Shadowblade, Human Rogue\n";
    cout << "4. Valeria Dawnlight, Elf Cleric\n";
    cout << "5. Ragnar Bloodaxe, Orc Barbarian\n";
    cout << "6. Sylas Shadowflame, Tiefling Warlock\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            // Premade Dwarf Warrior
            name = "Rurik Ironfist";
            race = "Dwarf";
            char_class = "Warrior";
            strength = 16; dexterity = 12; constitution = 15; intelligence = 10; wisdom = 10; charisma = 8;
            calculateHP();
            background = "Rurik Ironfist hails from the mountain halls of his ancestors, a warrior of great strength and endurance.";
            break;
        case 2:
            // Premade Elf Mage
            name = "Arannis Starfire";
            race = "Elf";
            char_class = "Mage";
            strength = 8; dexterity = 14; constitution = 10; intelligence = 18; wisdom = 16; charisma = 12;
            calculateHP();
            background = "Arannis Starfire was born with the gift of magic, studying ancient tomes to unlock the mysteries of the arcane.";
            break;
        case 3:
            // Premade Human Rogue
            name = "Kael Shadowblade";
            race = "Human";
            char_class = "Rogue";
            strength = 10; dexterity = 18; constitution = 12; intelligence = 14; wisdom = 10; charisma = 14;
            calculateHP();
            background = "Kael Shadowblade is a master of stealth and deception, growing up on the streets and surviving by wit and guile.";
            break;
        case 4:
            // Premade Elf Cleric
            name = "Valeria Dawnlight";
            race = "Elf";
            char_class = "Cleric";
            strength = 12; dexterity = 14; constitution = 10; intelligence = 16; wisdom = 18; charisma = 14;
            calculateHP();
            background = "Valeria Dawnlight has devoted her life to healing the wounded and spreading light across the land, chosen by the gods.";
            break;
        case 5:
            // Premade Orc Barbarian
            name = "Ragnar Bloodaxe";
            race = "Orc";
            char_class = "Barbarian";
            strength = 18; dexterity = 14; constitution = 16; intelligence = 8; wisdom = 10; charisma = 6;
            calculateHP();
            background = "Ragnar Bloodaxe, born from the blood of his ancestors, lives for the thrill of battle and the roar of the crowd.";
            break;
        case 6:
            // Premade Tiefling Warlock
            name = "Sylas Shadowflame";
            race = "Tiefling";
            char_class = "Warlock";
            strength = 8; dexterity = 14; constitution = 12; intelligence = 16; wisdom = 10; charisma = 18;
            calculateHP();
            background = "Sylas Shadowflame made a pact with an otherworldly patron, gaining dark powers in exchange for his soul.";
            break;
        default:
            cout << "Invalid choice. Returning to menu." << endl;
            showMainMenu();
            return;
    }

    // Show the chosen premade character's stats and background
    displayCharacter();
    saveCharacter();
}

// Function for creating a custom character
void customCharacter() {
    cout << "Enter your character's name: ";
    cin >> name;

    cout << "Enter your character's race (e.g., Human, Elf, Dwarf, Orc, Tiefling): ";
    cin >> race;
    chooseRace();  // Apply race modifiers

    cout << "Choose your character's class (Warrior, Mage, Rogue, Cleric, Paladin, Druid, Sorcerer, Barbarian, Monk, Ranger, Warlock, Bard): ";
    cin >> char_class;
    chooseClass();  // Apply class-specific abilities and info

    cout << "Rolling your character's stats..." << endl;

    // Roll stats for Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma
    strength = rollStat();
    dexterity = rollStat();
    constitution = rollStat();
    intelligence = rollStat();
    wisdom = rollStat();
    charisma = rollStat();

    calculateHP();  // Calculate HP based on class and Constitution modifier

    // Show the generated character's stats and background
    displayCharacter();
    saveCharacter();
}

// Function to choose race and apply modifiers
void chooseRace() {
    if (race == "Human") {
        strength += 1;
        dexterity += 1;
        constitution += 1;
        intelligence += 1;
        wisdom += 1;
        charisma += 1;
    } else if (race == "Elf") {
        dexterity += 2;
        intelligence += 1;
        wisdom += 1;
    } else if (race == "Dwarf") {
        constitution += 2;
        strength += 1;
    } else if (race == "Orc") {
        strength += 2;
        constitution += 2;
    } else if (race == "Tiefling") {
        charisma += 2;
        intelligence += 1;
    }
}

// Function to choose class and apply class-specific abilities and background
void chooseClass() {
    if (char_class == "Warrior") {
        background = "Warrior: A fierce fighter skilled in combat, often hailing from a military background.";
        strength += 2;
        constitution += 1;
        dexterity += 1;
    } else if (char_class == "Mage") {
        background = "Mage: A master of arcane magic, often coming from a scholarly or mystical background.";
        intelligence += 2;
        wisdom += 1;
        charisma += 1;
    } else if (char_class == "Rogue") {
        background = "Rogue: A quick and stealthy character, skilled in deception and thievery, often from a shady background.";
        dexterity += 2;
        intelligence += 1;
        charisma += 1;
    } else if (char_class == "Cleric") {
        background = "Cleric: A holy person, blessed with divine powers to heal and protect.";
        wisdom += 2;
        charisma += 1;
        constitution += 1;
    } else if (char_class == "Paladin") {
        background = "Paladin: A righteous warrior, devoted to the cause of justice and divine law.";
        strength += 2;
        charisma += 2;
        wisdom += 1;
    } else if (char_class == "Druid") {
        background = "Druid: A protector of nature, wielding powers derived from the earth and natural forces.";
        wisdom += 2;
        intelligence += 1;
        constitution += 1;
    } else if (char_class == "Sorcerer") {
        background = "Sorcerer: A spellcaster whose power comes from within, often due to a magical bloodline.";
        charisma += 2;
        intelligence += 1;
        dexterity += 1;
    } else if (char_class == "Barbarian") {
        background = "Barbarian: A primal warrior with immense strength and resilience, born from the wilderness.";
        strength += 2;
        constitution += 2;
        dexterity += 1;
    } else if (char_class == "Monk") {
        background = "Monk: A martial artist who has honed their body and mind to perfection.";
        dexterity += 2;
        wisdom += 2;
        strength += 1;
    } else if (char_class == "Ranger") {
        background = "Ranger: A skilled hunter and tracker, living off the land and protecting nature.";
        dexterity += 2;
        wisdom += 1;
        constitution += 1;
    } else if (char_class == "Warlock") {
        background = "Warlock: A spellcaster bound by pact to a powerful otherworldly patron.";
        charisma += 2;
        intelligence += 1;
        constitution += 1;
    } else if (char_class == "Bard") {
        background = "Bard: A jack-of-all-trades, using charm, music, and magic to inspire others.";
        charisma += 2;
        dexterity += 1;
        intelligence += 1;
    }

    printClassDetails();
    printBackgroundInfo();
}

// Print class-specific details
void printClassDetails() {
    cout << "\nClass: " << char_class << endl;
    if (char_class == "Warrior") {
        cout << "Warrior: A fierce fighter skilled in close combat. Known for their strength and resilience." << endl;
    } else if (char_class == "Mage") {
        cout << "Mage: Masters of arcane magic, Mages are powerful spellcasters with deep knowledge of the mystic arts." << endl;
    } else if (char_class == "Rogue") {
        cout << "Rogue: Rogues are quick, stealthy, and good at deception. Often they rely on agility and wit." << endl;
    } else if (char_class == "Cleric") {
        cout << "Cleric: Divine healers, Clerics use their god-given powers to mend wounds and protect the weak." << endl;
    } else if (char_class == "Paladin") {
        cout << "Paladin: Holy warriors bound by oath, fighting for justice and righteousness." << endl;
    } else if (char_class == "Druid") {
        cout << "Druid: Masters of nature magic, they protect the balance of the natural world." << endl;
    } else if (char_class == "Sorcerer") {
        cout << "Sorcerer: A spellcaster whose magic is innate, often tied to a powerful lineage." << endl;
    } else if (char_class == "Barbarian") {
        cout << "Barbarian: Warriors from the wilds, known for their ferocity and physical prowess." << endl;
    } else if (char_class == "Monk") {
        cout << "Monk: Martial artists who rely on their physical and spiritual training." << endl;
    } else if (char_class == "Ranger") {
        cout << "Ranger: Skilled in tracking and surviving in the wilderness, Rangers are nature's protectors." << endl;
    } else if (char_class == "Warlock") {
        cout << "Warlock: A pact-bound spellcaster, Warlocks wield eldritch power granted by a mysterious patron." << endl;
    } else if (char_class == "Bard") {
        cout << "Bard: Storytellers and performers, Bards weave magic through music and words." << endl;
    }
}

// Print the background information
void printBackgroundInfo() {
    cout << "\nBackground: " << background << endl;
}

// Function to calculate HP based on Constitution modifier
void calculateHP() {
    constitution_modifier = (constitution - 10) / 2; // D&D 5e formula for modifier
    
    // Basic HP formula: HP = 10 + Constitution modifier + class-specific bonuses
    if (char_class == "Warrior") {
        hp = 10 + constitution_modifier + 5;  // Warriors get extra HP
    } else if (char_class == "Mage") {
        hp = 10 + constitution_modifier + 2;  // Mages get a small bonus
    } else if (char_class == "Rogue") {
        hp = 10 + constitution_modifier + 3;  // Rogues have moderate HP
    } else if (char_class == "Cleric") {
        hp = 10 + constitution_modifier + 4;  // Clerics have balanced HP
    } else if (char_class == "Paladin") {
        hp = 10 + constitution_modifier + 6;  // Paladins have high HP
    } else if (char_class == "Druid") {
        hp = 10 + constitution_modifier + 5;  // Druids have balanced HP
    } else if (char_class == "Sorcerer") {
        hp = 10 + constitution_modifier + 2;  // Sorcerers have low HP
    } else if (char_class == "Barbarian") {
        hp = 10 + constitution_modifier + 8;  // Barbarians have very high HP
    } else if (char_class == "Monk") {
        hp = 10 + constitution_modifier + 5;  // Monks have moderate HP
    } else if (char_class == "Ranger") {
        hp = 10 + constitution_modifier + 4;  // Rangers have moderate HP
    } else if (char_class == "Warlock") {
        hp = 10 + constitution_modifier + 3;  // Warlocks have moderate HP
    } else if (char_class == "Bard") {
        hp = 10 + constitution_modifier + 3;  // Bards have moderate HP
    }

    max_hp = hp;  // Set max HP to the current HP value
    cout << "Initial HP: " << hp << endl;
}

// Function to simulate leveling up
void levelUp() {
    xp += 100; // Award 100 XP for leveling up (just for demo)

    if (xp >= 100) { // Level up condition
        level++;
        xp = 0; // Reset XP after level up
        cout << "Congratulations! You have leveled up to Level " << level << "!" << endl;
        max_hp += 5; // Increase max HP with each level
        hp = max_hp; // Restore HP to max HP when leveling up
    }
}

// Function to display the character's stats
void displayCharacter() {
    cout << "\nCharacter Stats for " << name << " (" << char_class << " - " << race << "):\n";
    cout << "Strength: " << strength << endl;
    cout << "Dexterity: " << dexterity << endl;
    cout << "Constitution: " << constitution << endl;
    cout << "Intelligence: " << intelligence << endl;
    cout << "Wisdom: " << wisdom << endl;
    cout << "Charisma: " << charisma << endl;
    cout << "Level: " << level << endl;
    cout << "XP: " << xp << endl;
    cout << "HP: " << hp << "/" << max_hp << endl;
}

// Function to save the character to a file
void saveCharacter() {
    ofstream file("character.txt");
    
    if (file.is_open()) {
        file << "Name: " << name << endl;
        file << "Race: " << race << endl;
        file << "Class: " << char_class << endl;
        file << "Strength: " << strength << endl;
        file << "Dexterity: " << dexterity << endl;
        file << "Constitution: " << constitution << endl;
        file << "Intelligence: " << intelligence << endl;
        file << "Wisdom: " << wisdom << endl;
        file << "Charisma: " << charisma << endl;
        file << "Level: " << level << endl;
        file << "XP: " << xp << endl;
        file << "HP: " << hp << "/" << max_hp << endl;
        file.close();
        cout << "Character saved to 'character.txt'.\n";
    } else {
        cout << "Error saving character to file.\n";
    }
}

// Function to simulate a dice roll (d6)
int rollDice() {
    return rand() % 6 + 1; // Returns a number between 1 and 6
}

// Function to roll a stat (four d6 and discard the lowest)
int rollStat() {
    int roll1 = rollDice();
    int roll2 = rollDice();
    int roll3 = rollDice();
    int roll4 = rollDice();

    // Find the lowest roll and discard it
    int rolls[] = {roll1, roll2, roll3, roll4};
    int minRoll = rolls[0];

    for (int i = 1; i < 4; i++) {
        if (rolls[i] < minRoll) {
            minRoll = rolls[i];
        }
    }

    // Sum the remaining three rolls
    int stat = roll1 + roll2 + roll3 + roll4 - minRoll;
    return stat;
}



