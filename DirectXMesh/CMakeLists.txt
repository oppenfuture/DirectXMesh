# DirectXMesh geometry Library
#
# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.
#
# http://go.microsoft.com/fwlink/?LinkID=324981

cmake_minimum_required (VERSION 3.8)
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project (DirectXMesh_CMake LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/CMake")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/CMake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/CMake")

add_library (directxmesh STATIC
    DirectXMesh.h
    DirectXMeshP.h
    scoped.h
    DirectXMeshAdjacency.cpp
    DirectXMeshClean.cpp
    DirectXMeshGSAdjacency.cpp
    DirectXMeshNormals.cpp
    DirectXMeshOptimize.cpp
    #DirectXMeshOptimizeLRU.cpp
    #DirectXMeshOptimizeTVC.cpp
    DirectXMeshRemap.cpp
    DirectXMeshTangentFrame.cpp
    DirectXMeshUtil.cpp
    DirectXMeshValidate.cpp
    DirectXMeshVBReader.cpp
    DirectXMeshVBWriter.cpp
    DirectXMeshWeldVertices.cpp
)

#target_compile_options( directxmesh PRIVATE /fp:fast )

if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang" )
    target_compile_options( directxmesh PRIVATE -Wall -w -fdeclspec -Wpedantic -Wextra )
    if (${CMAKE_SIZEOF_VOID_P} EQUAL "4")
        target_compile_options( directxmesh PRIVATE /arch:SSE2 )
    endif()
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
    target_compile_options( directxmesh PRIVATE /Wall /permissive- /Zc:__cplusplus )
endif()

install(TARGETS directxmesh ARCHIVE DESTINATION /usr/local/lib)
install(FILES DirectXMesh.h DirectXMesh.inl DESTINATION /usr/local/include)

# Windows 10 is used here to build the DirectX 12 code paths as well as 11
#add_compile_definitions(_UNICODE UNICODE _WIN32_WINNT=0x0A00)
