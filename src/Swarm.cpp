#include "Swarm.hpp"

namespace fl {

Swarm::Swarm () {
	// Create the particles
	m_particles = new Particle[N_PARTICLES];

}

Swarm::~Swarm() {
	// Deallocate the memory
	delete [] m_particles;
}

void Swarm::update(int delta) {
	// Update all the particle position
	for (int i=0; i<N_PARTICLES; i++) {
		m_particles[i].update(delta);
	}
}

}
