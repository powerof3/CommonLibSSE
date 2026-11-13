vcpkg_check_linkage(ONLY_STATIC_LIBRARY)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO libxse/commonlib-shared
    REF 79bccb6430237eac766c7e45c9c7a0523bdf92e4
    SHA512 abf4c71d097902daefa79398dd5abab0481ceaa915ec9fb34a7d91f01ee388d3ca063f534083d584873d398b1e9b8ea39150bcc73c9cc770ad401c9d2f05d1f6
    HEAD_REF main
)

vcpkg_check_features(OUT_FEATURE_OPTIONS FEATURE_OPTIONS
    FEATURES
        ini    COMMONLIB_INI
        json   COMMONLIB_JSON
		random COMMONLIB_RANDOM
        toml   COMMONLIB_TOML
        xbyak  COMMONLIB_XBYAK

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
