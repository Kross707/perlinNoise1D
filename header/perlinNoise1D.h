#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<math.h>
#include<random>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<conio.h>

struct color
{
	float r, g, b;
	color(float red, float green, float blue)
	{
		r = red;
		g = green;
		b = blue;
	}
};

void display(std::vector<double> vec)
{
	for (auto a : vec)
		std::cout << a << " ";
	std::cout << "\n";
}

class perlinNoise1D
{
private:
	std::vector<double> vec;
	double initValue, finalValue;
	unsigned int size;

	std::vector<double> add(std::vector<double> a, std::vector<double> b)
	{
		std::vector<double> result(size);
		for (unsigned int i = 0; i < size; i++)
			result[i] = a[i] + b[i];
		return result;
	}
	double linearInterpolation(double x1, double y1, double x2, double y2, double x)
	{
		double m = (y2 - y1) / (x2 - x1);
		return m * (x - x2) + y2;
	}
	std::vector<double> sampleVector(std::vector<double> vec, int intervalSkip)
	{
		std::vector<double> result(size);
		unsigned int prev = 0, next = intervalSkip;
		for (unsigned int i = 0; i < size; i++)
		{
			result[i] = linearInterpolation(prev, vec[prev], next, vec[next % size], i) * intervalSkip / size;
			if (i > next)
			{
				prev = next;
				next += intervalSkip;
			}
		}
		return result;
	}
	void draw(std::vector<double> vec, color c = { 0, 255, 0 })
	{

		unsigned int size = vec.size();

		glColor3f(c.r, c.g, c.b);
		glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(0, vec[0]);
		for (int i = 0; i < size - 1; i++)
		{
			glVertex2f(i, vec[i]);
			glVertex2f(i + 1, vec[i + 1]);
		}
		glVertex2f(size - 1, vec[size - 1]);
		glVertex2f(size, vec[0]);
		glEnd();
	}
public:
	perlinNoise1D()
	{
		size = 0;
	}
	perlinNoise1D(int size, double finalValue = 2, double initValue = 0)
	{
		vec = std::vector<double>(size);
		this->size = size;
		this->initValue = initValue;
		this->finalValue = finalValue;

		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> dist(initValue, finalValue);
		
		for (int i = 0; i < size; i++)
			vec[i] = dist(mt);
	}
	std::vector<double> getNoise()
	{
		std::vector<double> result(size);
		for (unsigned int i = size; i > 0; i /= 2)
		{
			result = add(sampleVector(vec, i), result);
		}
		return result;
	}
	void plotArray(double verticalScaling = 10, color c = {0, 255, 0})
	{

		glfwInit();
		GLFWwindow *window = glfwCreateWindow(800, 600, "Perlin Noise Plot", nullptr, nullptr);
		glfwMakeContextCurrent(window);

		gluOrtho2D(0, size, initValue, verticalScaling * finalValue);
		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			draw(getNoise(), c);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwTerminate();
	}
};

