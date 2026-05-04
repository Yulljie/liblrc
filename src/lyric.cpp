#include <algorithm>
#include <cassert>
#include "lyric.h"

Lyric::Lyric() = default;

uint32_t Lyric::size() const {
	return lines.size();
}

int32_t Lyric::get_time(int32_t index) const {
	assert(index < lines.size() && "Index out of bound!");
	return lines[index].time;
}

int32_t Lyric::get_index(int32_t ms) const {
	if (!m_is_sorted || lines.empty()) return -1;
	
	auto next = std::upper_bound(lines.begin(), lines.end(), ms, [](int32_t t, const line& l) {return t < l.time;});
	return std::distance(lines.begin(), next) - 1;
}

const std::string& Lyric::get_line_by_index(int32_t index) const {
	return (index >= 0 && index < size()) ? lines[index].content : EMPTY_STRING;
}

const std::string& Lyric::get_line_by_time(int32_t ms) const {
	return get_line_by_index(get_index(ms));
}

void Lyric::offset(int32_t ms) {
	for (uint32_t i = 0; i < lines.size(); i++) lines[i].time += ms;
}

int32_t Lyric::add(int32_t time, std::string content) {
	lines.push_back({time, std::move(content)});
	m_is_sorted = false;
	return 0;
}

int32_t Lyric::del(int32_t index) {
	if (static_cast<uint32_t>(index) >= lines.size()) return -1;
	lines.erase(lines.begin() + index);
	return 0;
}

int32_t Lyric::sort() {
	if (m_is_sorted || lines.size() < 2) return 0;
	std::sort(lines.begin(), lines.end(), [](const line& a, const line& b){return a.time < b.time;});
	m_is_sorted = true;
	return 0;
}

void Lyric::force_sorted() {
	m_is_sorted = true;
}
