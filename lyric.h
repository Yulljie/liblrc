// filename: lyric.h

#ifndef LYRIC_H
#define LYRIC_H

#include <string>
#include <vector>

class Lyric {
	private:
		struct line {
			// offset() may cause negative time, thus not uint32_t
			int32_t time;
			uint32_t index;
			std::string content;
		}

		std::vector<line> lines;
		
		// For err use
		static const std::string EMPTY_STRING;

	public:
		// Create new Lyric 
		Lyric();

		// Basic feature, DO NOT pass index larger than size() - 1 !!!
		int32_t get_time(uint32_t index) const;

		// Basic feature, return -1 if failed
		int32_t get_index(int32_t int ms) const;

		// Basic feature. Return blank string if nothing found.
		std::string& get_line_by_index(uint32_t index);

		// Basic feature. Return blank string if nothing found.
		std::string& get_line_by_time(int32_t ms) const {
			int32_t index = get_index(ms);
			return (index != -1) ? get_line_by_index(index) : EMPTY_STRING;
		}

		// return 0 if nothing bad, 1 if failed, 2 if negative time appears
		int32_t offset(int32_t ms);
		
		// Add line to a Lyric, liblrc will automatically sort 
		add(int32_t time, std::string content);

		// Delete line from a Lyric by index
		del(uint32_t index);

		// Return amount of saved lines
		uint32_t size() const;
};

#endif
