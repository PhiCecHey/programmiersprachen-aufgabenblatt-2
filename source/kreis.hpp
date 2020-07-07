#include "vec2.hpp" 
#include "color.hpp" 
//#include "window.hpp"
#include "rechteck.hpp"

#ifndef KREIS_HPP
#define KREIS_HPP

class Kreis {
public:
	Kreis(Kreis const& kreis); //copy constructor
	Kreis(Vec2 const& center, float radius, Color const& color);
	Kreis(Vec2 const& center, float radius);
	Kreis(float radius);
	Kreis() = default;

	bool operator<(Kreis const& r) const;
	bool operator>(Kreis const& r) const;
	bool operator==(Kreis const& r) const;

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

private:
	Vec2 center_;
	float radius_;
	Color color_;
};

//bool is_inside(Window& window, Kreis const& kreis);

struct lessKreis {
	bool operator() (Kreis const& a, Kreis const& b) const {
		return a.radius() < b.radius();
	}
};

#endif