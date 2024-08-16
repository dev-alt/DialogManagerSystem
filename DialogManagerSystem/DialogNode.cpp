#include "DialogNode.h"


// Constructor
DialogNode::DialogNode(const std::string& text) : text(text) {}

// Adds an option to the dialog node
void DialogNode::AddOption(const std::string& optionText, std::shared_ptr<DialogNode> nextNode) {
    options.push_back({ optionText, nextNode });
}
