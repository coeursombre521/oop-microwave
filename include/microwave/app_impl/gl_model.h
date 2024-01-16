
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/app_impl/gl_model.h
 */

#ifndef __APP_IMPL_GL_MODEL_H_
#define __APP_IMPL_GL_MODEL_H_

#include <vector>

#include <gl_common.h>

#include <microwave/interface/model.h>

using gl_vertices_list_t = std::vector<GLfloat>;
using gl_indices_list_t = std::vector<GLuint>;

class GLModel :
    public IModel
{
public:
    GLModel();
    GLModel(const gl_vertices_list_t &vertices, const gl_indices_list_t &indices);
    GLModel(const GLfloat *vertices, const size_t vertices_size, const GLuint *indices, const size_t indices_size);
    virtual ~GLModel();

    void init() override;
    virtual void draw() = 0;

    GLenum get_usage() const;
    void set_usage(GLenum usage);

    void set_vertices(const gl_vertices_list_t &vertices);
    void set_vertices(const GLfloat *vertices, const size_t size);

    void set_indices(const gl_indices_list_t &indices);
    void set_indices(const GLuint *indices, const size_t size);

    gl_vertices_list_t vertices;
    gl_indices_list_t indices;

protected:
    GLuint vao__;
    GLuint vbo__;
    GLuint ebo__;
    GLenum usage__ = GL_STATIC_DRAW;
};

#endif

/* EOF */
