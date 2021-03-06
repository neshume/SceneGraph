#include "Buffer.h"

namespace kitsune::scenegraph::sdl::graphics {

GLenum convertBufferTarget(BufferTarget target) {
    switch (target) {
        case BufferTarget::Vertex:
            return GL_ARRAY_BUFFER;
        case BufferTarget::Index:
            return GL_ELEMENT_ARRAY_BUFFER;
        case BufferTarget::Uniform:
            return GL_UNIFORM_BUFFER;
        case BufferTarget::Command:
            return GL_DRAW_INDIRECT_BUFFER;
        case BufferTarget::IndirectDispatch:
            return GL_DISPATCH_INDIRECT_BUFFER;
        case BufferTarget::PixelPack:
            return GL_PIXEL_PACK_BUFFER;
        case BufferTarget::PixelUnpack:
            return GL_PIXEL_UNPACK_BUFFER;
        case BufferTarget::Query:
            return GL_QUERY_BUFFER;
        case BufferTarget::ShaderStorage:
            return GL_SHADER_STORAGE_BUFFER;
        case BufferTarget::Texture:
            return GL_TEXTURE_BUFFER;
        case BufferTarget::TransformFeedback:
            return GL_TRANSFORM_FEEDBACK_BUFFER;
    }
}

GLenum convertBufferFrequencyAndAccess(BufferFrequency frequency, BufferAccess access) {
    switch (frequency) {
        case BufferFrequency::Stream:
            switch (access) {
                case BufferAccess::Draw:
                    return GL_STREAM_DRAW;
                case BufferAccess::Read:
                    return GL_STREAM_READ;
                case BufferAccess::Copy:
                    return GL_STREAM_COPY;
            }
        case BufferFrequency::Static:
            switch (access) {
                case BufferAccess::Draw:
                    return GL_STATIC_DRAW;
                case BufferAccess::Read:
                    return GL_STATIC_READ;
                case BufferAccess::Copy:
                    return GL_STATIC_COPY;
            }
        case BufferFrequency::Dynamic:
            switch (access) {
                case BufferAccess::Draw:
                    return GL_DYNAMIC_DRAW;
                case BufferAccess::Read:
                    return GL_DYNAMIC_READ;
                case BufferAccess::Copy:
                    return GL_DYNAMIC_COPY;
            }
    }
}

}
