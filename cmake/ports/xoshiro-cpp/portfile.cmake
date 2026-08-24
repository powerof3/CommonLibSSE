# header-only library
set(VCPKG_BUILD_TYPE release)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO Reputeless/Xoshiro-cpp
    REF 19bcbb2ce0ed158233187f524fd0964c105a65b3
    SHA512 b708505e3b4e84bdd87fa6d9bde91c95e09eef4b444d5593de331f4ea76d01021a0ca206ebcdfaa3aceaf0dfa161175d8e19b02e62f21ff8e765e2147563a3de
    HEAD_REF master
)

file(INSTALL "${SOURCE_PATH}/XoshiroCpp.hpp"
     DESTINATION "${CURRENT_PACKAGES_DIR}/include")

file(INSTALL "${CMAKE_CURRENT_LIST_DIR}/xoshiro-cpp-config.cmake"
     DESTINATION "${CURRENT_PACKAGES_DIR}/share/xoshiro-cpp")

vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE")
