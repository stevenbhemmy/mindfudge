#include <fstream>
#include <sstream>
#include <vector>

#include <fmt/core.h>

#include <Interpreter.h>
#include <Lexer.h>

int main(int argc, char *argv[]) {

  if (argc < 2) {
    fmt::println("No source file specified, exiting.");
    exit(1);
  }

  fmt::println("argv[1] = {}", argv[1]);

  std::ifstream sourceFile(argv[1]);
  std::stringstream buffer;

  char temp;
  while (sourceFile.get(temp)) {
    buffer << temp;
  }

  fmt::print(buffer.str());

  auto lexer = Lexer(buffer.str());

  std::vector<Token *> tokens;
  tokens = lexer.tokenize();

  /* for (const auto& token : tokens) { */
  /*     fmt::println(typeToString(token->TYPE)); */
  /* } */

  auto interpreter = Interpreter(tokens);
  interpreter.interpret();

  return 0;
};
