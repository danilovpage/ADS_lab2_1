#pragma once
#include <iostream>
#include <complex>
#include <math.h>
#include <exception>
#include <string>

namespace Polylines
{
	struct IntPoint2
	{
		int x;
		int y;

		bool operator == (const IntPoint2& Point) const
		{
			if ((x == Point.x) && (y == Point.y))
				return true;
			else return false;
		}

		float Distance(const IntPoint2& Point)
		{
			return static_cast<float>(sqrt(pow(x - Point.x, 2) + pow(y - Point.y, 2)));
		}
	};

	std::ostream& operator << (std::ostream& out, const IntPoint2& Point)
	{
		out << "[" << Point.x << ";" << Point.y << "]";
		return out;
	}

	std::istream& operator>>(std::istream& in, IntPoint2& p_i)
	{
		char data[32] = { 0 };
		char* pointer = data;
		in.getline(pointer, 32);
		pointer = pointer + 1;
		char* tmp = strchr(pointer, ';');
		size_t len_data = (tmp - pointer) / sizeof(char);
		char data_x[32] = { 0 };
		for (size_t j = 0; j < len_data; j++)
		{
			data_x[j] = pointer[j];
		}
		p_i.x = atoi(data_x);

		pointer = tmp + 1;

		tmp = strchr(pointer, ')');
		len_data = (tmp - pointer) / sizeof(char);
		char data_y[32] = { 0 };
		for (size_t j = 0; j < len_data; j++)
		{
			data_y[j] = pointer[j];
		}
		p_i.y = atoi(data_y);
		return in;
	}

	struct DoublePoint3
	{
		double x;
		double y;
		double z;

		double Distance(const DoublePoint3& Point)
		{
			return sqrt(pow(x - Point.x, 2) + pow(y - Point.y, 2) + pow(z - Point.z, 2));
		}


		bool operator == (const DoublePoint3& Point) const
		{
			if ((x == Point.x) && (y == Point.y) && (z == Point.z))
				return true;
			else return false;
		}
	};
	std::ostream& operator << (std::ostream& out, const DoublePoint3& Point)
	{
		out << "[" << Point.x << ";" << Point.y << ";" << Point.z << "]";
		return out;
	}

	std::istream& operator>>(std::istream& in, DoublePoint3& p_i)
	{
		char data[64] = { 0 };
		char* pointer = data;
		in.getline(pointer, 64);
		pointer = pointer + 1;
		char* tmp = strchr(pointer, ';');
		size_t len_data = (tmp - pointer) / sizeof(char);
		char data_x[32] = { 0 };
		for (size_t i = 0; i < len_data; i++)
		{
			data_x[i] = pointer[i];
		}
		p_i.x = atof(data_x);

		pointer = tmp + 1;

		tmp = strchr(pointer, ';');
		len_data = (tmp - pointer) / sizeof(char);
		char data_y[32] = { 0 };
		for (size_t j = 0; j < len_data; j++)
		{
			data_y[j] = pointer[j];
		}
		p_i.y = atof(data_y);

		pointer = tmp + 1;

		tmp = strchr(pointer, ')');
		len_data = (tmp - pointer) / sizeof(char);
		char data_z[32] = { 0 };
		for (size_t k = 0; k < len_data; k++)
		{
			data_z[k] = pointer[k];
		}
		p_i.z = atof(data_z);
		return in;
	}

	std::ostream& operator<< (std::ostream& out, const std::complex<double>& Point)
	{
		out << "[" << Point.real() << ";" << Point.imag() << "*i" << "]";
		return out;
	}

	std::istream& operator>>(std::istream& in, std::complex<double>& p_i)
	{
		double _re = 0;
		double _im = 0;
		char data[32] = { 0 };
		char* pointer = data;
		in.getline(pointer, 32);
		pointer = pointer + 1;
		char* tmp = strchr(pointer, ';');
		size_t len_data = (tmp - pointer) / sizeof(char);
		char data_real[32] = { 0 };
		for (size_t j = 0; j < len_data; j++)
		{
			data_real[j] = pointer[j];
		}
		_re = std::stod(data_real);
		pointer = tmp + 1;

		tmp = strchr(pointer, ')');
		len_data = (tmp - pointer) / sizeof(char);
		char data_image[32] = { 0 };
		for (size_t j = 0; j < len_data; j++)
		{
			data_image[j] = pointer[j];
		}
		_im = std::stod(data_image);

		std::complex<double> temp(_re, _im);
		p_i = temp;
		return in;
	}


	template <class T>
	class Polyline
	{
	private:
		T* Dots;
		int Vertex;
	public:
		Polyline();
		Polyline(int N);
		~Polyline();
		Polyline(const Polyline& other);
		int get_vertex() const;
		Polyline& operator = (const Polyline& other);
		T& operator [] (const int Index);
		T operator[](const int Index) const;
		void swap(Polyline&);
		Polyline& operator > (T NewPoint);
		Polyline& operator < (T NewPoint);
		Polyline operator + (const Polyline& Line);
		auto Distance() const;
		bool operator == (Polyline& other) const;
		bool operator!=(const Polyline<T>& other) const;
	};

