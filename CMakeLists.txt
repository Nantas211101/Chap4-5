cmake_minimum_required(VERSION 3.21)
project(Game LANGUAGES CXX)


include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)



add_executable(Game ./src/Game.cpp ./src/main.cpp)
target_include_directories(Game PRIVATE ./include)
target_link_libraries(Game PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_features(Game PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Game POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Game> $<TARGET_FILE_DIR:Game> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Game)