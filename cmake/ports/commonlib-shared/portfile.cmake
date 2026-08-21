vcpkg_check_linkage(ONLY_STATIC_LIBRARY)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO libxse/commonlib-shared
    REF efa73736b8c89a3b9297f20d2b86415353357a7b
    SHA512 4ff8e260db3f14c11b2e77aa24f94797ba462b11b8ca30c7c27bf5a8fb52f635c42839d2e23a11b4afdf419070e8a2f5b3a274aa07a937f79d8d8f43dccce7d7
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
