usd_library(xGen

    PUBLIC_HEADERS_INSTALL_PREFIX
        ${ORGANIZATION}

    PYTHON_INSTALL_PREFIX
        ${ORGANIZATION}

    LIBRARIES
        js
        plug
        tf
        sdf
        vt
        gf
        usd
        usdGeom
        arch

    PUBLIC_CLASSES
        xGen

    PUBLIC_HEADERS
        api.h
        tokens.h

    CPPFILES
        tokens.cpp

    PYMODULE_CPPFILES
        wrapTokens.cpp
        wrapXGen.cpp

    PYTHON_FILES
        __init__.py

    RESOURCE_FILES
        generatedSchema.usda
        plugInfo.json
)