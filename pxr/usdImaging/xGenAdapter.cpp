//
// Copyright © 2021 Weta Digital Limited
//
// SPDX-License-Identifier: Apache-2.0
//
#include "xGenAdapter.h"
#include "debugCodes.h"

#include <pxr/usd/usdGeom/xGen.h>

#include <pxr/imaging/hd/tokens.h>
#include <pxr/usd/usdGeom/tokens.h>
#include <pxr/usdImaging/usdImaging/indexProxy.h>
#include <pxr/usdImaging/usdImaging/tokens.h>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType)
{
    typedef UsdImagingXGenAdapter Adapter;
    TfType adapterType =
        TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    adapterType.SetFactory<UsdImagingPrimAdapterFactory<Adapter>>();
}

bool
UsdImagingXGenAdapter::IsSupported(
    const UsdImagingIndexProxy* index) const
{
    return index->IsRprimTypeSupported(HdPrimTypeTokens->mesh);
}

void
UsdImagingXGenAdapter::TrackVariability(
    const UsdPrim& usdPrim,
    const SdfPath& cachePath,
    HdDirtyBits* o_timeVaryingBits,
    const UsdImagingInstancerContext* i_instancerContext) const
{
    BaseAdapter::TrackVariability(
        usdPrim, cachePath, o_timeVaryingBits, i_instancerContext);

    // If frame varies over time then points need to be pulled on time
    // change.
    _IsVarying(usdPrim,
               UsdXGenTokens->frame,
               HdChangeTracker::DirtyPoints,
               UsdImagingTokens->usdVaryingPrimvar,
               o_timeVaryingBits,
               /*inherited*/ false);

    TF_DEBUG(USDXGENIMAGING)
        .Msg("[%s] <%s>, <%s>, dirtyBits: %s\n",
             TF_FUNC_NAME().c_str(),
             usdPrim.GetPath().GetText(),
             cachePath.GetText(),
             HdChangeTracker::StringifyDirtyBits(*o_timeVaryingBits).c_str());
}

SdfPath
UsdImagingXGenAdapter::Populate(
    const UsdPrim& usdPrim,
    UsdImagingIndexProxy* index,
    const UsdImagingInstancerContext* instancerContext)
{
    TF_DEBUG(USDXGENIMAGING)
        .Msg(
            "[%s] <%s>\n", TF_FUNC_NAME().c_str(), usdPrim.GetPath().GetText());

    return _AddRprim(HdPrimTypeTokens->mesh,
                     usdPrim,
                     index,
                     GetMaterialUsdPath(usdPrim),
                     instancerContext);
}

HdDirtyBits
UsdImagingXGenAdapter::ProcessPropertyChange(const UsdPrim& usdPrim,
                                                    const SdfPath& cachePath,
                                                    const TfToken& propertyName)
{

    TF_DEBUG(USDXGENIMAGING)
        .Msg("[%s] <%s>, <%s>, propertyName: %s\n",
             TF_FUNC_NAME().c_str(),
             usdPrim.GetPath().GetText(),
             cachePath.GetText(),
             propertyName.GetText());

    // If the frame attribute changes, then the points are dirty.
    if (propertyName == UsdXGenTokens->frame) {
        return HdChangeTracker::DirtyPoints;
    }

    // Allow base class to handle change processing.
    return BaseAdapter::ProcessPropertyChange(usdPrim, cachePath, propertyName);
}

VtValue
UsdImagingXGenAdapter::GetPoints(const UsdPrim& usdPrim,
                                        UsdTimeCode timeCode) const
{
    // UsdTriTriangle triangle(usdPrim);
    // TF_VERIFY(triangle);

    double sideLength = 1.0;
    // TF_VERIFY(triangle.GetSideLengthAttr().Get(&sideLength, timeCode));

    VtVec3fArray points{
        GfVec3f(0.0f, 0.57735027f * sideLength, 0.0f),
        GfVec3f(-0.5f * sideLength, -0.28867513f * sideLength, 0.0f),
        GfVec3f(0.5f * sideLength, -0.28867513f * sideLength, 0.0f)
    };
    return VtValue(points);
}

VtValue
UsdImagingXGenAdapter::GetTopology(const UsdPrim& usdPrim,
                                          const SdfPath& cachePath,
                                          UsdTimeCode time) const
{
    // A single triangle.
    VtIntArray faceVertexCounts(1, 3);
    VtIntArray faceVertexIndices{ 0, 1, 2 };
    static HdMeshTopology planeTopology(UsdGeomTokens->catmullClark,
                                        HdTokens->rightHanded,
                                        faceVertexCounts,
                                        faceVertexIndices);
    return VtValue(planeTopology);
}

PXR_NAMESPACE_CLOSE_SCOPE
