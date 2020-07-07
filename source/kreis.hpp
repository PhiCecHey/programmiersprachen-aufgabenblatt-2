#include "vec2.hpp" 
#include "color.hpp" 
//#include "window.hpp"
#include "rechteck.hpp"
#include <string>

#ifndef KREIS_HPP
#define KREIS_HPP

class Kreis {
public:
	Kreis(Kreis const& kreis); //copy constructor
	Kreis(Vec2 const& center, float radius, Color const& color);
	Kreis(Vec2 const& center, float radius);
	Kreis(float radius);
	Kreis() = default;
	Kreis(Vec2 const& center, float radius, Color const& color, std::string name);

	bool operator<(Kreis const& r) const;
	bool operator>(Kreis const& r) const;
	bool operator==(Kreis const& r) const;

	void print() const;

	/*
	void set_center(Vec2 const& center);
	void set_color(Color const& color);
	Vec2 get_center() const;
	*/
	float circumference() const;
	//void draw(Window & window, float const& thickness) const;
	//void draw(Window & window) const;
	Rechteck bounding_box() const;
	float radius() const;
	Vec2 center() const;
	Color color() const;
	std::string name() const;

private:
	Vec2 center_;
	float radius_;
	Color color_;
	std::string name_;
};

//bool is_inside(Window& window, Kreis const& kreis);

struct lessKreis {
	bool operator() (Kreis const& a, Kreis const& b) const {
		return a.radius() < b.radius();
	}
};

std::ostream& operator<<(std::ostream& os, Kreis const& c);

#endif