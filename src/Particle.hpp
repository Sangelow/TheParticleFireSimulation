#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_

namespace fl {

struct Particle {

	double m_x;
	double m_y;
	double m_vx;
	double m_vy;

public:
	Particle();
	void update();
};

}

#endif /* PARTICLE_HPP_ */
