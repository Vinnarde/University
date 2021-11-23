//
// Created by Pepega on 09.11.2021.
//

#ifndef LAB_3_TOKENIZER_H
#define LAB_3_TOKENIZER_H

#include <utility>
#include <vector>
#include <string>

namespace simpleparser {

    using namespace std;

    enum syntaxKind {
        WhitespaceToken,
        BooleanTrueToken,
        BooleanFalseToken,
        BooleanOrToken,
        BooleanAndToken,
        BooleanXorToken,
        BooleanNotToken,
        OpenParenthesisToken,
        CloseParenthesisToken,
        SemicolonToken,
        AssignToken,
        IdentifierToken,
        BadToken,
        EndOfFileToken
    };

    const char *syntaxKindToString(syntaxKind e) noexcept;

    class syntaxToken {
    public:
        syntaxToken();

        syntaxToken(syntaxKind kind, int position, std::string text, std::string value) {
            mKind = kind;
            mPosition = position;
            mText = std::move(text);
            mValue = std::move(value);
        }

        syntaxToken(const syntaxToken &obj);

        syntaxToken &operator=(const syntaxToken &other);

        bool operator==(const syntaxToken &obj) const;

        syntaxKind mKind;
        int mPosition;
        std::string mText;
        std::string mValue;

    };

    class Lexer {
        std::string mText;
        int mPosition{0};

        char currentToken();

        void next();

    public:
        explicit Lexer(std::string text) {
            mText = std::move(text);
        }

        syntaxToken nextToken();
    };

    struct syntaxTokenHasher
    {
        size_t operator() (const syntaxToken &obj) const
        {
            return std::hash<std::string>()(obj.mText);
        }
    };

}

#endif //LAB_3_TOKENIZER_H
