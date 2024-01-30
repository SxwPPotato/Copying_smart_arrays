#include <iostream>

class smart_array {
private:
	int size_;
	int* ptr;
	int pos_arr = 0;
public:
	smart_array(int size): ptr(new int[size]), size_(size) {
	
	}

	~smart_array() {

		if(ptr != nullptr) {

			delete[] ptr;

		}
	}

	void add_element(int elm) {
		if (pos_arr > size_) {
			throw std::runtime_error("Array out of bounds");
		}
		ptr[pos_arr] = elm;
		pos_arr++;
	}

	int get_element(int position) {
		if (position < 0 || position > size_) {
			throw std::runtime_error("The requested element does not exist");
		}
		else return  ptr[position];
	}

	smart_array& operator=(const smart_array& other)
	{
		delete[] ptr;
		if (size_ < other.size_) {
			throw std::runtime_error("Array overflow");
		}

		size_ = other.size_;
		pos_arr = other.pos_arr;
		ptr = new int[size_];
		for (int i = 0; i < other.pos_arr; i++) {	
			ptr[i] = other.ptr[i];
		}
		return *this;
	}

};


int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;
		std::cout << arr.get_element(0);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
