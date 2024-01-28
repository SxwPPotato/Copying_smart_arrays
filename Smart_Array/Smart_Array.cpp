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
		delete[] ptr;
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
	
};


int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
