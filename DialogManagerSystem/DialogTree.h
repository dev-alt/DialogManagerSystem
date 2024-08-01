#pragma once

#include "DialogNode.h"
#include <memory>

class DialogTree {
private:
    std::shared_ptr<DialogNode> root;

public:
    DialogTree(std::shared_ptr<DialogNode> rootNode); // Constructor

    // Starts the dialog from the root node
    void StartDialog();

    // Allows setting a new root node
    void SetRoot(std::shared_ptr<DialogNode> rootNode);
};
