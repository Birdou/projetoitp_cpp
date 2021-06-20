
#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <sstream>
#include <cmath>

/**
 * @brief      This class describes a vector 2d.
 */
class Vector2D
{
public:
	float x;
	float y;
	int Ix;
	int Iy;
	/**
	 * @brief      Constructs a new instance.
	 */
	Vector2D();
	/**
	 * @brief      Constructs a new instance.
	 *
	 * @param[in]  x     { parameter_description }
	 * @param[in]  y     { parameter_description }
	 */
	Vector2D(float x, float y);

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  angle  The angle
	 */
	void Rotate(float angle);
	/**
	 * @brief      { function_description }
	 */
	void Assoc();

	/**
	 * @brief      Adds the specified vector.
	 *
	 * @param[in]  vec   The vector
	 *
	 * @return     { description_of_the_return_value }
	 */
	Vector2D& Add(const Vector2D& vec);
	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  vec   The vector
	 *
	 * @return     { description_of_the_return_value }
	 */
	Vector2D& Subtract(const Vector2D& vec);
	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  vec   The vector
	 *
	 * @return     { description_of_the_return_value }
	 */
	Vector2D& Multiply(const Vector2D& vec);
	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  vec   The vector
	 *
	 * @return     { description_of_the_return_value }
	 */
	Vector2D& Divide(const Vector2D& vec);

	friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

	/**
	 * @brief      Addition assignment operator.
	 *
	 * @param[in]  vec   The vector
	 *
	 * @return     The result of the addition assignment
	 */
	Vector2D& operator+=(const Vector2D& vec);
	/**
	 * @brief      Subtraction assignment operator.
	 *
	 * @param[in]  vec   The vector
	 *
	 * @return     The result of the subtraction assignment
	 */
	Vector2D& operator-=(const Vector2D& vec);
	/**
	 * @brief      Multiplication assignment operator.
	 *
	 * @param[in]  vec   The vector
	 *
	 * @return     The result of the multiplication assignment
	 */
	Vector2D& operator*=(const Vector2D& vec);
	/**
	 * @brief      Division assignment operator.
	 *
	 * @param[in]  vec   The vector
	 *
	 * @return     The result of the division assignment
	 */
	Vector2D& operator/=(const Vector2D& vec);
	/**
	 * @brief      Equality operator.
	 *
	 * @param[in]  vec   The vector
	 *
	 * @return     The result of the equality
	 */
	bool operator==(const Vector2D& vec);

	/**
	 * @brief      Multiplication operator.
	 *
	 * @param[in]  i     { parameter_description }
	 *
	 * @return     The result of the multiplication
	 */
	Vector2D& operator*(const int& i);
	/**
	 * @brief      { function_description }
	 *
	 * @return     { description_of_the_return_value }
	 */
	Vector2D& Zero();
	/**
	 * @brief      { function_description }
	 *
	 * @return     { description_of_the_return_value }
	 */
	Vector2D& Null();

	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);
};

#endif