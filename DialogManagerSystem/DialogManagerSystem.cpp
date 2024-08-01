// DialogManagerSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DialogSystem.h"

int main()
{
    auto root = std::make_shared<DialogNode>("Welcome to the game! What will you do?");
    auto option1 = std::make_shared<DialogNode>("You chose to fight the dragon!");
    auto option2 = std::make_shared<DialogNode>("You chose to run away!");

    // Add options to the root node
    root->AddOption("Fight the dragon", option1);
    root->AddOption("Run away", option2);

    // Create the dialog tree
    DialogTree dialogTree(root);

    // Start the dialog
    dialogTree.StartDialog();

    return 0;
}
