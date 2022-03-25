usd_plugin(usdTriImaging

    CPPFILES
        xgenAdapter.cpp
        debugCodes.cpp

    LIBRARIES
        arch
        js
        plug
        usd
        tf
        sdf
        vt
        gf
        hd
        usdGeom
        usdImaging
        xGen

    RESOURCE_FILES
        plugInfo.json
)

