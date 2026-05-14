// filename: lrctools.h

#ifndef LRCTOOLS_H
#define LRCTOOLS_H

#include <string>
#include <vector>
#include <regex>

namespace lrcparse {
	std::regex timetag(R"(^\[(\d{2}):(\d{2})\.(\d{2,3})\])");

	// Remove all time tag of words, return converted line. Both single line and multiple line are accepted.
	std::string remove_inline_time(std::string raw);
	
	// Convert given raw text to standard multiple line lyric text
	// raw text lyric will be devided into multiple single lines (this will follow the order of the given text and not sort by time), metadata will be saved to the last element
	std::vector<std::string> convert_to_vector(std::string raw);

	// Check if a line contains a time tag at head
	bool is_time_head(std::string line);

	// Read time from the head of a single line, this will not check whether multiple time tags exist.
	int32_t read_time(std::string line);

	// Read content from a single line, if no time tag found at head, this will return blank string.
	std::string read_content(std::string line);

	// Read offset of a lyric vector, return 0 if not defined
	int32_t read_offset(std::vector<std::string>);
}
