vcpkg_check_linkage(ONLY_STATIC_LIBRARY)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO libxse/commonlib-shared
    REF def5f6c93db28d20307d8e55a62118fc1c4f0b6c
    SHA512 79e7fed14f077daa1903a5aa45763e8babc66c81fa32e37836adedc9c7e098779bfcfd787dfdb8a7183fc3b1bb75995786270b954b4b356ceb623c947e2e372d
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
