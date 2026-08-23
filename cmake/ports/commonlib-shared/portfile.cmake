vcpkg_check_linkage(ONLY_STATIC_LIBRARY)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO libxse/commonlib-shared
    REF bbd60153e4b5ecb4b7949513a1af4df43dc6e267
    SHA512 cb490e70843297f4a4840c1f556e17eecb3171d106e508e2b48164b7bebf0fcb5b05d6f91c6441c9efa409d185da65833bb5ba10d42ef407bb845f6a647aab98
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
