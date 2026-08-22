vcpkg_check_linkage(ONLY_STATIC_LIBRARY)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO libxse/commonlib-shared
    REF 64bdd33c243f8deb7eb45d2fbcb52a80787c69e6
    SHA512 62968e323b78c6a0719a2daef8e3c8ce1e4d381fd0f12c86a9b20ecabe25bbe7cd520aa701a03861f4c8e274e2664e3a428ef1a338b1bbc1d48c5cf7bf805f0f
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
