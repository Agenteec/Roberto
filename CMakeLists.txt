# CMakeList.txt: проект CMake для Roberto; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


project ("Roberto")

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

find_package(box2d CONFIG REQUIRED)
# Добавление путей к заголовочным файлам SFML
include_directories(${SFML_INCLUDE_DIR})
include_directories(${Box2D_INCLUDE_DIR})

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Roberto "Roberto.cpp" "include/Roberto.h" "include/Window.h" "include/Gui.h" "Gui.cpp")
target_include_directories(Roberto PRIVATE "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(Roberto PRIVATE sfml-system sfml-network sfml-graphics sfml-window box2d::box2d)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Roberto PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
