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

# Укажите путь к установленным файлам vcpkg
if(WIN32)
    execute_process(COMMAND cmd /c echo %USERPROFILE% OUTPUT_VARIABLE USER_PROFILE)
    string(STRIP "${USER_PROFILE}" USER_PROFILE)
else()
    message(FATAL_ERROR "This script is designed for Windows only.")
endif()
set(VCPKG_PATH "${USER_PROFILE}/vcpkg")

# Укажите путь к пакету Thor в vcpkg
set(THOR_INCLUDE_DIR "${VCPKG_PATH}/installed/${VCPKG_TARGET_TRIPLET}/include")
set(THOR_LIBRARY_DIR "${VCPKG_PATH}/installed/${VCPKG_TARGET_TRIPLET}/lib")
# Добавьте пути к заголовочным файлам Thor
include_directories(${THOR_INCLUDE_DIR})
project ("Roberto")

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

find_package(box2d CONFIG REQUIRED)

find_package(nlohmann_json CONFIG REQUIRED)

find_package(TGUI CONFIG REQUIRED)

find_package(OpenSSL REQUIRED)
# Добавление путей к заголовочным файлам SFML
include_directories(${SFML_INCLUDE_DIR})
include_directories(${Box2D_INCLUDE_DIR})
file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.h")
# Добавьте источник в исполняемый файл этого проекта.
add_executable (Roberto ${SOURCES})
#"Roberto.cpp" "include/Roberto.h" "include/Window.h" "Window.cpp" "include/Gui.h" "Gui.cpp" "include/Settings.h" "Settings.cpp" "include/FeatureTester.h" "FeatureTester.cpp" "FeatureTesterM.cpp"
target_include_directories(Roberto PRIVATE "${PROJECT_SOURCE_DIR}/include")
set(TGUI_STATIC_LIBRARIES TRUE)
target_link_libraries(Roberto PRIVATE sfml-system sfml-network sfml-graphics sfml-window box2d::box2d nlohmann_json::nlohmann_json tgui ${OPENSSL_LIBRARIES} ${THOR_LIBRARY_DIR}/thor.lib)

# Укажите директорию с файлами для копирования
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/Resources)

# Укажите директорию, в которую нужно скопировать файлы
set(DESTINATION_DIR ${CMAKE_BINARY_DIR})

# Копируйте файлы
file(COPY ${SOURCE_DIR} DESTINATION ${DESTINATION_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Roberto PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
