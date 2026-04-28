#ifndef __INTERPRETER_H
#define __INTERPRETER_H

#include <functional>
#include <istream>
#include <map>
#include <vector>

#include <fmt/core.h>

#include <Lexer.h>

class Interpreter {
public:
  Interpreter(std::vector<Token *> instrs) {
    fmt::println("Setting up interpreter");
    instructions = instrs;
    pointer = 0;
  }

  void interpret() {
    fmt::println("Running interpreter");
    for (auto instr : instructions) {
      dispatchTable[instr->TYPE]();
    }
  }

private:
  unsigned char tape[30000] = {0};
  int pointer;

  std::vector<Token *> instructions;

  std::map<enum type, std::function<void()>> dispatchTable{
      {TOKEN_PLUS,
       [this]() {
         tape[pointer] += 1;
         fmt::println("Incr tape[pointer]");
       }},
      {TOKEN_MINUS,
       [this]() {
         tape[pointer] -= 1;
         fmt::println("Decr tape[pointer]");
       }},
      {TOKEN_LT,
       [this]() {
         pointer -= 1;
         fmt::println("Decr pointer");
       }},
      {TOKEN_GT,
       [this]() {
         pointer += 1;
         fmt::println("Incr pointer");
       }},
      {TOKEN_LB,
       [this]() {
         fmt::println("Start loop"); /* TODO */
       }},
      {TOKEN_RB,
       [this]() {
         fmt::println("End loop"); /* TODO */
       }},
      {TOKEN_DOT,
       [this]() { /* fmt::print(tape[pointer]); */
                  fmt::println("Print tape[pointer]");
       }},
      {TOKEN_COMMA,
       [this]() { /* cin.get(tape[pointer]); */
                  fmt::println("Get tape[pointer]");
       }},
  };
};

#endif
