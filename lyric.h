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
		
		bool m_is_sorted = true;
	public:
		// Create/Initialize a new Lyric container
		Lyric();
        
		// Return amount of saved lines
		uint32_t size() const;

		// Basic feature, this will NOT check m_is_sorted, DO NOT pass index larger than count() - 1 !!!
		int32_t get_time(int32_t index) const;

		// Basic feature, return -1 if failed, this will check m_is_sorted.
		int32_t get_index(int32_t ms) const;

		// Basic feature, this will NOT check m_is_sorted(), this will return EMPTY_STRING if invalid index passed (Because the line itself could be empty, check the boundary yourself!!!)
		const std::string& get_line_by_index(int32_t index) const;

		// Basic feature, this is implemented as get_line_by_index(get_index(ms)).
		const std::string& get_line_by_time(int32_t ms) const;

		// Set offset to all lines. this will not err, ig. This will NOT modify m_is_sorted.
		void offset(int32_t ms);
		
		// Add line to a Lyric, liblrc will not automatically sort, this will set m_is_sorted to false
		int32_t add(int32_t time, std::string content);

		// Delete line from a Lyric by index, this will not modify m_is_sorted.
		int32_t del(int32_t index);
		
		// Sort lyrics by time, return 0 if nothing bad, -1 if failed. This will set m_is_sorted to true if nothing bad.
		int32_t sort();

		// !!!DANGEROUS!!! Set m_is_sorted to true, without doing anything.
		void force_sorted();
        
};

#endif
