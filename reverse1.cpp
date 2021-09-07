// reverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

class Glossary : public std::vector<std::pair<std::string, uint32_t>>
{
public:
    void AddWord(const std::string& _word) {
        if (1 >= _word.size()) return;

        auto item = std::find_if(begin(), end(), [_word](const auto& _inList) { return (0 == _inList.first.compare(_word)); });
        if (end() == item) push_back(std::make_pair(_word, 1));
        else item->second++;
    }

    void DumpToFile(const std::string& _file) {
        std::ofstream file(_file);
        if (file.bad()) { std::cout << "Error opening output file: " << _file << "\n"; return; }
        std::sort(begin(), end(), [](const auto& _el1, const auto& _el2) { return (_el1.second > _el2.second); });
        for (const auto& item : *this) file << item.first << ", " << std::to_string(item.second) << "\n";
        file.close();
    }
};

static void _NewWordFound(Glossary& _glossary, std::ofstream& _reverseFile, std::string& _word) {
    if (_word.empty()) return;
    _glossary.AddWord(_word);
    std::reverse(_word.begin(), _word.end());
    _reverseFile << _word;
    _word.clear();
}

static std::vector<char> gRealCharacters = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'é', 'è', 'ê', 'à', 'â', 'ë', 'û', 'ù', 'î', 'ç', 'ô', 'ö', 'ü' };
bool _IsRealCharacter(const char _char) { return (std::cend(gRealCharacters) != std::find(std::cbegin(gRealCharacters), std::cend(gRealCharacters), _char)); }

#define CHECKWORDLENGTH                                                         \
    if (word.length() >= 64) {                                                  \
        std::cout << "A word exceeds 64 characters limit, exiting...\n";        \
        goto exit;                                                              \
    }                                                                           \

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::string exePath(argv[0]);
        size_t pos = exePath.rfind('\\') + 1;
        std::cout << "Usage: " << exePath.substr(pos, exePath.size() - pos) << " file\n";
        return 0;
    }

    std::ifstream file(argv[1]);
    if (file.bad()) {
        std::cout << "Could not open input file: \"" << argv[1] << "\" \n";
        return 0;
    }

    std::string inputFilePath(argv[1]);
    std::string fileNameRoot = (0 == inputFilePath.substr(inputFilePath.length() - 4, 4).compare(".txt")) ? inputFilePath.substr(0, inputFilePath.length() - 4) : inputFilePath;

    std::ofstream reverseFile(fileNameRoot + ".reverse.txt");
    if (reverseFile.bad()) {
        std::cout << "Error opening output reverse file: " << fileNameRoot << ".reverse.txt" << "\n";
        return 0;
    }

    Glossary reverseGlossary;
    char cur;
    std::string word;
    while (file.get(cur).good())
    {
        if (_IsRealCharacter(cur)) word += cur;
        else {
            CHECKWORDLENGTH
            _NewWordFound(reverseGlossary, reverseFile, word);
            reverseFile << cur;
        }
    }
    CHECKWORDLENGTH
    _NewWordFound(reverseGlossary, reverseFile, word);

    reverseGlossary.DumpToFile(fileNameRoot + ".table.txt");

exit:

    reverseFile.close();
    file.close();

    return 0;
}
