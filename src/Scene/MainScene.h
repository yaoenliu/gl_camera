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

		std::float_t aspect_ratio = 1.0f;

	private:
		GLenum mode = GL_FILL; // GL_FILL or GL_LINE

		std::array<float, 3> p0c; // Color of P0
		std::array<float, 3> p1c; // Color of P1
		std::array<float, 3> p2c; // Color of P2

		std::float_t camera_x = 0;
		std::float_t camera_y = 0;
		std::float_t camera_z = 5;

		std::float_t camera_look_x = 0;
		std::float_t camera_look_y = 0;
		std::float_t camera_look_z = -1;

		std::float_t horizontal_angle = 90;
		std::float_t vertical_angle = 0;

		std::int8_t is_mouse_down = false;

		std::int16_t mouse_last_x = -1;
		std::int16_t mouse_last_y = 0;

		bool keydown[6] = { false, false, false, false, false, false };
		bool cursor_locked = true;

	};
}

