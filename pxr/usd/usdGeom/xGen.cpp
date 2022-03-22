//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#include "./xGen.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdXGen,
        TfType::Bases< UsdGeomGprim > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("XGen")
    // to find TfType<UsdXGen>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, UsdXGen>("XGen");
}

/* virtual */
UsdXGen::~UsdXGen()
{
}

/* static */
UsdXGen
UsdXGen::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdXGen();
    }
    return UsdXGen(stage->GetPrimAtPath(path));
}

/* static */
UsdXGen
UsdXGen::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("XGen");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdXGen();
    }
    return UsdXGen(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaType UsdXGen::_GetSchemaType() const {
    return UsdXGen::schemaType;
}

/* static */
const TfType &
UsdXGen::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdXGen>();
    return tfType;
}

/* static */
bool 
UsdXGen::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdXGen::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdXGen::GetFileAttr() const
{
    return GetPrim().GetAttribute(UsdTokens->file);
}

UsdAttribute
UsdXGen::CreateFileAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdTokens->file,
                       SdfValueTypeNames->Asset,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdXGen::GetPaletteAttr() const
{
    return GetPrim().GetAttribute(UsdTokens->palette);
}

UsdAttribute
UsdXGen::CreatePaletteAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdTokens->palette,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdXGen::GetDescriptionAttr() const
{
    return GetPrim().GetAttribute(UsdTokens->description);
}

UsdAttribute
UsdXGen::CreateDescriptionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdTokens->description,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdXGen::GetGeomAttr() const
{
    return GetPrim().GetAttribute(UsdTokens->geom);
}

UsdAttribute
UsdXGen::CreateGeomAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdTokens->geom,
                       SdfValueTypeNames->Asset,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdXGen::GetPatchAttr() const
{
    return GetPrim().GetAttribute(UsdTokens->patch);
}

UsdAttribute
UsdXGen::CreatePatchAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdTokens->patch,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdXGen::GetFrameAttr() const
{
    return GetPrim().GetAttribute(UsdTokens->frame);
}

UsdAttribute
UsdXGen::CreateFrameAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdTokens->frame,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdXGen::GetFpsAttr() const
{
    return GetPrim().GetAttribute(UsdTokens->fps);
}

UsdAttribute
UsdXGen::CreateFpsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdTokens->fps,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdXGen::GetWorldAttr() const
{
    return GetPrim().GetAttribute(UsdTokens->world);
}

UsdAttribute
UsdXGen::CreateWorldAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdTokens->world,
                       SdfValueTypeNames->Matrix4d,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdXGen::GetExtentAttr() const
{
    return GetPrim().GetAttribute(UsdTokens->extent);
}

UsdAttribute
UsdXGen::CreateExtentAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdTokens->extent,
                       SdfValueTypeNames->Float3Array,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

namespace {
static inline TfTokenVector
_ConcatenateAttributeNames(const TfTokenVector& left,const TfTokenVector& right)
{
    TfTokenVector result;
    result.reserve(left.size() + right.size());
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}
}

/*static*/
const TfTokenVector&
UsdXGen::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdTokens->file,
        UsdTokens->palette,
        UsdTokens->description,
        UsdTokens->geom,
        UsdTokens->patch,
        UsdTokens->frame,
        UsdTokens->fps,
        UsdTokens->world,
        UsdTokens->extent,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdGeomGprim::GetSchemaAttributeNames(true),
            localNames);

    if (includeInherited)
        return allNames;
    else
        return localNames;
}

PXR_NAMESPACE_CLOSE_SCOPE

// ===================================================================== //
// Feel free to add custom code below this line. It will be preserved by
// the code generator.
//
// Just remember to wrap code in the appropriate delimiters:
// 'PXR_NAMESPACE_OPEN_SCOPE', 'PXR_NAMESPACE_CLOSE_SCOPE'.
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--
