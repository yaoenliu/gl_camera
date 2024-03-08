#include <iostream>

#include "MainScene.h"

namespace CG
{
	MainScene::MainScene()
	{
		p0c = { 1, 0.95, 0.01 };
		p1c = { 1, 0.95, 0.01 };
		p2c = { 0.4, 0.4, 0.1 };
	}

	MainScene::~MainScene()
	{
	}

	auto MainScene::Initialize() -> bool
	{
		// load the shader
		glLoadIdentity();
		// Set the camera perspective
		gluPerspective(fov, aspect_ratio, 0.01f, 500.0f);
		// Set the camera position and look direction
		gluLookAt(camera_x, camera_y, camera_z, camera_x + camera_look_x, camera_y + camera_look_y, camera_z + camera_look_z, 0, 1, 0);
		glEnable(GL_DEPTH_TEST);
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
		return true;
	}

	void MainScene::Update(double dt)
	{
		float v_weight = sin(glm::radians(vertical_angle)); // the weight of the vertical movement
		float h_weight = cos(glm::radians(vertical_angle)); // the weight of the horizontal movement
		// the horizontal movement (also vertical if vertical_angle is not 0)
		if (keydown[0])
		{
			camera_x += camera_translate_speed * h_weight * cos(glm::radians(horizontal_angle));
			camera_y += camera_translate_speed * v_weight;
			camera_z -= camera_translate_speed * h_weight * sin(glm::radians(horizontal_angle));
		}
		if (keydown[1])
		{
			camera_x -= camera_translate_speed * h_weight * cos(glm::radians(horizontal_angle));
			camera_y -= camera_translate_speed * v_weight;
			camera_z += camera_translate_speed * h_weight * sin(glm::radians(horizontal_angle));
		}
		if (keydown[2])
		{
			camera_x -= camera_translate_speed * h_weight * sin(glm::radians(horizontal_angle));
			camera_z -= camera_translate_speed * h_weight * cos(glm::radians(horizontal_angle));
		}
		if (keydown[3])
		{
			camera_x += camera_translate_speed * h_weight * sin(glm::radians(horizontal_angle));
			camera_z += camera_translate_speed * h_weight * cos(glm::radians(horizontal_angle));
		}
		// the vertical movement
		if (keydown[4])
		{
			camera_y += camera_translate_speed;
		}
		if (keydown[5])
		{
			camera_y -= camera_translate_speed;
		}
		// update the camera look direction
		camera_look_x = cos(glm::radians(horizontal_angle));
		camera_look_z = -sin(glm::radians(horizontal_angle));
		camera_look_y = sin(glm::radians(vertical_angle));
	}

