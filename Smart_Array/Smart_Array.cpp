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
		ptr[pos_arr] = elm;
		pos_arr++;
		if (pos_arr > size_) {
			throw std::runtime_error("Array out of bounds");
		}
	}

	int get_element(int position) {
		return  ptr[position - 1];
	}

	smart_array& operator=(const smart_array& other)
	{
		delete[] ptr;
		if (size_ < other.size_) {
			throw std::runtime_error("Array overflow");
		}
		for (int i = 0; i < size_; i++) {
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
		std::cout << arr.get_element(1);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
