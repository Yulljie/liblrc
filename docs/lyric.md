# lyric.h

This header defines Lyric class and its interfaces. The Lyric class is used to store, manage and retrieving parsed lyric data. 

Uesually, this is not strongly depend on the parser header provided by liblrc. You can use your own parser implementation together with this header.

## Structure

A Lyric object is defined as below: 
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
  * `time`: Time at when the line should appear. This could be negative, but a newly parsed line shouldn't be.
  * `content`: Content of the line itself.

`lines`: Vector `lines` stores line in one timeline (usually a song).
`EMPTY_STRING`: Some interfaces may return this if error occured.
`m_is_sorted`: Used to mark if `lines` is sorted. Some interfaces may modify or check this.