#include "DialogSaveLoad.h"
#include <fstream>
#include <sstream>

void DialogSaveLoad::SaveDialogTree(const DialogTree& tree, const std::string& filename) {
    std::ofstream out(filename);
    SaveNode(out, *tree.GetRoot(), 0);
}

void DialogSaveLoad::SaveNode(std::ofstream& out, const DialogNode& node, int depth) {
    out << std::string(depth, '\t') << "NODE:" << node.text << '\n';
    for (const auto& option : node.options) {
        out << std::string(depth + 1, '\t') << "OPTION:" << option.first << '\n';
        SaveNode(out, *option.second, depth + 2);
    }
}

DialogTree DialogSaveLoad::LoadDialogTree(const std::string& filename) {
    std::ifstream in(filename);
    auto root = LoadNode(in);
    return DialogTree(root);
}

std::shared_ptr<DialogNode> DialogSaveLoad::LoadNode(std::ifstream& in) {
    std::string line;
    std::getline(in, line);
    std::istringstream iss(line);
    std::string prefix;
    std::getline(iss, prefix, ':');
    std::string nodeText;
    std::getline(iss, nodeText);

    auto node = std::make_shared<DialogNode>(nodeText);

    while (std::getline(in, line)) {
        if (line.find("NODE:") != std::string::npos) {
            in.seekg(static_cast<std::basic_istream<char, std::char_traits<char>>::off_type>(-static_cast<int>(line.length())) - 1, std::ios::cur);
            break;
        }
        if (line.find("OPTION:") != std::string::npos) {
            std::istringstream optionIss(line);
            std::string optionPrefix;
            std::getline(optionIss, optionPrefix, ':');
            std::string optionText;
            std::getline(optionIss, optionText);
            auto childNode = LoadNode(in);
            node->AddOption(optionText, childNode);
        }
    }

    return node;
}