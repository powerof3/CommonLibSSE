vcpkg_check_linkage(ONLY_STATIC_LIBRARY)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO libxse/commonlib-shared
    REF b8f30fb8ad69ca05fe7c7e5965cb4ca327befea0
    SHA512 6e1d487497b8c386982c9907c4613129c182c8e2beb13c2a570fc76e0996e837a9ef8dd050a0621b0859e72dcb1d61dff0d46250c6416d6cad25c72134ea8dae
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
