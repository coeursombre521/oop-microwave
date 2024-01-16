
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/app_impl/gl_material.h
 */

#ifndef __APP_IMPL_GL_MATERIAL_H_
#define __APP_IMPL_GL_MATERIAL_H_

#include <fstream>
#include <sstream>

#include <gl_common.h>

#include <microwave/interface/material.h>

class GLMaterial :
    public IMaterial
{
public:
    GLMaterial();
    GLMaterial(const std::string &vspath);
    GLMaterial(const std::string &vspath, const std::string &fspath);
    GLMaterial(const std::string &gspath, const std::string &vspath, const std::string &fspath);
    virtual ~GLMaterial();

    void init() override;
    void compile() override;
    void use() override;

    void set_geometry_shader_source(const std::string &path) override;
    void set_vertex_shader_source(const std::string &path) override;
    void set_fragment_shader_source(const std::string &path) override;

    bool compile_geometry_shader() override;
    bool compile_vertex_shader() override;
    bool compile_fragment_shader() override;

    GLuint get_program() const;

protected:
    GLint get_uniform_location(const std::string &name);

    std::string gshader_src_;
    std::string vshader_src_;
    std::string fshader_src_;

    std::string gs_path_;
    std::string vs_path_;
    std::string fs_path_;

    GLuint program_;
    GLuint gshader_;
    GLuint vshader_;
    GLuint fshader_;

    GLint is_linked_ = false;

private:
    std::string get_shader_source(const std::string &path);
    GLuint compile_shader(GLuint &shader, std::string buffer, std::string path);
    GLint link_program();
};

#endif

/* EOF */
