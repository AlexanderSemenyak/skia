/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkTypes.h"
#ifdef SK_BUILD_FOR_IOS

#include "include/gpu/gl/GrGLAssembleInterface.h"
#include "include/gpu/gl/GrGLInterface.h"

#include <dlfcn.h>

sk_sp<const GrGLInterface> GrGLMakeNativeInterface() {
    auto getProc = [](void* ctx, const char* name) {
        return (GrGLFuncPtr)dlsym(RTLD_DEFAULT, name);
    };

    return GrGLMakeAssembledGLESInterface(nullptr, getProc);
}

const GrGLInterface* GrGLCreateNativeInterface() { return GrGLMakeNativeInterface().release(); }

#endif  // SK_BUILD_FOR_IOS
