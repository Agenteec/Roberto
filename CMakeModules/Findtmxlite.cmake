set(VCPKG_PATH "${USER_PROFILE}/vcpkg")
set(VCPKG_INCLUDE_DIR "${VCPKG_PATH}/installed/${VCPKG_TARGET_TRIPLET}/include")
set(VCPKG_LIBRARY_DIR "${VCPKG_PATH}/installed/${VCPKG_TARGET_TRIPLET}/lib")
set(VCPKG_BINARY_DIR "${VCPKG_PATH}/installed/${VCPKG_TARGET_TRIPLET}/lib")

# Настройка поиска tmxlite

# Найдите путь к заголовочным файлам tmxlite
find_path(tmxlite_INCLUDE_DIR NAMES tmxlite/Map.hpp PATHS VCPKG_INCLUDE_DIR)

# Найдите библиотеку tmxlite
find_library(tmxlite_LIBRARY NAMES tmxlite PATHS VCPKG_LIBRARY_DIR)

# Создайте импортированный целевой объект для tmxlite
add_library(tmxlite INTERFACE)

# Укажите путь к заголовочным файлам tmxlite
target_include_directories(tmxlite INTERFACE ${tmxlite_INCLUDE_DIR})

# Подключите библиотеку tmxlite к целевому объекту
target_link_libraries(tmxlite INTERFACE ${tmxlite_LIBRARY})