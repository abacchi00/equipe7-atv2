#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "abcgOpenGL.hpp"

#include "camera.hpp"

struct Vertex {
  glm::vec3 position;

  friend bool operator==(Vertex const &, Vertex const &) = default;
};

class Window : public abcg::OpenGLWindow {
protected:
  void onEvent(SDL_Event const &event) override;
  void onCreate() override;
  void onPaint() override;
  void onPaintUI() override;
  void onResize(glm::ivec2 const &size) override;
  void onDestroy() override;
  void onUpdate() override;

  void showCameraPositionUI();

private:
  glm::ivec2 m_viewportSize{};

  GLuint m_VAO{};
  GLuint m_VBO{};
  GLuint m_EBO{};
  GLuint m_program{};

  GLint m_viewMatrixLocation{};
  GLint m_projMatrixLocation{};
  GLint m_modelMatrixLocation{};
  GLint m_colorLocation{};

  Camera m_camera;

  std::unordered_map<SDL_Keycode, bool> m_keyState;

  // Camera movement related variables
  float m_dollySpeed = 0.0f;
  float m_panSpeed = 0.0f;
  float m_truckSpeed = 0.0f;

  float m_dollyAcceleration = 0.05f;
  float m_panAcceleration = 0.025f;
  float m_truckAcceleration = 0.05f;

  float m_dollyMaxSpeed = 1.5f;
  float m_panMaxSpeed = 1.0f;
  float m_truckMaxSpeed = 1.0f;

  glm::vec4 m_legoColor{0.0f, 0.0f, 0.0f, 0.0f};

  bool isSphereClicked(glm::vec3 sphereCenter, float radius, float mouseX, float mouseY);

  std::vector<Vertex> m_vertices;
  std::vector<GLuint> m_indices;

  void loadModelFromFile(std::string_view path);
};

#endif
