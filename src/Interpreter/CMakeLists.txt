add_library(Interpreter)

set_target_properties(Interpreter
    PROPERTIES
        LINKER_LANGUAGE CXX
)

target_sources(Interpreter
    PUBLIC
        FILE_SET interpreterFiles 
        TYPE HEADERS
        FILES
            Interpreter.h
)
