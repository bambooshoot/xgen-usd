# A top-level name used as the root directory for public headers
# installation, and the root python module.
set(ORGANIZATION "xGen")

# Build & install libraries.
add_subdirectory(usd/usdGeom)
# add_subdirectory(imaging)
# add_subdirectory(usdImaging)

# Install top-level plugInfo for including per-plugin plugInfo(s).
install(
    FILES plugInfo.json
    DESTINATION ${CMAKE_INSTALL_DIR}/${USD_PLUG_INFO_ROOT_DIR}
)

# Install top level python __init__.py
install(
    FILES __init__.py
    DESTINATION ${CMAKE_INSTALL_DIR}/${USD_PYTHON_DIR}/${ORGANIZATION}
)