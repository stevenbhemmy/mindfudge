add_executable(mindfudge_tests)
target_sources(mindfudge_tests
  PRIVATE
    mindfudge_tests.cpp
)
target_link_libraries(mindfudge_tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(mindfudge_tests PRIVATE fmt::fmt)
target_link_libraries(mindfudge_tests PRIVATE Lexer)
target_link_libraries(mindfudge_tests PRIVATE Interpreter)
