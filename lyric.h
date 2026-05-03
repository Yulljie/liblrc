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
			std::string content;
		};

		std::vector<line> lines;
		
		// For err use
		static const std::string EMPTY_STRING;

	public:
		// Create new Lyric 
		Lyric();
        
		// Return amount of saved lines
		size_t size() const;

		// Basic feature, DO NOT pass index larger than count() - 1 !!!
		int32_t get_time(size_t index) const;

		// Basic feature, return -1 if failed
		int32_t get_index(int32_t ms) const;

		// Basic feature. Return blank string if nothing found. DO NOT pass index larger than count() - 1 !!!
		const std::string& get_line_by_index(size_t index) const;

		// Basic feature. Return blank string if nothing found.
		const std::string& get_line_by_time(int32_t ms) const;

		// return 0 if nothing bad, 1 if failed, 2 if negative time appears
		int32_t offset(int32_t ms);
		
		// Add line to a Lyric, liblrc will automatically sort 
		int32_t add(int32_t time, std::string content);

		// Delete line from a Lyric by index
		int32_t del(size_t index);
        
};

#endif
