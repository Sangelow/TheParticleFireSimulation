#include <stdlib.h>
#include "Particle.hpp"

namespace fl {

Particle::Particle() {
	// Set initial position
	m_x = (2*(double)rand()/RAND_MAX) - 1;
	m_y = (2*(double)rand()/RAND_MAX) - 1;
	// Set initial velocity
	m_vx = 0.001 * (2*(double)rand()/RAND_MAX - 1);
	m_vy = 0.001 * (2*(double)rand()/RAND_MAX - 1);
}

void Particle::update() {

	// Update the position of the particle
	m_x += m_vx;
	m_y += m_vy;

	// If the particle goes out of the screen, change the velocity to its opposite
	if ( m_x <= -1.&& m_vx < 0 ) {
		m_vx = -m_vx;
	}
	if ( 1 <= m_x && 0 <= m_vx ) {
		m_vx = -m_vx;
	}
	if ( m_y <= -1.&& m_vy < 0 ) {
		m_vy = -m_vy;
	}
	if ( 1 <= m_y && 0 <= m_vy ) {
		m_vy = -m_vy;
	}

}

}
