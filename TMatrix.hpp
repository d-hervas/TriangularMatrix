#ifndef __T_MATRIX__
#define __T_MATRIX__
#include <cstring>
#include <algorithm>
#include <vector>

using std::vector;

template<class T>
class TMatrix {
	private:
		vector<T> matrix;
		size_t computePosition(size_t x, size_t y);
	public:
		explicit TMatrix(size_t N);
		TMatrix();
		size_t size;
		size_t computeSize();
		TMatrix(size_t N, T value); //Initialize all values
		~TMatrix();
		T get(size_t x, size_t y);
		const T& get (size_t x, size_t y) const;
		void set(size_t x, size_t y, T value);
		void setSize(size_t x);
		void reserve(size_t x);
		//Overloading operators
		T operator()(size_t x, size_t y) { return get(x,y); }
		void operator()(size_t x, size_t y, T value) { set(x,y,value); }
		auto begin() { return matrix.begin(); };
		auto end() { return matrix.end(); };
};

template<class T>
TMatrix<T>::TMatrix() : matrix(vector<T>()), size{0}
{ }

template<class T>
TMatrix<T>::TMatrix(const size_t N) : matrix(vector<T>()), size{N} 
{
	matrix.reserve((N*N+N)/2);
}

template<class T>
TMatrix<T>::TMatrix(const size_t N, const T value) : matrix(vector<T>()), size{N}
{
	matrix.resize((N*N+N)/2);
	std::fill(matrix.begin(),matrix.end(), value);
}

template<class T>
TMatrix<T>::~TMatrix() 
{
	vector<T>().swap(matrix);
}

template<class T>
size_t TMatrix<T>::computeSize() 
{
	return (size*size+size)/2;
}

template<class T>
size_t TMatrix<T>::computePosition(size_t x, size_t y) 
{
	if (y > x) {
		size_t aux = x;
		x=y;
		y=aux;
	}
	size_t position = (x*x+x)/2+y;
	return position;
}

template<class T>
T TMatrix<T>::get(const size_t x, const size_t y) 
{
	return matrix[computePosition(x,y)];
}

template<class T>
void TMatrix<T>::set(const size_t x, const size_t y, T value) 
{
	matrix[computePosition(x,y)] = value;
}

template<class T>
void TMatrix<T>::setSize(const size_t x)
{
	size = x;
}

template<class T>
void TMatrix<T>::reserve(const size_t x)
{
	size = x;
	matrix.reserve(x);
}

#endif