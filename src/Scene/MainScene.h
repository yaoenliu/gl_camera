#pragma once

#include <array>
#include <string>
#include <map>
#include <vector>
#include <cmath>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace CG
{
	class MainScene
	{
	public:
		MainScene();
		~MainScene();

		auto Initialize() -> bool;
		void Update(double dt);
		void Render();

		void OnResize(int width, int height);
		void OnKeyboard(int key, int action);
		void OnMouseMove(double x, double y);
		void updateTitle();
		void SetMode(int mode);

		std::float_t fov = 90.0f;
		std::float_t aspect_ratio = 1.0f;

	private:
		GLenum mode = GL_FILL; // GL_FILL or GL_LINE

		std::array<float, 3> p0c; // Color of P0
		std::array<float, 3> p1c; // Color of P1
		std::array<float, 3> p2c; // Color of P2

		// the position of the camera
		std::float_t camera_x = 0;
		std::float_t camera_y = 0;
		std::float_t camera_z = 5;

		// the two info below can be replaced by each other and generate by a coodinate transformation if needed (not recommended)

		// the unit vector of the camera look direction
		std::float_t camera_look_x = 0;
		std::float_t camera_look_y = 0;
		std::float_t camera_look_z = -1;

		// the angles of the camera look direction
		std::float_t horizontal_angle = 90;
		std::float_t vertical_angle = 0;

		// the speed of the camera movement and rotation
		std::float_t camera_translate_speed = 0.04f;
		std::float_t camera_rotate_speed = horizontal_angle / 600;
		// the ratio of the fov and the camera_rotate_speed should be 600:1, so that the object in the center of the screen will always ran out when the mouse moves 600 pixels

		// the position of the mouse when last event was called
		std::int16_t mouse_last_x = -1;
		std::int16_t mouse_last_y = 0;

		// the keys that are currently pressed
		bool keydown[6] = { false, false, false, false, false, false };
		// the cursor is locked to the window
		bool cursor_locked = true;

		// the rotation of the object
		float rotation = 0.0f;
		
		// the window that this scene is in
		GLFWwindow* thisWindow = glfwGetCurrentContext();

	};
}

