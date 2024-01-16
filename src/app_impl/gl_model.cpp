
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: app_impl/gl_model.cpp
 */

#include <microwave/debug/logger.h>
#include <microwave/app_impl/gl_model.h>

GLModel::GLModel()
{
    glGenVertexArrays(1, &vao__);
    glGenBuffers(1, &vbo__);
    glGenBuffers(1, &ebo__);
}

GLModel::GLModel(const gl_vertices_list_t &vertices, const gl_indices_list_t &indices) : GLModel()
{
    set_vertices(vertices);
    set_indices(indices);
}

GLModel::GLModel(const GLfloat *vertices, const size_t vertices_size, const GLuint *indices, const size_t indices_size) : GLModel()
{
    set_vertices(vertices, vertices_size);
    set_indices(indices, indices_size);
}


GLModel::~GLModel()
{
    glDeleteVertexArrays(1, &vao__);
    glDeleteBuffers(1, &vbo__);
    glDeleteBuffers(1, &ebo__);
}

void
GLModel::init()
{
    glBindVertexArray(vao__);

    glBindBuffer(GL_ARRAY_BUFFER, vbo__);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], usage__);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo__);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], usage__);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

GLenum
GLModel::get_usage() const
{
    return usage__;
}

void
GLModel::set_usage(GLenum usage)
{
    usage__ = usage;
}

void
GLModel::set_vertices(const gl_vertices_list_t &vlist)
{
    vertices = vlist;
}

void
GLModel::set_vertices(const GLfloat *varray, const size_t size)
{
    vertices.assign(varray, varray + size);
}

void
GLModel::set_indices(const gl_indices_list_t &ilist)
{
    indices = ilist;
}

void
GLModel::set_indices(const GLuint *ilist, const size_t size)
{
    indices.assign(ilist, ilist + size);
}

/* EOF */
