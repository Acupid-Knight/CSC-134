Thief: A Haunted Mystery

Overview

"Thief: A Haunted Mystery" is a C++ text-based adventure game that combines horror, exploration, and decision-based storytelling. The player takes on the role of a daring individual who enters a haunted house on a dare, only to uncover the chilling secrets that lie within. Through a structured act and scene system, players make choices that shape their fate, interact with mysterious elements, navigate dangerous rooms, and encounter supernatural beings like Selene.

Features

Narrative-Driven Acts: The story unfolds across six acts, each containing vivid scenes that build suspense and player immersion.

Room Navigation: Includes an explorable dungeon system where players traverse rooms connected through a graph-like structure.

Inventory System: Players can collect and use items that influence the narrative and determine different endings.

Branching Paths: Multiple decisions influence the direction and outcome of the story.

Consequences: Death, survival, sacrifice, and supernatural interactions are all shaped by the player's actions.

Structure

Acts & Scenes

Act I: The Dare – Introduction and the choice to enter or retreat.

Act II: Entry – First look inside the haunted house, with survival instincts tested.

Act III: Exploration – Player investigates either the upstairs or hides.

Act IV: The Dungeon Descent – Exploration begins in a graph-based dungeon with rooms, traps, and a relic.

Act V: Echoes and Revelation – Story-driven flashbacks and emotional choices.

Act VI: Final Trial – Ultimate decision determines one of multiple endings.

Room System

Rooms are connected in a directed manner, each with:

Descriptions

Possible connections to other rooms

Potential dangers (traps)

Rewards (items or relics)

Items

Example: Silver Fang – A key item required for certain narrative outcomes.

Gameplay Instructions

Compile and run the program in any C++ IDE or terminal supporting C++11 or later.

Make narrative choices by entering the number corresponding to your desired action.

Navigate through rooms, collect items, and survive traps.

Your decisions will lead to one of multiple endings.

Controls

Numeric Input – All choices are made by selecting numbers from prompted options.

Inventory Collection – When prompted, choose to take or leave items.

Requirements

C++11 or later

Standard I/O libraries (iostream, vector, string, etc.)

Compilation (Example for g++)

 g++ -std=c++11 haunted_thief.cpp -o haunted_thief
 ./haunted_thief

Example Ending Outcomes

Trust Selene and possess the Silver Fang → Escape with guidance

Attempt to escape alone → Coward ending

Sacrifice yourself → Spiritual ending

Smash the relic → Chaos ending

File Summary

haunted_thief.cpp – Main game file containing all logic, room structure, story narrative, and gameplay loop.

Author Notes

This project blends horror fiction with game logic, showcasing C++ fundamentals including classes, vectors, dynamic memory, user input validation, and storytelling techniques. The game emphasizes the importance of every decision, mimicking real psychological tension through branching choices and consequences.

Future Improvements