	auto Polyline<std::complex<double>>::Distance() const
	{
		if ((Dots == nullptr) || (Vertex < 2))
			throw "Error. ";
		double Length = 0;
		for (int i = 0; i < Vertex - 1; i++)
		{
			Length += std::abs(Dots[i + 1] - Dots[i]);
		}
		return Length;
	}



	template <class T>
	Polyline<T>::Polyline() : Vertex(0), Dots(NULL) {}

	template <class T>
	Polyline<T>::Polyline(int N) : Vertex(N)
	{
		Dots = new T[Vertex];
	}

	template <class T>
	Polyline<T>::Polyline(const Polyline& other) : Vertex(other.Vertex)
	{
		Dots = new T[other.Vertex];
		for (int i = 0; i < Vertex; i++)
		{
			Dots[i] = other.Dots[i];
		}
	}

	template <class T>
	Polyline<T>::~Polyline()
	{
		delete[] Dots;
	}

	template <class T>
	void Polyline<T>::swap(Polyline<T>& other)
	{
		std::swap(Vertex, other.Vertex);
		std::swap(Dots, other.Dots);
	}

	template <class T>
	int Polyline<T>::get_vertex() const
	{
		return Vertex;
	}

	template <class T>
	T& Polyline<T>::operator [] (int Index)
	{
		if (Index > Vertex || Index < 0)
			throw ("out_of_bounds");
		else
			return Dots[Index];
	}

	template <class T>
	T Polyline<T>::operator[](int Index) const
	{
		if (Index > Vertex || Index < 0)
			throw ("out_of_bounds");
		else
			return Dots[Index];
	}


	template <class T>
	Polyline<T>& Polyline<T>::operator>(T NewPoint) // add end
	{
		Vertex++;
		T* Temp = new T[Vertex];

		for (int i = 0; i < Vertex; i++)
		{
			Temp[i] = Dots[i];
		}
		Temp[Vertex - 1] = NewPoint;
		delete[]Dots;
		Dots = Temp;
		return *this;
	}


	template <class T>
	Polyline<T>& Polyline<T>::operator <(T NewPoint) // add begin
	{
		Vertex++;
		T* Temp = new T[Vertex];
		Temp[0] = NewPoint;
		for (int i = 0; i < Vertex - 1; i++)
		{
			Temp[i + 1] = Dots[i];
		}

		delete[] Dots;
		Dots = Temp;
		return *this;
	}


	template <class T>
	Polyline<T>& Polyline<T>::operator=(const Polyline<T>& other)
	{
		Polyline copy(other);
		swap(copy);
		return *this;
	}


	template <class T>
	Polyline<T> Polyline<T>::operator + (const Polyline<T>& Line)
	{
		if (!Vertex)
			return Line;
		if (!Line.Vertex)
			return *this;
		Polyline ResultLine(Vertex + Line.Vertex);
		for (int i = 0; i < Vertex; i++)
		{
			ResultLine[i] = Dots[i];
		}
		for (int i = 0; i < Line.Vertex; i++)
		{
			ResultLine[Vertex + i] = Line.Dots[i];
		}
		return ResultLine;
	}


	template <class T>
	bool Polyline<T>::operator==(Polyline<T>& other) const
	{
		if (Vertex != other.Vertex)
			return false;
		for (int i = 0; i < Vertex; i++)
		{
			if (!(Dots[i] == other.Dots[i]))
				return false;
		}
		return true;
	}


	template <class T>
	bool Polyline<T>::operator!=(const Polyline<T>& other) const
	{
		if (Vertex != other.Vertex)
			return true;
		for (int i = 0; i < Vertex; i++)
		{
			if (!(Dots[i] == other.Dots[i]))
				return true;
		}
		return false;
	}

	template <class T>
	std::ostream& operator << (std::ostream& out, const Polyline<T>& Line)
	{
		for (int i = 0; i < Line.get_vertex(); i++)
		{
			out << Line[i] << "  ";
		}
		out << std::endl;
		return out;
	}

	template <class T>
	std::istream& operator>>(std::istream& in, Polyline<T>& p)
	{
		int n;
		in >> n;
		in.get();
		Polyline<T> _p(n);
		for (size_t i = 0; i < n; i++)
		{
			T v;
			in >> v;
			_p[i] = v;
		}
		p = _p;
		return in;
	}

	template <class T>
	auto Polyline<T>::Distance() const
	{
		if ((Dots == nullptr) || (Vertex < 2))
			throw "Error. ";

		auto Length = Dots[0].Distance(Dots[1]);
		for (int i = 1; i < Vertex - 1; i++)
		{
			Length += Dots[i].Distance(Dots[i + 1]);
		}
		return Length;
	}

}