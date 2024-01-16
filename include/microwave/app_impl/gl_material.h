
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
    std::string gshader_src__;
    std::string vshader_src__;
    std::string fshader_src__;

    std::string gs_path__;
    std::string vs_path__;
    std::string fs_path__;

    GLuint program__;
    GLuint gshader__;
    GLuint vshader__;
    GLuint fshader__;

    bool is_compiled_gshader__ = false;
    bool is_compiled_vshader__ = false;
    bool is_compiled_fshader__ = false;

    GLint is_linked__ = false;

private:
    GLuint compile_shader(GLuint &shader, std::string buffer, std::string path, bool &compiled);
    GLint link_program();
    std::string get_shader_source(const std::string &path);
};

#endif

/* EOF */
