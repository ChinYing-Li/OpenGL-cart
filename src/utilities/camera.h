#pragma once

#include <math.h>
#include <iostream>

#include "main.h"

class Camera
{
public:
    Camera();
    Camera(const float x, const float y, const float z);
    Camera(const glm::vec3 position);
    ~Camera() = default;
    
    void update_matrices(GLMatrices& mat);
    //void update_cam(const int user_input);
    
protected:
    //glm::vec3 m_stepsize;
    
    glm::vec3 m_eye;
    glm::vec3 m_direction;
    glm::vec3 m_up;
};

class CarCam: public Camera
{
public:
    CarCam() = delete;
    CarCam(const float x, const float y, const float z);
    CarCam(const glm::vec3 position);
    ~CarCam() = default;
    
    void set_eye(const glm::vec3 pos);
    void set_direction(const glm::vec3 dir);
};

class FreeCam: public Camera
{
public:
    FreeCam();
    FreeCam(const float x, const float y, const float z);
    FreeCam(const glm::vec3 position);
    ~FreeCam() = default;
    
    void update_cam(const int user_input);
    void set_stepsize(const glm::vec3 new_stepsize);
private:
    float m_rotate_ang; // in radians
    glm::vec3 m_stepsize;
    glm::mat4 m_cw_mat;
    glm::mat4 m_ccw_mat;
};
