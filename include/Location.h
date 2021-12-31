#pragma once

struct Location {

	int m_row;
	int m_col;
};

bool operator==(const Location& a, const Location& b);