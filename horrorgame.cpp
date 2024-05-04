#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>


class HorrorGame {
private:
    std::map<std::string, std::string> inventory;
    std::vector<std::string> rooms = {"entrance", "living room", "kitchen", "library", "secret room", "main hall", "attic"};
    std::map<std::string, bool> visited;
    std::string currentRoom = "entrance";
    int health = 100;
    bool alive = true;
    bool ghostPacified = false;


public:
    HorrorGame() {
        for (const auto& room : rooms) {
            visited[room] = false;
        }
    }


void startGame() {
    std::cout << "You wake up in a cold, dark room. You must find your way out of this haunted mansion." << std::endl;
    while (alive && health > 0) {
        displayRoom();
        std::string action;
        std::cout << "What would you like to do? (move, search, check inventory, check health)" << std::endl;
        std::getline(std::cin, action);  // Using getline to read full line input
        handleAction(action);

        // Check for game-ending conditions
        if (currentRoom == "secret room" && inventory.find("key") != inventory.end()) {
            std::cout << "You use the key to unlock the door and escape the mansion!" << std::endl;
            break;
        } else if (currentRoom == "main hall" && ghostPacified) {
            std::cout << "The spirit finds peace, and the hauntings cease. You've brought peace to the mansion." << std::endl;
            break;
        }
    }

    if (health <= 0) {
        std::cout << "You have succumbed to your injuries..." << std::endl;
        alive = false;
        endingSacrifice();
    }
}



private:
    void handleAction(const std::string& action) {
        if (action == "move") {
            move();
        } else if (action == "search") {
            searchRoom();
        } else if (action == "check inventory") {
            showInventory();
        } else if (action == "check health") {
            std::cout << "Your health is at: " << health << std::endl;
        } else {
            std::cout << "Invalid action. Try again." << std::endl;
        }
    }


    void displayRoom() {
        std::cout << "You are in the " << currentRoom << "." << std::endl;
        if (!visited[currentRoom]) {
            std::cout << "It feels eerie and unwelcoming." << std::endl;
            visited[currentRoom] = true;
        }
    }


    void move() {
        std::string nextRoom;
        std::cout << "Where would you like to go? (available rooms: ";
        for (const auto& room : rooms) {
            if (room != currentRoom) {
                std::cout << room << " ";
            }
        }
        std::cout << ")" << std::endl;
        std::cin >> nextRoom;
        if (std::find(rooms.begin(), rooms.end(), nextRoom) != rooms.end()) {
            currentRoom = nextRoom;
            if (currentRoom == "library") {
                health -= 10;  // Example hazard
                std::cout << "A ghostly figure touches you. You feel weaker." << std::endl;
            }
        } else {
            std::cout << "You can't go there. Try another room." << std::endl;
        }
    }


    void searchRoom() {
        if (currentRoom == "library" && visited[currentRoom] == false) {
            inventory["key"] = "An ornate key that looks very old. It might unlock something important.";
            std::cout << "You found a key hidden behind a dusty old book." << std::endl;
        } else if (currentRoom == "main hall" && visited[currentRoom] == false && inventory.find("crucifix") != inventory.end()) {
            std::cout << "You use the crucifix and the ghostly lord of the mansion appears. He seems calm as you recite a passage.";
            ghostPacified = true;
        } else {
            std::cout << "You find nothing new here." << std::endl;
        }
    }


    void showInventory() {
        if (inventory.empty()) {
            std::cout << "Your inventory is empty." << std::endl;
        } else {
            std::cout << "You have the following items in your inventory:" << std::endl;
            for (const auto& item : inventory) {
                std::cout << item.first << ": " << item.second << std::endl;
            }
        }
    }


    void endingSacrifice() {
        std::cout << "In the dim light of the moon, the spirits of the mansion overwhelm you. The mansion claims another soul." << std::endl;
    }
};


int main() {
    HorrorGame game;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
    game.startGame();
    return 0;
}

