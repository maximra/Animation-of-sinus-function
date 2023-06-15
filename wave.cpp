#include "wave.h"
#include<iostream>
#include<math.h>
sin_wave::sin_wave(const int& size)
{
	m_size = size;
	data = new float[size];

	for (int i = 0; i < m_size; i++)
	{
		data[i] = sin(2 * PI * double(i) / double(m_size));
	}
	
}

sin_wave::sin_wave(const sin_wave& a)
{
	m_size = a.m_size;
	data = new float[m_size];
	for (int i = 0; i < m_size; i++)
	{
		data[i] = a.data[i];
	}

}

sin_wave::~sin_wave()
{
	delete[] data;
}


int sin_wave::return_size_of_array() const
{
	return m_size;
}

float sin_wave::return_specific_data(const int& i) const
{
	if (i > 0 and i < m_size)
	{
		return data[i];
	}
	else
	{
		return 0.0f;
	}
}


