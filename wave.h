#pragma once
#include<string>

#define PI 3.141592653

class sin_wave {

public:

	sin_wave(const int& size);		// Standard constructor
	sin_wave(const sin_wave& a);	// standard copy constructor
	~sin_wave();
	int return_size_of_array() const;			// Returns size of array
	float return_specific_data(const int& i);	// Returns specific value 
protected:
	int	m_size;;
	float *data;

};