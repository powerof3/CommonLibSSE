vcpkg_check_linkage(ONLY_STATIC_LIBRARY)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO libxse/commonlib-shared
    REF 0e0796f81e61e4ef4c5110f9b64ca058eb0eb459
    SHA512 e18c5f2d0755f47a11c903a5c0aeff4b31510fa3bbeb752bbd64ba708b235d8d1e12b3d92c8cc3adce487d792a0ce362d935685240c1386d61826ccd66f330f3
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
