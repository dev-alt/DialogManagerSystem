#include <iostream>
#include "DialogSystem.h"
#include "DialogSaveLoad.h"
using namespace std;

int main()
{
    // Create the root dialog node
    auto root = make_shared<DialogNode>("Welcome to the game! What will you do?");

    // Create first set of options
    auto fightDragon = make_shared<DialogNode>("You chose to fight the dragon! It's a fierce battle...");
    auto runAway = make_shared<DialogNode>("You chose to run away! You live to fight another day.");

    // Add options to the root node
    root->AddOption("Fight the dragon", fightDragon);
    root->AddOption("Run away", runAway);

    // Additional dialog nodes for fighting the dragon
    auto useSword = make_shared<DialogNode>("You use your sword and slay the dragon!");
    auto useMagic = make_shared<DialogNode>("You use magic to defeat the dragon, but at a cost...");

    // Add more options to the fightDragon node
    fightDragon->AddOption("Use sword", useSword);
    fightDragon->AddOption("Use magic", useMagic);

    // Additional dialog nodes for running away
    auto hideInCave = make_shared<DialogNode>("You hide in a cave and wait for the danger to pass.");
    auto returnHome = make_shared<DialogNode>("You return home, safe but filled with regret.");

    // Add more options to the runAway node
    runAway->AddOption("Hide in a cave", hideInCave);
    runAway->AddOption("Return home", returnHome);

    // Create the dialog tree
    DialogTree dialogTree(root);

    // Save the dialog tree
    DialogSaveLoad::SaveDialogTree(dialogTree, "dialog_tree.txt");

    // Start the dialog
    cout << "Original Dialog Tree:\n";
    dialogTree.StartDialog();

    // Load the dialog tree
    DialogTree loadedTree = DialogSaveLoad::LoadDialogTree("dialog_tree.txt");

    // Start the loaded dialog
    cout << "\nLoaded Dialog Tree:\n";
    loadedTree.StartDialog();

    return 0;
}