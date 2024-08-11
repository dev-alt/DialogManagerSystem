# Dialog System

This project implements a simple dialog system for text-based games or interactive stories using C++. It provides a flexible structure for creating branching dialogues with multiple choice options.

## Features

- Create a tree-like structure of dialog nodes
- Each node can have multiple options leading to other nodes
- Easy to integrate into existing game systems
- Console-based interaction for demonstration purposes

## Components

1. **DialogNode**: Represents a single dialog node with text and options.
2. **DialogTree**: Manages the structure of the dialog, including navigation between nodes.
3. **DialogSystem**: A header that includes all necessary components for easy integration.

## How to Use

1. Clone the repository
2. Open the project in Visual Studio (a .vcxproj file is included)
3. Build and run the project

The main function in `DialogManagerSystem.cpp` provides an example of how to create a simple dialog tree and interact with it.

## Example

Here's a simple example of how to create a dialog tree:

```cpp
auto root = make_shared<DialogNode>("Welcome to the game! What will you do?");

auto fightDragon = make_shared<DialogNode>("You chose to fight the dragon! It's a fierce battle...");
auto runAway = make_shared<DialogNode>("You chose to run away! You live to fight another day.");

root->AddOption("Fight the dragon", fightDragon);
root->AddOption("Run away", runAway);

DialogTree dialogTree(root);
dialogTree.StartDialog();
```

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is open source and available under the [MIT License](LICENSE).

## Contact

If you have any questions, feel free to open an issue or contact the repository owner.

---

Happy coding!