	void MainScene::Render()
	{
		// update the camera position and look direction
		glLoadIdentity();
		gluPerspective(fov, aspect_ratio, 0.01f, 500.0f);
		gluLookAt(camera_x, camera_y, camera_z, camera_x + camera_look_x, camera_y + camera_look_y, camera_z + camera_look_z, 0, 1, 0);

		// Clear the color and depth buffer
		glClearColor(0.0, 0.0, 0.0, 1); // Black background
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPolygonMode(GL_FRONT_AND_BACK, mode);

		// Update the rotation of the object
		glRotated(rotation++, 0, 1, 0);
		glTranslatef(0, sin(glm::radians(rotation)) / 6, 0);

		float d = 0.15; // the depth of the object
		// Start drawing the object
		glBegin(GL_TRIANGLES);
		//0
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0.718, 0.233, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(0.2743, -0.089, 0);
		//1
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0.718, 0.233, 0);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(0.195, 0.233, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		//2
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(0.195, 0.233, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0.755, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		//3
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0.755, 0);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(-0.195, 0.233, 0);
		//4
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(-0.195, 0.233, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(-0.718, 0.233, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		//5
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(-0.718, 0.233, 0);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(-0.2743, -0.089, 0);
		//6	
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(-0.2743, -0.089, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(-0.443, -0.610, 0);
		//7
		glColor3f(1, 0.95, 0.01);
		glVertex3f(-0.443, -0.610, 0);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(0, -0.377, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		//8
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(0, -0.377, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0.443, -0.610, 0);
		//9
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0.443, -0.610, 0);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(0.2743, -0.089, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		d = -d;
		//10
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0.718, 0.233, 0);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(0.2743, -0.089, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		//11
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0.718, 0.233, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(0.195, 0.233, 0);
		//12
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(0.195, 0.233, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0.755, 0);
		//13
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(-0.195, 0.233, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0.755, 0);
		//14
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(-0.195, 0.233, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(-0.718, 0.233, 0);
		//15
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(-0.2743, -0.089, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(-0.718, 0.233, 0);
		//16	
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(-0.443, -0.610, 0);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(-0.2743, -0.089, 0);
		//17
		glColor3f(1, 0.95, 0.01);
		glVertex3f(-0.443, -0.610, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(0, -0.377, 0);
		//18
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0.443, -0.610, 0);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(0, -0.377, 0);
		//19
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0.443, -0.610, 0);
		glColor3f(1, 0.95, 0.01);
		glVertex3f(0, 0, d);
		glColor3f(0.4, 0.4, 0.1);
		glVertex3f(0.2743, -0.089, 0);
		// End
		glEnd();

		// update the title
		updateTitle();
	}

	// update the camera perspective when the window is resized
	void MainScene::OnResize(int width, int height)
	{
		aspect_ratio = ((float)width) / ((float)height);
		std::cout << "MainScene Resize: " << width << " " << height << std::endl;
		glLoadIdentity();
		gluPerspective(fov, aspect_ratio, 0.01f, 500.0f);
		gluLookAt(camera_x, camera_y, camera_z, camera_x + camera_look_x, camera_y + camera_look_y, camera_z + camera_look_z, 0, 1, 0);
	}

	// keyboard event
	void MainScene::OnKeyboard(int key, int action)
	{
		// ignore the repeat action
		if (action == GLFW_REPEAT)
		{
			return;
		}
		std::cout << "MainScene OnKeyboard: " << key << " " << action << std::endl;

		if (action == GLFW_PRESS)
		{
			switch (key)
			{
			case GLFW_KEY_W:
				keydown[0] = true;
				break;
			case GLFW_KEY_S:
				keydown[1] = true;
				break;
			case GLFW_KEY_A:
				keydown[2] = true;
				break;
			case GLFW_KEY_D:
				keydown[3] = true;
				break;
			case GLFW_KEY_E:
				keydown[4] = true;
				break;
			case GLFW_KEY_Q:
				keydown[5] = true;
				break;
			case GLFW_KEY_R: // reset key
				camera_x = 0;
				camera_y = 0;
				camera_z = 5;
				horizontal_angle = 90;
				vertical_angle = 0;
				camera_look_x = 0;
				camera_look_y = 0;
				camera_look_z = -1;
				break;
			case GLFW_KEY_ESCAPE: // close the window
				glfwSetWindowShouldClose(thisWindow, GLFW_TRUE);
				break;
			case GLFW_KEY_LEFT_ALT: // stop locking the cursor
				glfwSetInputMode(thisWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
				cursor_locked = false;
				break;
			}
		}
		if (action == GLFW_RELEASE)
		{
			switch (key)
			{
			case GLFW_KEY_1: // Red
				p0c = { 1.0, 0.0, 0.0 };
				p1c = { 1.0, 0.0, 0.0 };
				p2c = { 1.0, 0.0, 0.0 };
				break;
			case GLFW_KEY_2: // Green
				p0c = { 0.0, 1.0, 0.0 };
				p1c = { 0.0, 1.0, 0.0 };
				p2c = { 0.0, 1.0, 0.0 };
				break;
			case GLFW_KEY_3: // Blue
				p0c = { 0.0, 0.0, 1.0 };
				p1c = { 0.0, 0.0, 1.0 };
				p2c = { 0.0, 0.0, 1.0 };
				break;
			case GLFW_KEY_4: // Rainbow
				p0c = { 1.0, 0.0, 0.0 };
				p1c = { 0.0, 1.0, 0.0 };
				p2c = { 0.0, 0.0, 1.0 };
				break;
			case GLFW_KEY_W:
				keydown[0] = false;
				break;
			case GLFW_KEY_S:
				keydown[1] = false;
				break;
			case GLFW_KEY_A:
				keydown[2] = false;
				break;
			case GLFW_KEY_D:
				keydown[3] = false;
				break;
			case GLFW_KEY_E:
				keydown[4] = false;
				break;
			case GLFW_KEY_Q:
				keydown[5] = false;
				break;
			case GLFW_KEY_LEFT_ALT: // continue locking the cursor
				glfwSetInputMode(thisWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
				mouse_last_x = -1;
				cursor_locked = true;
				break;
			}
		}
	}

	// mouse move event
	void MainScene::OnMouseMove(double x, double y)
	{
		// ignore the first event or the cursor is not locked
		if (mouse_last_x != -1 && cursor_locked)
		{
			// update the camera look direction
			horizontal_angle += (mouse_last_x - x) * camera_rotate_speed;
			vertical_angle += (mouse_last_y - y) * camera_rotate_speed;

			// limit the vertical angle
			if (horizontal_angle > 360)horizontal_angle -= 360;
			if (horizontal_angle < 0)horizontal_angle += 360;
			if (vertical_angle > 90)vertical_angle = 90;
			if (vertical_angle < -90)vertical_angle = -90;
		}
		//std::cout << "MainScene OnMouseMove: " << x << " " << y << std::endl;
		mouse_last_x = x;
		mouse_last_y = y;

	}

	// This could cost a lot of performance
	void MainScene::updateTitle()
	{
		glfwSetWindowTitle(thisWindow, ("Camera Position: (" + std::to_string(camera_x) + ", " + std::to_string(camera_y) + ", " + std::to_string(camera_z) + ") | Camera Look: (" + std::to_string(camera_look_x) + ", " + std::to_string(camera_look_y) + ", " + std::to_string(camera_look_z) + ")").c_str());
	}

	void MainScene::SetMode(int mode)
	{
		switch (mode)
		{
		case 0:
			this->mode = GL_FILL;
			break;
		case 1:
			this->mode = GL_LINE;
			break;
		default:
			this->mode = GL_FILL;
			break;
		}
	}
}