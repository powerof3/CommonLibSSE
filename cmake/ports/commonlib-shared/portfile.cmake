vcpkg_check_linkage(ONLY_STATIC_LIBRARY)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO libxse/commonlib-shared
    REF 55f86cbd5a88ccb21076a63726eaf75408cdebf7
    SHA512 59f97d0b91447e4f230f347f50bfe2b4854ad0bd472ccdfbca7e65019ff9b99c352ffbcea2d95de6170f588d165d53ffb14e8b11ae31a44e4c7d498300bfe17f
    HEAD_REF support/cmake
)

vcpkg_check_features(OUT_FEATURE_OPTIONS FEATURE_OPTIONS
    FEATURES
        ini   COMMONLIB_INI
        json  COMMONLIB_JSON
        toml  COMMONLIB_TOML
        xbyak COMMONLIB_XBYAK
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS ${FEATURE_OPTIONS}
)

vcpkg_cmake_install()

vcpkg_cmake_config_fixup(
    PACKAGE_NAME commonlib-shared
    CONFIG_PATH lib/cmake/commonlib-shared
)

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")

vcpkg_install_copyright(
    FILE_LIST
        "${SOURCE_PATH}/LICENSE"
        "${SOURCE_PATH}/EXCEPTIONS"
)
