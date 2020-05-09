#ifndef SWARM_HPP_
#define SWARM_HPP_

#include "Particle.hpp"

namespace fl {

class Swarm {
public:
	const static int N_PARTICLES = 1000;

private:
	Particle * m_particles;

public:
	Swarm();
	~Swarm();
	const Particle * const get_particles() { return m_particles; };
	void update(int delta);
};

}

#endif /* SWARM_HPP_ */
