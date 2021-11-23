//
// Created by Pepega on 09.11.2021.
//

#include "Tokenizer.h"

namespace simpleparser {

    using namespace std;

    const char *syntaxKindToString(syntaxKind e) noexcept {
        switch (e) {
            case WhitespaceToken:
                return "WhitespaceToken";
            case BooleanTrueToken:
                return "BooleanTrueToken";
            case BooleanFalseToken:
                return "BooleanFalseToken";
            case BooleanOrToken:
                return "BooleanOrToken";
            case BooleanAndToken:
                return "BooleanAndToken";
            case BooleanXorToken:
                return "BooleanXorToken";
            case BooleanNotToken:
                return "BooleanNotToken";
            case OpenParenthesisToken:
                return "OpenParenthesisToken";
            case CloseParenthesisToken:
                return "CloseParenthesisToken";
            case SemicolonToken:
                return "SemicolonToken";
            case AssignToken:
                return "AssignToken";
            case IdentifierToken:
                return "IdentifierToken";
            case BadToken:
                return "BadToken";
            case EndOfFileToken:
                return "EndOfFileToken";
        }
    }

    char Lexer::currentToken() {
        if (mPosition >= mText.length())
            return '\0';

        return mText.at(mPosition);
    }

    void Lexer::next() {
        mPosition++;
    }

    syntaxToken Lexer::nextToken() {

        // 0 1
        // | & ^ ! ( ) ;
        // <whitespaces>

        if (mPosition >= mText.length())
            return syntaxToken{EndOfFileToken, mPosition, "", "null"};

        // 0
        if (currentToken() == '0')
            return syntaxToken{BooleanFalseToken, mPosition++, "0", "0"};
        // 1
        if (currentToken() == '1')
            return syntaxToken{BooleanTrueToken, mPosition++, "1", "1"};

        if (currentToken() == '|')
            return {BooleanOrToken, mPosition++, "|", "null"};
        if (currentToken() == '&')
            return {BooleanAndToken, mPosition++, "&", "null"};
        if (currentToken() == '^')
            return {BooleanXorToken, mPosition++, "^", "null"};
        if (currentToken() == '!')
            return {BooleanNotToken, mPosition++, "!", "null"};
        if (currentToken() == '(')
            return {OpenParenthesisToken, mPosition++, "(", "null"};
        if (currentToken() == ')')
            return {CloseParenthesisToken, mPosition++, ")", "null"};
        if (currentToken() == ';')
            return {SemicolonToken, mPosition++, ";", "null"};
        if (currentToken() == '=')
            return {AssignToken, mPosition++, "=", "null"};

        if (std::isspace(currentToken())) {
            int start = mPosition;
            while (std::isspace(currentToken()))
                next();

            int length = mPosition - start;
            std::string text = mText.substr(start, length);

            return {WhitespaceToken, start, text, "null"};
        }

        if (std::isalpha(currentToken())) {
            int start = mPosition;
            while (std::isalpha(currentToken()) || std::isdigit(currentToken()))
                next();

            int length = mPosition - start;
            std::string text = mText.substr(start, length);

            return {IdentifierToken, start, text, "null"};
        }

        return {BadToken, mPosition++, mText.substr(mPosition - 1, 1), "null"};

    }


    syntaxToken::syntaxToken() {
        mKind = BadToken;
        mPosition = 0;
        mText = "";
        mValue = "";
    }

    syntaxToken::syntaxToken(const syntaxToken &obj) {
        mKind = obj.mKind;
        mPosition = obj.mPosition;
        mText = obj.mText;
        mValue = obj.mValue;
    }

    syntaxToken &syntaxToken::operator=(const syntaxToken &obj) {
        mKind = obj.mKind;
        mPosition = obj.mPosition;
        mText = obj.mText;
        mValue = obj.mValue;
        return *this;
    }

    bool syntaxToken::operator==(const syntaxToken &obj) const {
        return mText == obj.mText;
    }


}
