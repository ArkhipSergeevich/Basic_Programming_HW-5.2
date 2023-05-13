#include <iostream>

class triangles 
{
public:
	void print_info(triangles*)
	{
		std::cout << "Sides: " << a << " " << b << " " << c << std::endl;
		std::cout << "Angles: " << A << " " << B << " " << C << std::endl << std::endl;
	}
	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
protected:
	int a, b, c, A, B, C;
};
class isosceles_triangles :public triangles
{
public:
	isosceles_triangles(int a_, int b_, int A_, int B_);
};
class rectangular_triangles :public triangles
{
public:
	rectangular_triangles(int a_, int b_, int c_, int A_, int B_);
};
class equilateral_triangles :public isosceles_triangles
{
public:
	equilateral_triangles(int a_);
};
class quadrilaterals 
{
public:
	void print_info(quadrilaterals*)
	{
		std::cout << "Sides: " << a << " " << b << " " << c << " " << d << std::endl;
		std::cout << "Angles: " << A << " " << B << " " << C << " " << D << std::endl << std::endl;
	}
	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_d() { return d; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
	int get_D() { return D; }
protected:
	int a, b, c, d, A, B, C, D;
};
class rectangles : public quadrilaterals
{
public: 
	rectangles(int a_, int b_);
};
class squares : public rectangles
{
public:
	squares(int a_);
};
class parallelograms : public quadrilaterals
{
public:
	parallelograms(int a_, int b_, int A_, int B_);
};
class rhombs : public parallelograms
{
public:
	rhombs(int a_, int A_, int B_);
};
rectangular_triangles::rectangular_triangles(int a_, int b_, int c_, int A_, int B_)
{
	a = a_; b = b_; c = c_;
	A = A_; B = B_; C = 90;
}
isosceles_triangles::isosceles_triangles(int a_, int b_, int A_, int B_)
{
	a = a_; b = b_; c = a_;
	A = A_; B = B_; C = A_;
}
equilateral_triangles::equilateral_triangles(int a_):isosceles_triangles(a, b, A, B)
{
	a = b = c = a_;
	A = 60; B = A; C = A;
}
rectangles::rectangles(int a_, int b_)
{
	a = a_; b = b_; c = a_; d = b_;
	A = B = C = D = 90;
}
squares::squares(int a_):rectangles(a, b)
{
	a = b = c = d = a_;
	A = B = C = D = 90;
}
parallelograms::parallelograms(int a_, int b_, int A_, int B_)
{
	a = c = a_; b = d = b_;
	A = C = A_; B = D = B_;
}
rhombs::rhombs(int a_, int A_, int B_):parallelograms(a, b, A, B)
{
	a = b = c = d = a_;
	A = C = A_;
	B = D = B_;
}
int main()
{
	rectangular_triangles rectangular_triangle1(1, 2, 3, 40, 50);
	isosceles_triangles isosceles_triangle1(1, 2, 40, 100);
	equilateral_triangles equilateral_triangle1(12);
	rectangles rectangle1(2, 5);
	squares square1(4);
	parallelograms parallelogram1(10, 15, 45, 135);
	rhombs rhomb1(8, 30, 60);
	rectangular_triangle1.print_info(&rectangular_triangle1);
	isosceles_triangle1.print_info(&isosceles_triangle1);
	equilateral_triangle1.print_info(&equilateral_triangle1);
	rectangle1.print_info(&rectangle1);
	square1.print_info(&square1);
	parallelogram1.print_info(&parallelogram1);
	rhomb1.print_info(&rhomb1);
}