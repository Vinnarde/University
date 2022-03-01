#include <iostream>
#include <string>
#include <iomanip>
#include <unordered_set>

#include "Tokenizer.h"
#include "Hashtable.h"
#include "HashMap.h"

using namespace simpleparser;

std::size_t getId(const std::unordered_set<syntaxToken, syntaxTokenHasher> &table, const syntaxToken &token) {
    return std::distance(table.begin(), table.find(token));
}

void printTable(const std::unordered_set<syntaxToken, syntaxTokenHasher> &table) {

    std::size_t idColumnLength{8}, valueColumnLength{16}, typeColumnLength{32};

    std::cout << std::setw(idColumnLength + valueColumnLength + typeColumnLength + 1) << std::setfill('-') << '\n';

    std::cout << std::setw(idColumnLength) << std::setfill(' ') << "Id";
    std::cout << std::setw(valueColumnLength) << std::setfill(' ') << "Value";
    std::cout << std::setw(typeColumnLength) << std::setfill(' ') << "Type";

    std::cout << '\n';

    std::cout << std::setw(idColumnLength + valueColumnLength + typeColumnLength + 1) << std::setfill('-') << '\n';

    for (const auto& item: table) {
        std::size_t id = getId(table, item);
        std::cout << std::setw(8) << std::setfill(' ') << id;
        std::cout << std::setw(16) << std::setfill(' ') << item.mText;
        std::cout << std::setw(32) << std::setfill(' ') << syntaxKindToString(item.mKind);
        std::cout << '\n';
    }
    std::cout << std::setw(idColumnLength + valueColumnLength + typeColumnLength + 1) << std::setfill('-') << '\n';
}

int main() {
    std::unordered_set<syntaxToken, syntaxTokenHasher> table;
    HashMap<std::string, syntaxToken>myTable;

    while (true) {
        std::cout << "> ";
        std::string line;
        std::getline(std::cin, line);

        if (line.empty())
            return 0;

//        auto lexer = new Lexer(line);
        Lexer lexer(line);
        while (true) {
            auto token = lexer.nextToken();
            if (token.mKind == EndOfFileToken)
                break;
            std::cout << syntaxKindToString(token.mKind) << ": '" << token.mText << "'";
            if (token.mValue != "null")
                std::cout << ' ' << token.mValue;
            std::cout << '\n';

            if (token.mKind == BooleanTrueToken ||
                token.mKind == BooleanFalseToken ||
                token.mKind == IdentifierToken) {

                table.insert(token);
                myTable.insert(token.mText, token);
            }
        }

        Lexer lexer1(line);
        std::string output;
        while (true) {
            auto token = lexer1.nextToken();
            if (token.mKind == EndOfFileToken)
                break;

            if (token.mKind == BooleanTrueToken ||
                token.mKind == BooleanFalseToken ||
                token.mKind == IdentifierToken) {
                output += "<id" + std::to_string(getId(table, token)) + ">";
            }
            else if (token.mKind != BadToken && token.mKind != WhitespaceToken)
            {
                output += token.mText;
            }

        }

        printTable(table);
        std::cout << output << '\n';
        myTable.display();
        table.erase(table.begin(),table.end());

    }

    return 0;
}
