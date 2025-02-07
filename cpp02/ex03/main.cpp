#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void run_test(Point& p1, Point& p2, Point& p3, Point& p)
{
	std::cout << "Triangle: " << p1 << " || " << p2 << " || " << p3 << " || " << std::endl;
	std::cout << "Point: " << p << std::endl;
	std::cout << (bsp(p1, p2, p3, p) ? "Inside" : "Outside") << std::endl;
}

int main(void)
{
    Point p1(0, 0);
    Point p2(20, 0);
    Point p3(10, 30);

    Point p4(10, 0);
    std::cout << "Test 2: (Expected: Outside)" << std::endl;
	run_test(p1, p2, p3, p4);
	
    Point p5(30, 30);
    std::cout << "Test 3: (Expected: Outside)" << std::endl;
	run_test(p1, p2, p3, p5);
	
    Point p6(0, 0);
    std::cout << "Test 4: (Expected: Outside)" << std::endl;
	run_test(p1, p2, p3, p6);
	
    Point p7(10.5f, 15.5f);
    std::cout << "Test 5: (Expected: Inside)" << std::endl;
	run_test(p1, p2, p3, p7);
	
    Point p8(25.5f, 25.5f);
    std::cout << "Test 6: (Expected: Outside)" << std::endl;
	run_test(p1, p2, p3, p8);
	
    Point p9(10, 15);
    std::cout << "Test 1: (Expected: Inside)" << std::endl;
	run_test(p1, p2, p3, p9);
}