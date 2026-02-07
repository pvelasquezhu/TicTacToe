
# Add source to this project's executable.
add_executable(TicTacToe
	main.cpp
)

# Define language standard
set_property(TARGET TicTacToe PROPERTY CXX_STANDARD 20)

# Add library dependencies
target_link_libraries(TicTacToe PRIVATE TicTacLib)
