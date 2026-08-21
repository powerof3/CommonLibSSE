vcpkg_check_linkage(ONLY_STATIC_LIBRARY)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO powerof3/commonlib-shared
    REF 6b564e791d74498299981f0822fb283a927ff936
    SHA512 357cb60fef80fb5f6403ef694fd9bc8eff689ea02747e2d4ec300fd2fc7ded7db01af5727b4655427be16d7166c852f9fcb847128052807f641569f3426e0c9c
    HEAD_REF cmake-tests
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
