add_library(Lexer)

set_target_properties(Lexer
    PROPERTIES
        LINKER_LANGUAGE CXX
)

target_sources(Lexer
    PUBLIC
        FILE_SET lexerFiles
        TYPE HEADERS
        FILES
            Lexer.h
)
