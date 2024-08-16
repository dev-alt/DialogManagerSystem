#pragma once
#include "DialogTree.h"
#include <string>

class DialogSaveLoad {
public:
    static void SaveDialogTree(const DialogTree& tree, const std::string& filename);
    static DialogTree LoadDialogTree(const std::string& filename);

private:
    static void SaveNode(std::ofstream& out, const DialogNode& node, int depth);
    static std::shared_ptr<DialogNode> LoadNode(std::ifstream& in);
};
