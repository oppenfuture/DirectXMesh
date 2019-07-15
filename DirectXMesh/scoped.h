//-------------------------------------------------------------------------------------
// scoped.h
//  
// Utility header with helper classes for exception-safe handling of resources
//
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//-------------------------------------------------------------------------------------

#pragma once

#include <assert.h>
#include <memory>
#include <malloc.h>

//---------------------------------------------------------------------------------
struct aligned_deleter { void operator()(void* p) { _aligned_free(p); } };

typedef std::unique_ptr<float[], aligned_deleter> ScopedAlignedArrayFloat;

typedef std::unique_ptr<DirectX::XMVECTOR[], aligned_deleter> ScopedAlignedArrayXMVECTOR;
