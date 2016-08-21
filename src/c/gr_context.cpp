/*
 * Copyright 2016 Xamarin Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrContext.h"
#include "gl/GrGLInterface.h"
#include "gl/GrGLAssembleInterface.h"

#include "gr_context.h"

#include "sk_types_priv.h"

gr_context_t* gr_context_create(gr_backend_t backend, gr_backendcontext_t backendContext, const gr_context_options_t* options) {
    return ToGrContext(GrContext::Create((GrBackend)backend, backendContext, AsGrContextOptions(*options)));
}

gr_context_t* gr_context_create_with_defaults(gr_backend_t backend, gr_backendcontext_t backendContext) {
    return ToGrContext(GrContext::Create((GrBackend)backend, backendContext));
}

void gr_context_unref(gr_context_t* context) {
    AsGrContext(context)->unref();
}

void gr_context_abandon_context(gr_context_t* context) {
    AsGrContext(context)->abandonContext();
}

void gr_context_release_resources_and_abandon_context(gr_context_t* context) {
    AsGrContext(context)->releaseResourcesAndAbandonContext();
}

void gr_context_get_resource_cache_limits(gr_context_t* context, int* maxResources, size_t* maxResourceBytes) {
    AsGrContext(context)->getResourceCacheLimits(maxResources, maxResourceBytes);
}

void gr_context_set_resource_cache_limits(gr_context_t* context, int maxResources, size_t maxResourceBytes) {
    AsGrContext(context)->setResourceCacheLimits(maxResources, maxResourceBytes);
}

void gr_context_get_resource_cache_usage(gr_context_t* context, int* maxResources, size_t* maxResourceBytes) {
    AsGrContext(context)->getResourceCacheUsage(maxResources, maxResourceBytes);
}

int gr_context_get_recommended_sample_count(gr_context_t* context, gr_pixelconfig_t config, float dpi) {
    return AsGrContext(context)->getRecommendedSampleCount((GrPixelConfig)config, dpi);
}


const gr_glinterface_t* gr_glinterface_default_interface() {
    return ToGrGLInterface(GrGLDefaultInterface());
}

const gr_glinterface_t* gr_glinterface_create_native_interface() {
    return ToGrGLInterface(GrGLCreateNativeInterface());
}

const gr_glinterface_t* gr_glinterface_assemble_interface(void* ctx, gr_gl_get_proc get) {
    return ToGrGLInterface(GrGLAssembleInterface(ctx, get));
}

const gr_glinterface_t* gr_glinterface_assemble_gl_interface(void* ctx, gr_gl_get_proc get) {
    return ToGrGLInterface(GrGLAssembleGLInterface(ctx, get));
}

const gr_glinterface_t* gr_glinterface_assemble_gles_interface(void* ctx, gr_gl_get_proc get) {
    return ToGrGLInterface(GrGLAssembleGLESInterface(ctx, get));
}

void gr_glinterface_unref(gr_glinterface_t* glInterface) {
    AsGrGLInterface(glInterface)->unref();
}

gr_glinterface_t* gr_glinterface_clone(gr_glinterface_t* glInterface) {
    return ToGrGLInterface(GrGLInterface::NewClone(AsGrGLInterface(glInterface)));
}

bool gr_glinterface_validate(gr_glinterface_t* glInterface) {
    return AsGrGLInterface(glInterface)->validate();
}

bool gr_glinterface_has_extension(gr_glinterface_t* glInterface, const char* extension) {
    return AsGrGLInterface(glInterface)->hasExtension(extension);
}
