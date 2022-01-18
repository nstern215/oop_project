1.
Oop project

2.
Netanel Stern, ID 206342255
Daniel Yosef, ID 322017518

3.
In this project we recreated the game of "Save The King".
The code was writen with a combination of libraries including SFML in order to give the game 
more of color.
This version of the game included more elements like the game being timed, dwarfs moving on the board.
(+-*).

The logic tries to use less memory as possible combined with the best time complexity

4.
The different objects in this project are mainly the characters and the board_items.
Being that the characters are representing the objects that can move on the map, and the board_items
representing the items on the map that cannot move but yet have an effect on the ongoing of the game.
 

5.
The file being used to load the levels is actually a file holding the names of other files that each of those
files holds a map of the upcoming level.
The reason for this format is to simplify the load of each level for each level is indivedual and not part
of one very long file.


6.
Header files:
BoardItems.h- holds the class of boardItems witch is the root of Item.
Characters.h- holds the class of Characters witch is the root of Item.
Clock.h- holds the class of clock and its functions.
ClockMode.h- holds the enum of the clock modes.
controller.h- holds the class of controller and its functions. this class puts all the the game to play. 
Dwarf.h- holds the class of Dwarf witch is the root of Characters Becouse it moves on the board.
Fire.h- holds the class of Fire and its functions witch is a root of BoardItems.
GameMode.h- holds the Enum of game_modes.
Gate.h- holds the class of Gate and its functions witch is a root of BoardItems.
Item.h- the main class of the items that will appear on the board.
Key.h- holds the class of Key and its functions witch is a root of BoardItems.
King.h- holds the class of King and its functions witch is a root of Characters.
LevelData.h- holds the struct of levels data along the game.
LevelsManager.h- holds the class of levels manager and its functions.
Location.h- holds the struct location.
Mage.h- holds the class of Mage and its functions witch is a root of Characters.
Menu.h- holds the class of menu and its functions.
MenuItem.h- holds the class of menuItems and its functions.
Ork.h- holds the class of Ork and its functions witch is a root of BoardItems.
ResourcesService.h- holds the class and functions of ResourcesService.
Teleport.h- holds the class of Teleports and its functions witch is a root of BoardItems.
Thief.h- holds the class of Thief and its functions witch is a root of Characeters.
Throne.h- holds the class of Throne and its functions witch is a root of BoardItems.
Wall.h- holds the class of Wall and its functions witch is a root of BoardItems.
Warrier.h- holds the class of Warrier and its functions witch is a root of Characters.

CPP files:
BoardItems.cpp- implementation of BoardItems class.
Characters.cpp-implementation of Cahracters class.
Clock.cpp- implementation of Clock class.
controller.cpp- implementation of Controller class.
Dwarf.cpp- implementation of Dwarf class.
Fire.cpp- implementation of Fire class.
Gate.cpp- implementation of Gate class.
Item.cpp- implementation of Item class.
Key.cpp- implementation of Key class.
King.cpp- implementation of King class.
LevelsManager.cpp- implementation of LevelsManager class.
Mage.cpp- implementation of Mage class. 
Menu.cpp- implementation of Menu class.
MenuItem.cpp- implementation of MenuItem class.
Ork.cpp- implementation of Ork class 
ResourcesService.cpp-implementation of ResourcesService class
Teleport.cpp- implementation of teleport class
Thief.cpp- implementation of thief class.
Throne.cpp- implementation of Throne class.
Wall.cpp- implementation of Wall class.
Warrier.cpp- implementation of Warrier class.

7. 
Characters vector:
BoardItems vector:
Location struct:

8.

9.
We have an minor issue with the dwards that can stack in place

10.
Daniel has been called to Miluim for most of the time and we did our best