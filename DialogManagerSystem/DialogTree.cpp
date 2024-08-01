#include "DialogTree.h"
#include <iostream>

// Constructor
DialogTree::DialogTree(std::shared_ptr<DialogNode> rootNode) : root(rootNode) {}

// Starts the dialog, printing options and handling user input
void DialogTree::StartDialog() {
    std::shared_ptr<DialogNode> currentNode = root;
    while (currentNode != nullptr) {
        std::cout << currentNode->text << std::endl;

        if (currentNode->options.empty()) break;

        for (size_t i = 0; i < currentNode->options.size(); ++i) {
            std::cout << i + 1 << ": " << currentNode->options[i].first << std::endl;
        }

        int choice;
        std::cin >> choice;
        choice -= 1;  // Adjust for 0-based index

        if (choice >= 0 && choice < currentNode->options.size()) {
            currentNode = currentNode->options[choice].second;
        }
        else {
            std::cout << "Invalid choice." << std::endl;
            currentNode = nullptr;
        }
    }
}

// Allows setting a new root node
void DialogTree::SetRoot(std::shared_ptr<DialogNode> rootNode) {
    root = rootNode;
}
