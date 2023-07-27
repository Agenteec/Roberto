# CMakeList.txt:
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
set(VCPKG_INCLUDE_DIR "${VCPKG_PATH}/installed/${VCPKG_TARGET_TRIPLET}/include")
set(VCPKG_LIBRARY_DIR "${VCPKG_PATH}/installed/${VCPKG_TARGET_TRIPLET}/lib")
set(VCPKG_BINARY_DIR "${VCPKG_PATH}/installed/${VCPKG_TARGET_TRIPLET}/bin")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules")
include_directories(${VCPKG_INCLUDE_DIR})


include_directories(${CMAKE_SOURCE_DIR}/modules/tmxlite/include)
link_directories(${CMAKE_SOURCE_DIR}/modules/tmxlite/lib)

# Попробуйте использовать прямые слеши в пути к папке vcpkg
project ("Roberto")

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

find_package(box2d CONFIG REQUIRED)

find_package(nlohmann_json CONFIG REQUIRED)

find_package(TGUI CONFIG REQUIRED)

find_package(OpenSSL REQUIRED)

#Настройка конфигурации tmxlite
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(TMXLITE_LIB ${TMXLITE_LIB} "libtmxlite-s-d")
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
  set(TMXLITE_LIB ${TMXLITE_LIB} "libtmxlite-s")
endif()

# Добавление путей к заголовочным файлам SFML
include_directories(${SFML_INCLUDE_DIR})
include_directories(${Box2D_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.h")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Roberto ${SOURCES})
add_executable (tester "tester/main.cpp" "include/SFMLOrthogonalLayer.hpp")
add_executable (sfmlTest "sfmlTest/main.cpp")

target_link_libraries(tester PRIVATE sfml-system sfml-network sfml-graphics sfml-window box2d::box2d nlohmann_json::nlohmann_json tgui ${OPENSSL_LIBRARIES} ${VCPKG_LIBRARY_DIR}/thor.lib ${TMXLITE_LIB})
target_link_libraries(sfmlTest PRIVATE sfml-system sfml-network sfml-graphics sfml-window box2d::box2d nlohmann_json::nlohmann_json tgui ${OPENSSL_LIBRARIES})
target_link_libraries(Roberto PRIVATE sfml-system sfml-network sfml-graphics sfml-window box2d::box2d nlohmann_json::nlohmann_json tgui ${OPENSSL_LIBRARIES} ${VCPKG_LIBRARY_DIR}/thor.lib ${TMXLITE_LIB})

#"Roberto.cpp" "include/Roberto.h" "include/Window.h" "Window.cpp" "include/Gui.h" "Gui.cpp" "include/Settings.h" "Settings.cpp" "include/FeatureTester.h" "FeatureTester.cpp" "FeatureTesterM.cpp"
#target_include_directories(Roberto PRIVATE "${PROJECT_SOURCE_DIR}/include")

# Укажите директорию с файлами для копирования
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/Resources)

# Укажите директорию, в которую нужно скопировать файлы
set(DESTINATION_DIR ${CMAKE_BINARY_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Roberto PROPERTY CXX_STANDARD 20)
endif()