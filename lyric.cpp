#include "lyric.h"

Lyric::Lyric();

size_t Lyric::size() const {
	return lines.size();
}

int32_t Lyric::get_time(size_t index) const {
	assert(index < lines.size() && "Index out of bound!");
	return lines[index].time;
}

size_t Lyric::get_index(int32_t ms) const {}

const std::string& Lyric::get_line_by_index(size_t index) const {
	assert(index < lines.size() && "Index out of bound!");
	return lines[index].content;
}

const std::string& Lyric::get_line_by_time(int32_t ms) const {
	size_t index = get_index(ms);
	return (index != -1) ? get_line_by_index(index) : EMPTY_STRING;
}

int32_t Lyric::offset(int32_t ms);

int32_t Lyric::add(int32_t time, std::string content);

int32_t Lyric::del(size_t index);
