# CMakeList.txt: проект CMake для lab2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (lab2 "lab2.cpp"  "funcs.cpp" "funcs.h" "wagon.cpp" "wagon.h" "train.cpp" "train.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lab2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
