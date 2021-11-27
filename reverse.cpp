// reverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Replacement of the STL (and others includes)
#include "mystl.h"

class Glossary : public MyVector
{
private:
public:
    void AddWord(const MyString& _word) {
        if (1 >= _word.length()) return;
        auto item = find_if(begin(), end(), _word);
        if (item < 0) push_back(MyPair::make_pair(_word, 1));
        else {
            accessMyPairMember(item).IncrementOccurrence();
        }
    }

    void DumpToFile(const MyString& _file) {
        std::ofstream file(_file);
        if (file.bad()) { std::cout << "Error opening output file: " << _file << "\n"; return; }
        sort();
        for (int i = m_count - 1; i >= 0; i--) file << accessMyPairMember(i).getText() << ", " << std::to_string(accessMyPairMember(i).getOccurrence()) << "\n";
        file.close();
    }

};

static void _NewWordFound(Glossary& _glossary, std::ofstream& _reverseFile, MyString& _word) {
    if (_word.empty()) return;
    _glossary.AddWord(_word);
    _word.reverse();
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
    
    MyString inputFilePath(argv[1]);
    MyString fileNameRoot = inputFilePath.substr(inputFilePath.length() - 4, 4).equals(".txt") ? inputFilePath.substr(0, inputFilePath.length() - 4) : inputFilePath; //???

    std::ofstream reverseFile(fileNameRoot + ".reverse.txt");

    if (reverseFile.bad()) {
        std::cout << "Error opening output reverse file: " << fileNameRoot << ".reverse.txt" << "\n";
        return 0;
    }
    
    Glossary reverseGlossary;
    char cur;
    MyString word;
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
