#pragma once

#include <string>
#include <vector>
#include <memory>

class DialogNode {
public:
    std::string text; // The text of this dialog node
    std::vector<std::pair<std::string, std::shared_ptr<DialogNode>>> options; // List of options leading to other nodes

    DialogNode(const std::string& text); // Constructor

    // Adds an option to this dialog node
    void AddOption(const std::string& optionText, std::shared_ptr<DialogNode> nextNode);
};
