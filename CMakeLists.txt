cmake_minimum_required(VERSION 3.2)

project(grasp_mvc VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER}) 

set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")

set(TEST_PATH "${PROJECT_TEST_DIR}/test")

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(n_matrix 
					${SOURCE_PATH}/main.cpp
					)

add_compile_options(-std=c++11)

set_target_properties(grasp_mvc PROPERTIES
		CXX_STANDARD 14
		CXX_STANDARD_REQUIRED ON
		COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

install(TARGETS grasp_mvc RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT abdulvadudovmagomed@mail.ru)

include(CPack)

#enable_testing()

#add_subdirectory(test)