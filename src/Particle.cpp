#include <stdlib.h>
#include <math.h>
#include "Particle.hpp"

namespace fl {

Particle::Particle() : m_x(0), m_y(0) {
	// Set initial velocity (in [1/ms])
	m_speed = (0.001 * rand())/RAND_MAX;
	// Set a random direction
	m_direction = (2*M_PI * rand())/RAND_MAX;
}

void Particle::update(int delta) {
	// Update the position (here trajectory = expolosion)
	m_x += m_speed * cos(m_direction) * delta;
	m_y += m_speed * sin(m_direction) * delta;

}

}
