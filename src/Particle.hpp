#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_

namespace fl {

struct Particle {

	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;
	double m_rotation_speed;

private:
	void init();

public:
	Particle();
	void update(int delta);
};

}

#endif /* PARTICLE_HPP_ */
