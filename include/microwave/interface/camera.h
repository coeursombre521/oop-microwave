
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/interface/camera.h
 */

#ifndef __INTERFACE_CAMERA_H_
#define __INTERFACE_CAMERA_H_

#include <glm/glm.hpp>

class ICamera
{
public:
    virtual void set_position(const glm::vec3 &position) = 0;
    virtual void set_position(const float x, const float y, const float z) = 0;
    virtual void set_front(const glm::vec3 &front) = 0;
    virtual void set_front(const float x, const float y, const float z) = 0;
    virtual void set_up(const glm::vec3 &up) = 0;
    virtual void set_up(const float x, const float y, const float z) = 0;
    virtual void set_right(const glm::vec3 &right) = 0;
    virtual void set_right(const float x, const float y, const float z) = 0;

    virtual void set_yaw(const float yaw) = 0;
    virtual void set_pitch(const float pitch) = 0;
};

#endif

/* EOF */
