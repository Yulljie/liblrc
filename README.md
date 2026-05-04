# Liblrc

A WIP .lrc lyric parser library written in C++

## Progress

### Stage1: Core Engine (Completed)

Class Lyric is completed and usable, which means you can handle lyrics manually, include lyric.h to get started. Hooray~

### Stage2: .lrc Parser (WIP)

A parser for .lrc to Lyric will be implemented in this stage, WIP.

## Quick Start

```cpp
#include "lyric.h"

// The .lrc parser (in stage2) is WIP...Zzzzzzzzzzzz
// The parser is currently dreaming about regex and line endings.
// Check back later! 
// Currently we need ourselves to be the parser for demonstration!

Lyric lrc;
lrc.add(10000, "Hello World"); // Add lyric at 10s
lrc.add(15000, "ハローワールド");
lrc.add(5000, "你好，世界");


std::string text = lrc.get_line_by_index(2); // 你好，世界

lrc.sort(); // Previously not sorted

// Find line at 16s
int32_t idx = lrc.get_index(16000); // idx = 2
text = lrc.get_line_by_index(idx); // ハローワールド

// Simpler way to find line by time. Inplemented same as above
text = lrc.get_line_by_time(12000); // Hello World

```
