# A top-level name used as the root directory for public headers
# installation, and the root python module.
set(ORGANIZATION "xGen")

# Build & install libraries.
add_subdirectory(usd/usdGeom)
# add_subdirectory(imaging)
# add_subdirectory(usdImaging)

# Install top-level plugInfo for including per-library plugInfo(s).
install(
    FILES plugInfo.json
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/${USD_PLUG_INFO_ROOT_DIR}
)

# Install top-level plugInfo for including per-plugin plugInfo(s).
install(
    FILES plugInfo.json
    DESTINATION ${USD_PLUGIN_DIR}/${USD_PLUG_INFO_ROOT_DIR}
)