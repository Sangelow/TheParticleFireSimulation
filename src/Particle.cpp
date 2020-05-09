#include <stdlib.h>
#include <math.h>
#include "Particle.hpp"

namespace fl {

Particle::Particle() {
	init();
}

void Particle::init() {
	// Set initial position
	m_x = 0;
	m_y = 0;
	// Set initial velocity (in [1/s])
	m_speed = (1e-3 * 40 * rand())/RAND_MAX;
	m_speed *= m_speed;
	// Set a random direction
	m_direction = (2*M_PI * rand())/RAND_MAX;
	// Set a random rotation speed
	m_rotation_speed = 1e-3 * 0.1 * 2*M_PI;
}

void Particle::update(int delta) {
	// Change the direction
	m_direction += delta * m_rotation_speed;
	// Update the position (here trajectory = expolosion)
	m_x += m_speed * cos(m_direction) * delta;
	m_y += m_speed * sin(m_direction) * delta;
	// If the particle goes out of the screen
	if (m_x < -1 || 1 < m_x || m_y < -1 || 1 < m_y) {
		// Reset the particle
		init();
	}
	// Reset random particles
	if (rand() < RAND_MAX/1000) {
		init();
	}
}

}
