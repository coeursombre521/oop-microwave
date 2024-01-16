
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/app_impl/gl_camera.h
 */

#ifndef __APP_IMPL_GL_CAMERA_H_
#define __APP_IMPL_GL_CAMERA_H_

#include <gl_common.h>
#include <glm/glm.hpp>

#include <microwave/interface/camera.h>

class GLCamera :
    public ICamera
{
public:
    GLCamera();
    GLCamera(const glm::vec3 &position, const glm::vec3 &front, const glm::vec3 &up, const glm::vec3 &right);
    GLCamera(const float pos_x, const float pos_y, const float pos_z,
             const float front_x, const float front_y, const float front_z,
             const float up_x, const float up_y, const float up_z,
             const float right_x, const float right_y, const float right_z);
    virtual ~GLCamera() = default;

    void set_position(const glm::vec3 &position) override;
    void set_position(const float x, const float y, const float z) override;
    void set_front(const glm::vec3 &front) override;
    void set_front(const float x, const float y, const float z) override;
    void set_up(const glm::vec3 &up) override;
    void set_up(const float x, const float y, const float z) override;
    void set_right(const glm::vec3 &right) override;
    void set_right(const float x, const float y, const float z) override;

    void set_yaw(const float yaw) override;
    void set_pitch(const float pitch) override;

    glm::vec3 get_position() const;
    glm::vec3 get_front() const;
    glm::vec3 get_up() const;
    glm::vec3 get_right() const;

    float get_yaw() const;
    float get_pitch() const;

    glm::mat4 get_view_matrix() const;

private:
    glm::vec3 position__;
    glm::vec3 front__;
    glm::vec3 up__;
    glm::vec3 right__;

    float yaw__;
    float pitch__;
};

#endif

/* EOF */
