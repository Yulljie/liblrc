#include <iostream>
#include "lyric.h"

int main() {
	Lyric lrc;

	lrc.add(10000, "Hello World");
	std::cout << "\"Hello World\" at 10000ms added to index 0." << std::endl;
	lrc.add(15000, "ハローワールド");
	std::cout << "\"ハローワールド\" at 15000ms added to index 1" << std::endl;
	lrc.add(5000, "你好，世界");
	std::cout << "\"你好，世界\" at 5000ms added to index 2" << std::endl;
	std::cout << std::endl;
	
	std::string text = lrc.get_line_by_index(2);
	std::cout << "Now you will see the line at index 2:" << std::endl;
	std::cout << text << std::endl;
	std::cout << std::endl;

	std::cout << "Previously not sorted, now let's sort the added lines..." << std::endl;
	lrc.sort();
	std::cout << "Done." << std::endl;
	std::cout << std::endl;

	std::cout << "Now you will see the index of the line at 16000ms: " << std::endl;
	int32_t idx = lrc.get_index(16000);
	std::cout << idx << std::endl;
	std::cout << "Let's see what it is: " << std::endl;
	text = lrc.get_line_by_index(idx); 
	std::cout << text << std::endl;
	std::cout << std::endl;

	std::cout << "Next line you will see the line at 12000ms: "<< std::endl;
	text = lrc.get_line_by_time(12000);
	std::cout << text << std::endl;
	std::cout << std::endl;

	std::cout << "Delete line at index 1, vector will automatically shift subsquent lines forward..." << std::endl;
	lrc.del(1);
	std::cout << "Now previous index 2 has been moved to index 1. Let's add the abandoned line to index 2, 20000ms."<< std::endl;
	lrc.add(20000, "Hello World");
	std::cout << "You know there's no need to sort, but some functions need sorted lyric. Let's force the lyrics to be sorted..." << std::endl;
	lrc.force_sorted();
	std::cout << "Done." << std::endl;
	
	std::cout << "And let's see the line at 22000ms: " << std::endl;
	text = lrc.get_line_by_time(22000);
	std::cout << text << std::endl;
	std::cout << std::endl;
	
	std::cout << "Also, apply offset +5000, and let's see the line at 22000ms: "<< std::endl;
	lrc.offset(5000);
	text = lrc.get_line_by_time(22000);
	std::cout << text << std::endl;
	std::cout << std::endl;

	std::cout << "Now all founctions tested, happy coding ^_^ " << std::endl;

	return 0;
}
