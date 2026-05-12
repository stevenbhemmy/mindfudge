#include <algorithm>

#include <catch2/catch_test_macros.hpp>

#include <Lexer.h>

int factorial(int number) {
	return number <= 1 ? number : factorial(number - 1) * number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
  REQUIRE(factorial(1) == 1);
  REQUIRE(factorial(2) == 2);
  REQUIRE(factorial(3) == 6);
  REQUIRE(factorial(10) == 3'628'800);
}

TEST_CASE("Type to string", "[lexer][typeToString]") {
  REQUIRE(typeToString(TOKEN_PLUS) == "TOKEN_PLUS");
  REQUIRE(typeToString(TOKEN_MINUS) == "TOKEN_MINUS");
  REQUIRE(typeToString(TOKEN_LT) == "TOKEN_LT");
  REQUIRE(typeToString(TOKEN_GT) == "TOKEN_GT");
  REQUIRE(typeToString(TOKEN_LB) == "TOKEN_LB");
  REQUIRE(typeToString(TOKEN_RB) == "TOKEN_RB");
  REQUIRE(typeToString(TOKEN_DOT) == "TOKEN_DOT");
  REQUIRE(typeToString(TOKEN_COMMA) == "TOKEN_COMMA");
}

TEST_CASE("Lexer tokenize basic bf program", "[lexer][tokenize]") {

  Lexer lex = Lexer(">>++--<<[].,");
  std::vector<Token *> tokens = lex.tokenize();

  std::vector<Token *> expected_tokens = {
      new Token{TOKEN_GT, ">"},    new Token{TOKEN_GT, ">"},
      new Token{TOKEN_PLUS, "+"},  new Token{TOKEN_PLUS, "+"},
      new Token{TOKEN_MINUS, "-"}, new Token{TOKEN_MINUS, "-"},
      new Token{TOKEN_LT, "<"},    new Token{TOKEN_LT, "<"},
      new Token{TOKEN_LB, "["},    new Token{TOKEN_RB, "]"},
      new Token{TOKEN_DOT, "."},   new Token{TOKEN_COMMA, ","},
  };

  REQUIRE(std::equal(tokens.begin(), tokens.end(), expected_tokens.begin(),
                     expected_tokens.end(),
                     [](const Token *tok, const Token *ex_tok) {
                       return tok->TYPE == ex_tok->TYPE;
                     }));
}
