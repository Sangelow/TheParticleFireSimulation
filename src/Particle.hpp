#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_

namespace fl {

struct Particle {

	double m_x;
	double m_y;
	double m_speed;
	double m_direction;

public:
	Particle();
	void update(int delta);
};

}

#endif /* PARTICLE_HPP_ */
