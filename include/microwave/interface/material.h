
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/interface/material.h
 */

#ifndef __INTERFACE_MATERIAL_H_
#define __INTERFACE_MATERIAL_H_

#include <cstddef>
#include <string>

class IMaterial
{
public:
    virtual ~IMaterial() = default;
    virtual void init() = 0;
    virtual void compile() = 0;
    virtual void use() = 0;

    virtual void set_geometry_shader_source(const std::string &path) = 0;
    virtual void set_vertex_shader_source(const std::string &path) = 0;
    virtual void set_fragment_shader_source(const std::string &path) = 0;

    virtual bool compile_geometry_shader() = 0;
    virtual bool compile_vertex_shader() = 0;
    virtual bool compile_fragment_shader() = 0;
};

#endif

/* EOF */
