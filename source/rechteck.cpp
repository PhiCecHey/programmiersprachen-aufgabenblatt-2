
#include "rechteck.hpp"
#include "vec2.hpp" 
#include "pair.hpp"
//#include "window.hpp"

#include <iostream>

Rechteck::Rechteck(Rechteck const& rechteck) {
	this->max_ = rechteck.max_;
	this->min_ = rechteck.min_;
	this->color_ = rechteck.color_;
}

Rechteck::Rechteck(Vec2 const& min, Vec2 const& max, Color const& color) :
	min_{ min },
	max_{ max },
	color_{ color }
{}

Rechteck::Rechteck(Vec2 const& min, Vec2 const& max) :
	min_{ min },
	max_{ max },
	color_{ 0, 0, 0 }
{}

Vec2 const& Rechteck::min() const {
	return this->min_;
}

Vec2 const& Rechteck::max() const {
	return this->max_;
}

Pair Rechteck::side_lenghs() const {
	float x;
	if (this->max_.x > this->min_.x) {
		x = this->max_.x - this->min_.x;
	}
	else {
		x = this->min_.x - this->max_.x;
	}
	float y;
	if (this->max_.y > this->min_.y) {
		y = this->max_.y - this->min_.y;
	}
	else {
		y = this->min_.y - this->max_.y;
	}
	return Pair{ x, y };
}

float Rechteck::circumference() const {
	Pair a{ this->side_lenghs() };
	return (a.a + a.b) * 2;
}

/*void Rechteck::draw(Window& window, float const& thickness) const {
	float line = thickness;
	if (is_inside(window, *this)) {
		line *= 2;
	}
	Pair a{ this->side_lenghs() };
	//unten links nach unten rechts:
	window.draw_line(
		this->min_.x, this->min_.y,
		this->min_.x + a.a, this->min_.y,
		this->color_.r, this->color_.g, this->color_.b, line
	);
	//unten rechts nach oben rechts:
	window.draw_line(
		this->min_.x + a.a, this->min_.y,
		this->max_.x, this->max_.y,
		this->color_.r, this->color_.g, this->color_.b, line
	);
	//oben rechts nach oben links:
	window.draw_line(
		this->max_.x, this->max_.y,
		this->max_.x - a.a, this->max_.y,
		this->color_.r, this->color_.g, this->color_.b, line
	);
	//oben links nach unten links:
	window.draw_line(
		this->max_.x - a.a, this->max_.y,
		this->min_.x, this->min_.y,
		this->color_.r, this->color_.g, this->color_.b, line
	);
	return;
}

void Rechteck::draw(Window& window) const {
	Rechteck::draw(window, 1);
}

bool is_inside(Window & window, Rechteck const& rechteck) {
	auto mouse = window.mouse_position();
	Vec2 r_min = rechteck.min();
	Vec2 r_max = rechteck.max();
	if (r_min.x <= mouse.first && mouse.first <= r_max.x &&
		r_min.x >= mouse.second && mouse.second >= r_max.y) {
		return true;
	}
	return false;
}*/