#ifndef __LEXER_H
#define __LEXER_H

#include <string>
#include <vector>

enum type {
  TOKEN_PLUS,
  TOKEN_MINUS,
  TOKEN_LT,
  TOKEN_GT,
  TOKEN_LB,
  TOKEN_RB,
  TOKEN_DOT,
  TOKEN_COMMA
};

struct Token {
  enum type TYPE;
  std::string VALUE;
};

std::string typeToString(enum type TYPE) {
  switch (TYPE) {
  case TOKEN_PLUS:
    return "TOKEN_PLUS";
  case TOKEN_MINUS:
    return "TOKEN_MINUS";
  case TOKEN_LT:
    return "TOKEN_LT";
  case TOKEN_GT:
    return "TOKEN_GT";
  case TOKEN_LB:
    return "TOKEN_LB";
  case TOKEN_RB:
    return "TOKEN_RB";
  case TOKEN_DOT:
    return "TOKEN_DOT";
  case TOKEN_COMMA:
    return "TOKEN_COMMA";
  }
  return "UNKOWN";
};

class Lexer {
public:
  Lexer(std::string sourceCode) {
    source = sourceCode;
    size = sourceCode.length();
    cursor = 0;
    current = source.at(cursor);
  }

  std::vector<Token *> tokenize() {
    std::vector<Token *> tokens;

    while (cursor < size) {
      current = source.at(cursor);
      Token *new_tok = new Token();
      new_tok->VALUE = current;
      switch (current) {
      case '+':
        new_tok->TYPE = TOKEN_PLUS;
        tokens.push_back(new_tok);
        break;
      case '-':
        new_tok->TYPE = TOKEN_MINUS;
        tokens.push_back(new_tok);
        break;
      case '<':
        new_tok->TYPE = TOKEN_LT;
        tokens.push_back(new_tok);
        break;
      case '>':
        new_tok->TYPE = TOKEN_GT;
        tokens.push_back(new_tok);
        break;
      case '[':
        new_tok->TYPE = TOKEN_LB;
        tokens.push_back(new_tok);
        break;
      case ']':
        new_tok->TYPE = TOKEN_RB;
        tokens.push_back(new_tok);
        break;
      case '.':
        new_tok->TYPE = TOKEN_DOT;
        tokens.push_back(new_tok);
        break;
      case ',':
        new_tok->TYPE = TOKEN_COMMA;
        tokens.push_back(new_tok);
        break;
      }
      cursor++;
    }
    return tokens;
  }

private:
  std::string source;
  int cursor;
  int size;
  char current;
};

#endif
