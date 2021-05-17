#pragma once
#include "framework.h"

#define PADDING 10

struct Button {
	LPCWSTR text;
	RECT rect;
	void  (*callback)(void);

public:
	void init(LPCWSTR text, int x, int y, void (*cb)(void)) {
		this->text = text;
		this->callback = cb;

		HDC hDC = GetDC(NULL);
		RECT r = { 0, 0, 0, 0 };
		DrawText(hDC, text, (int)wcslen(text), &r, DT_CALCRECT);
		rect.left = x;
		rect.top = y;
		rect.right = x + r.right + (2 * PADDING);
		rect.bottom = y + r.bottom + (2 * PADDING);
	}

	void draw(HDC hdc, HPEN hpen) {
		SelectObject(hdc, hpen);
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
		TextOut(
			hdc,
			rect.left + PADDING,
			rect.top + PADDING,
			text,
			(int)wcslen(text)
		);
	}
};


