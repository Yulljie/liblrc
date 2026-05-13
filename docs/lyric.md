# lyric.h

This header defines `Lyric` class and its interfaces. The `Lyric` class is used to store, manage and retrieving parsed lyric data. 

Uesually, this is not strongly depend on the parser header provided by liblrc. You can use your own parser implementation together with this header.

## Structure

A `Lyric` object is defined as below: 

``` cpp
class Lyric {
	private:
		struct line {
			int32_t time;
			std::string content;
		};
		std::vector<line> lines;
		static const std::string EMPTY_STRING;
		bool m_is_sorted = true;
}
```

`line`: Container for single line
  * `time`: Time at when the line should appear. This could be negative, but a newly parsed line shouldn't be. The unit is not strictly limited, and in this document we use `ms` as unit.
  * `content`: Content of the line itself.

`lines`: Vector `lines` stores line in one timeline (usually a song).

`EMPTY_STRING`: Some interfaces may return this if error occured.

`m_is_sorted`: Used to mark if `lines` is sorted. Some interfaces may modify or check this.

## Interfaces

### Initialize

`Lyric()`Create a `Lyric` object, it does't need any initial parameters.
```cpp
Lyric::Lyric();
// Usage:
Lyric lrc;
```

### Modify

`add()`: Add a line to the end of a `Lyric` object, No order required. This will set `m_is_sorted` to `false` and return `0` usually.
```cpp
int32_t Lyric::add(int32_t time, std::string content);
// Usage:
lrc.add(5000, "Hello world");
```

`del()`: Delete one line from a `Lyric` object by index, no order required. This will return `-1` if error occured, `0` if nothing bad.
```cpp
int32_t Lyric::del(int32_t index);
// Usage:
lrc.del(1);
```

`offset()`: Apply offset to all lines. This may set time of several lines to negative, such behavior is accepted.
```cpp
void Lyric::offset(int32_t ms);
// Usage:
lrc.offset(-1000);
```

`sort()`: Sort all lines in a `Lyric` object by time and set `m_is_sorted` to `true`, return `0` if nothing bad. This will not check `m_is_sorted`.
```cpp
int32_t Lyric::sort();
// Usage:
lrc.sort();
```

`force_sorted()`: DANGEROUS!!! Set `m_is_sorted` to `true` without doing anything.
```cpp
void Lyric::force_sorted();
// Usage:
lrc.force_sorted();
```

### Query

`size()`: Return the size of the vector `lines`. This can be used for boundary check.
```cpp
uint32_t Lyric::vector();
// Usage:
lrc.size();
```

`get_time()`: Return `time` by index. This will not check `m_is_sorted`. Also, check if the index is valid before invoke this, a invalid index will cause undefined behavior.
```cpp
int32_t Lyric::get_time(int32_t index) const;
// Usage:
lrc.get_time(2);
```

`get_index()`: Return the index by time. This will check `m_is_sorted`. When `m_is_sorted` is `false`, `lines` is empty or the given time is earlier than the first line (index0), this will return `-1`.
```cpp
int32_t Lyric::get_index(int32_t ms);
// Usage:
lrc.get_index(5000);
```

`get_line_by_index()`: Return the line by index. This will not check `m_is_sorted`. This will return a empty string `""` if a invalid index given.
```cpp
const std::string& get_line_by_index(int32_t index) const;
// Usage:
lrc.get_line_by_index(2);
```

`get_line_by_time()`: Return the line by time. This is implemented as `get_line_by_index(get_index())`, return empty string `""` if invalid time given.
```cpp
const std::string& get_line_by_time(int32_t ms) const;
// Usage:
get_line_by_time(5000);
```




