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
		
		bool m_is_sorted = false;
	public:
		// Create/Initialize a new Lyric container
		Lyric();
        
		// Return amount of saved lines
		uint32_t size() const;

		// Basic feature, DO NOT pass index larger than count() - 1 !!!
		int32_t get_time(int32_t index) const;

		// Basic feature, return -1 if failed
		int32_t get_index(int32_t ms) const;

		// Basic feature. Return blank string if nothing found. DO NOT pass index larger than count() - 1 !!!
		const std::string& get_line_by_index(int32_t index) const;

		// Basic feature. Return blank string if nothing found.
		const std::string& get_line_by_time(int32_t ms) const;

		// return 0 if nothing bad, 1 if nothing changed (to a blank container), and nothing to err?
		int32_t offset(int32_t ms);
		
		// Add line to a Lyric, liblrc will not automatically sort 
		int32_t add(int32_t time, std::string content);

		// Delete line from a Lyric by index
		int32_t del(int32_t index);
		
		// Sort lyrics by time, return 0 if nothing bad, -1 if failed.
		int32_t sort();

		// Set is_sorted to true, without doing anything.
		void force_sorted();
        
};

#endif
