#pragma once
#include<string>

#define PI 3.141592653

class sin_wave {

public:

	sin_wave(const int& size);		// Standard constructor
	sin_wave(const sin_wave& a);	// standard copy constructor
	~sin_wave();
	int return_size_of_array() const;			// Returns size of array
	float return_specific_data(const int& i) const;	// Returns specific value 
protected:
	int	m_size;;
	float *data;

};

class sin_changed_freq: public sin_wave {		// Very similar class, only here we can control the frequency too
	
public:
	sin_changed_freq(const int& size, const double& freq) : sin_wave(size), m_freq(freq) {
		
		for (int i = 0; i < m_size; i++)
		{
			data[i] = sin(2 * PI * double(i) * m_freq / double(m_size));
		}
	}

protected:
	double m_freq;
};