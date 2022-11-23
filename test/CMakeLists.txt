set(NAME test)
add_executable(${NAME}
	main.cpp
	test_monovec.cpp
)

target_link_libraries(${NAME} PUBLIC ft)

# Catch2
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

target_link_libraries(${NAME} PRIVATE Catch2::Catch2WithMain)
