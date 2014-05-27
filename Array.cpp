// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


#include <stdexcept>         // for std::out_of_range exception

//
// Array
//
template <typename T>
Array <T>::Array (void):
data_(0),			// new empty array
cur_size_(0),		// set current size to 0
max_size_(0)		// set max size to 0
{
	
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length):
data_(new T[length]),
cur_size_(length),
max_size_(length)
{
	if (length > 0)
	{
		for (size_t i=0; i < cur_size_ ; ++i)
		{
			*(this->data_ + i) = 0;
		}
	}
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill):
data_(new T[length]),
cur_size_(length),
max_size_(length)
{
	for (size_t i=0; i < cur_size_ ; ++i)
	{
		*(this->data_ + i) = fill;		//reducing the index validity check overhead
	}
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array):
data_(new T[array.cur_size_]),
cur_size_(array.cur_size_),
max_size_(array.cur_size_)
{
	 for (size_t i=0; i < cur_size_ ; ++i)
	 {
		 *(this->data_ + i) = array.data_[i];		//reducing the index validity check overhead
	 }
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	if (0!= data_)
	{
		delete []data_;
	}
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	if (this != &rhs)	// enter only if not self assignment
	{
		
		Array<T> new_array_ (rhs.cur_size_);	//this takes care of the possible memory leak issue

		for (size_t i=0; i < rhs.cur_size_ ; i++)
		{
			*((new_array_.data_)+i) = rhs.data_[i];
		}

		// save the size variables
		size_t cur_size_new_ = rhs.cur_size_;
		size_t max_size_new_ = rhs.cur_size_; 
		
	
		// release current array and set the size variables to new values
		this->cur_size_=cur_size_new_;
		this->max_size_=max_size_new_;
		
		std::swap(data_, new_array_.data_);
		
		
	}
	return *this;	// returning pointer for chain-assignment

}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
	if (index >= this->cur_size_)
	{
		throw std::out_of_range("Specified Index out of range");
	}

	return (this->data_[index]);
}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
		if (index >= this->cur_size_)
	{
		throw std::out_of_range("Specified Index out of range");
	}
	return (this->data_[index]);
}

//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{
	if(index >= this->cur_size_)	// check if index falls outside range
	{
		throw std::out_of_range("Specified Index out of range");
	}
	return (this->data_[index]);
}

//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
	if (index >= this->cur_size_)
	{
		throw std::out_of_range("Specified Index out of range");
	}

	
	 
	this->data_[index]=value;	
}
//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if (new_size != cur_size_)
	{
		if (new_size > cur_size_)
		{
			Array<T> new_array_(new_size);
			//copy current data to new array
			for (size_t i=0;i < cur_size_ ; ++i)
			{
				*(new_array_.data_ + i) = this->data_[i];	// bypass bound-check by controlled assignment
			}
			//set up pointers
			this->cur_size_ = new_size;
			this->max_size_ = new_size;
			//swap new data with current data
			std::swap (data_, new_array_.data_);	
		}
		//if newsize is less than current size
		else 
		{
			this->cur_size_ = new_size;
		}
	}
}

//
// find (char)
//
template  <typename T>
int Array <T>::find (T value) const
{
	for (size_t i = 0; i < (this->cur_size_); ++i)
	{
		if(this->data_[i] == value)
		{
			return i;
		}
	}
	return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Array <T>::find (T val, size_t start) const
{
	if(start > this->cur_size_)
	{
		throw std::out_of_range("Specified	Index out of range");
	}

	// if index is valid, proceed to search
	for (size_t i = start; i < (this->cur_size_); ++i)
	{
		if(this->data_[i] == val)
		{
			return i;
		}
	}
	return -1;
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
	if (this->cur_size_ != rhs.cur_size_) 
	{ 
		return false;
	}
	for (size_t i = 0; i < this->cur_size_; ++i)
	{
		if(this->data_[i] != rhs.data_[i])
		{
			return false;
		}
	}
	return true;
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	return (!(*this == rhs))?true:false;
}

//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{
	for ( size_t i = 0; i < (this->cur_size_); ++i )
	{
		this->data_[i] = value;
	}
}

