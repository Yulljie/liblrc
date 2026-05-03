#include <algorithm>
#include "lyric.h"

Lyric::Lyric();

uint32_t Lyric::size() const {
	return lines.size();
}

int32_t Lyric::get_time(int32_t index) const {
	assert(index < lines.size() && "Index out of bound!");
	return lines[index].time;
}

int32_t Lyric::get_index(int32_t ms) const {
	if (lines.empty()) return -1;

	auto next = std::upper_bound(lines.begin(), lines.end(), ms, [](int32_t t, const line& l) {return t < l.time;});
	return std::distance(lines.begin(), next) - 1;
}

const std::string& Lyric::get_line_by_index(int32_t index) const {
	assert(index < lines.size() && "Index out of bound!");
	return lines[index].content;
}

const std::string& Lyric::get_line_by_time(int32_t ms) const {
	int32_t index = get_index(ms);
	return (index != -1) ? get_line_by_index(index) : EMPTY_STRING;
}

int32_t Lyric::offset(int32_t ms) {
	if (lines.empty()) return 1;
	for (uint32_t i = 0; i < lines.size(); i++) lines[i].time += ms;
	return 0;
}

int32_t Lyric::add(int32_t time, std::string content);

int32_t Lyric::del(int32_t index);
