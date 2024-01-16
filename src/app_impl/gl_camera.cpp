
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: app_impl/gl_camera.cpp
 */

#include <microwave/app_impl/gl_camera.h>

GLCamera::GLCamera()
{
    position__ = glm::vec3(0.0f, 0.0f, 0.0f);
    front__ = glm::vec3(0.0f, 0.0f, -1.0f);
    up__ = glm::vec3(0.0f, 1.0f, 0.0f);
    right__ = glm::vec3(1.0f, 0.0f, 0.0f);

    yaw__ = -90.0f;
    pitch__ = 0.0f;
}

GLCamera::GLCamera(const glm::vec3 &position, const glm::vec3 &front, const glm::vec3 &up, const glm::vec3 &right)
{
    position__ = position;
    front__ = front;
    up__ = up;
    right__ = right;

    yaw__ = -90.0f;
    pitch__ = 0.0f;
}

GLCamera::GLCamera(const float pos_x, const float pos_y, const float pos_z,
                   const float front_x, const float front_y, const float front_z,
                   const float up_x, const float up_y, const float up_z,
                   const float right_x, const float right_y, const float right_z)
{
    position__ = glm::vec3(pos_x, pos_y, pos_z);
    front__ = glm::vec3(front_x, front_y, front_z);
    up__ = glm::vec3(up_x, up_y, up_z);
    right__ = glm::vec3(right_x, right_y, right_z);

    yaw__ = -90.0f;
    pitch__ = 0.0f;
}

void
GLCamera::set_position(const glm::vec3 &position)
{
    position__ = position;
}

void
GLCamera::set_position(const float x, const float y, const float z)
{
    position__ = glm::vec3(x, y, z);
}

void
GLCamera::set_front(const glm::vec3 &front)
{
    front__ = front;
}

void
GLCamera::set_front(const float x, const float y, const float z)
{
    front__ = glm::vec3(x, y, z);
}

void
GLCamera::set_up(const glm::vec3 &up)
{
    up__ = up;
}

void
GLCamera::set_up(const float x, const float y, const float z)
{
    up__ = glm::vec3(x, y, z);
}

void
GLCamera::set_right(const glm::vec3 &right)
{
    right__ = right;
}

void
GLCamera::set_right(const float x, const float y, const float z)
{
    right__ = glm::vec3(x, y, z);
}

void
GLCamera::set_yaw(const float yaw)
{
    yaw__ = yaw;
    update_camera_vectors();
}

void
GLCamera::set_pitch(const float pitch)
{
    pitch__ = pitch;
    update_camera_vectors();
}

glm::vec3
GLCamera::get_position() const
{
    return position__;
}

glm::vec3
GLCamera::get_front() const
{
    return front__;
}

glm::vec3
GLCamera::get_up() const
{
    return up__;
}

glm::vec3
GLCamera::get_right() const
{
    return right__;
}

float
GLCamera::get_yaw() const
{
    return yaw__;
}

float
GLCamera::get_pitch() const
{
    return pitch__;
}

glm::mat4
GLCamera::get_view_matrix() const
{
    return glm::lookAt(position__, position__ + front__, up__);
}

void
GLCamera::update_camera_vectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(yaw__)) * cos(glm::radians(pitch__));
    front.y = sin(glm::radians(pitch__));
    front.z = sin(glm::radians(yaw__)) * cos(glm::radians(pitch__));

    front__ = glm::normalize(front);
    right__ = glm::normalize(glm::cross(front__, glm::vec3(0.0f, 1.0f, 0.0f)));
    up__ = glm::normalize(glm::cross(right__, front__));
}

/* EOF */
