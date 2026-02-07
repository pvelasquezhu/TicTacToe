
# Add source to this project's executable.
add_library(TicTacLib
	src/board.cpp
	src/console.cpp
 )

# Define language standard
set_property(TARGET TicTacLib PROPERTY CXX_STANDARD 20)

# Define include directories
target_include_directories(TicTacLib PUBLIC "${PROJECT_SOURCE_DIR}/TicTacLib/include")

