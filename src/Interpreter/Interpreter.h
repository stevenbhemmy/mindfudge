#ifndef __INTERPRETER_H
#define __INTERPRETER_H

#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

#include <fmt/base.h>

#include <Lexer.h>

#define CODESIZE 65536
#define ARRAYSIZE 65536

struct stateDump {
  unsigned char tape[ARRAYSIZE];
  unsigned long stack[CODESIZE];
  unsigned char inchar;
  int code_length;
  int codep;
  int tapep;
  int stackp;
};

class Interpreter {
public:
  Interpreter(std::vector<Token *> instrs) {
    /* fmt::println("Setting up interpreter"); */
    instructions = instrs;
    code_length = instructions.size();
    codep = 0;
    tapep = 0;
    stackp = CODESIZE;
  }

  void interpret() {

    /* fmt::println("Mapping loop targets"); */
    for (codep = 0; codep < code_length; codep++) {
      auto instr = instructions.at(codep);
      switch (instr->TYPE) {
      case TOKEN_LB:
        /* fmt::println("Map start loop"); */
        stack[--stackp] = codep;
        break;
      case TOKEN_RB:
        /* fmt::println("Map end loop"); */
        if (stackp < CODESIZE) {
          stack[stack[codep] = stack[stackp++]] = codep;
        }
        break;
      default:
        /* Skip all other tokens */
        break;
      }
    }

    /* fmt::println("Running interpreter"); */
    for (tapep = 0, codep = 0; codep < code_length; codep++) {
      auto instr = instructions.at(codep);
      dispatchTable[instr->TYPE]();
    }
  }

  stateDump dumpState() {
    stateDump dump = {0};

    std::copy(std::begin(this->tape), std::end(this->tape),
              std::begin(dump.tape));
    std::copy(std::begin(this->stack), std::end(this->stack),
              std::begin(dump.stack));
    dump.inchar = this->inchar;
    dump.code_length = this->code_length;
    dump.codep = this->codep;
    dump.tapep = this->tapep;
    dump.stackp = this->stackp;

    return dump;
  }

private:
  unsigned char tape[ARRAYSIZE] = {0};
  unsigned long stack[CODESIZE] = {0};
  unsigned char inchar;
  int code_length;
  int codep;
  int tapep;
  int stackp;

  std::vector<Token *> instructions;

  std::map<enum type, std::function<void()>> dispatchTable{
      {TOKEN_PLUS,
       [this]() {
         tape[tapep] += 1;
         /* fmt::println("Incr tape[tapep]"); */
       }},
      {TOKEN_MINUS,
       [this]() {
         tape[tapep] -= 1;
         /* fmt::println("Decr tape[tapep]"); */
       }},
      {TOKEN_LT,
       [this]() {
         tapep -= 1;
         /* fmt::println("Decr tapep"); */
       }},
      {TOKEN_GT,
       [this]() {
         tapep += 1;
         /* fmt::println("Incr tapep"); */
       }},
      {TOKEN_LB,
       [this]() {
         /* fmt::println("Start loop"); */
         if (!tape[tapep]) {
           codep = stack[codep];
         }
       }},
      {TOKEN_RB,
       [this]() {
         /* fmt::println("End loop"); */
         if (tape[tapep]) {
           codep = stack[codep];
         }
       }},
      {TOKEN_DOT,
       [this]() {
         fmt::print("{:c}", tape[tapep]);
         /* fmt::println("Print tape[tapep]"); */
       }},
      {TOKEN_COMMA,
       [this]() {
         inchar = std::cin.get();
         tape[tapep] = inchar;
         /* fmt::println("Get tape[tapep]"); */
       }},
  };
};

#endif
