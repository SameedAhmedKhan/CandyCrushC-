#include <windows.h>
#include <windowsx.h>



void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}


void myLine(int x1, int y1, int x2, int y2, int color) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(color, color, color)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}

void myLine2(int x1, int y1, int x2, int y2, int R, int G, int B) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 20, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);


}

void myLine3(int x1, int y1, int x2, int y2, int R, int G, int B) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 5, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}
// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool isCursorKeyPressed(int& whickKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whickKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whickKey = 2;		// 2 if up key is pressed
		return true;
	}

	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whickKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whickKey = 4;   // 4 if down key is pressed
		return true;
	}
	return false;
}



//void myTriangle(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
//{
//	HWND console_handle = GetConsoleWindow();
//	HDC device_context = GetDC(console_handle);
//
//	//change the color by changing the values in RGB (from 0-255)
//	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
//	SelectObject(device_context, pen);
//	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB)); //Fill color i*s passed as parameter to the function!!!
//
//	SelectObject(device_context, brush);
//
//	Rectangle(device_context, (x1+x2)/2, y1, y2);
//	ReleaseDC(console_handle, device_context);
//	DeleteObject(pen);
//	DeleteObject(brush);
//}

void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


}

void shape2(int x1, int y1, int x2, int y2,int R,int G,int B,int FR,int FG,int FB) 
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

	HPEN hpen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	HPEN hOldPen = SelectPen(device_context, hpen);

	HBRUSH hBrush = CreateSolidBrush(RGB(FR, FG, FB));
	HBRUSH hOldBrush = SelectBrush(device_context, hBrush);

	int center=(x1+x2)/2,center1=(y1+y1)/2,cen=(x2-x1)/4,cen1=(y2-y1)/4;
    //change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.

    SelectObject(device_context,hpen);
	MoveToEx(device_context,center,y1,NULL);
    LineTo(device_context,x1,y1+ cen1);
	LineTo(device_context,x1+cen,y2);
	LineTo(device_context,x2-cen,y2);
	LineTo(device_context,x2,y1+cen1);
	LineTo(device_context,center,y1);
	
	FloodFill(device_context,x1,y1,(RGB(R,G,B)));
	
	ReleaseDC(console_handle, device_context);  



	SelectBrush(device_context, hOldBrush);
	DeleteObject(hBrush);

	SelectPen(device_context, hOldPen);
	DeleteObject(hpen);

	}


void Polygon(int x1, int y1, int x2, int y2,int R,int G,int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);

	HBRUSH brush = CreateSolidBrush(RGB(FR, FG, FB));

	SelectObject(device_context, brush);
	
	POINT vertices[] = { {(x1+x2)/2, y1}, {x2, y2}, {x1, y2} };
	Polygon(device_context, vertices, sizeof(vertices) / sizeof(vertices[0]));
	
	ReleaseDC(console_handle, device_context);

	DeleteObject(brush);
	DeleteObject(pen);
}

void Poly2(int x1, int y1, int x2, int y2,int R,int G,int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);

	HBRUSH brush = CreateSolidBrush(RGB(FR, FG, FB));

	SelectObject(device_context, brush);
	
	POINT vertices[] = { {(x1), y1}, {x2, y2}, {x1, y2}, {x2,y1} };
	Polygon(device_context, vertices, sizeof(vertices) / sizeof(vertices[0]));
	
	ReleaseDC(console_handle, device_context);

	DeleteObject(brush);
	DeleteObject(pen);
}

void Poly3(int x1, int y1, int x2, int y2,int R,int G,int B, int FR, int FG, int FB)
{

	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);

	HBRUSH brush = CreateSolidBrush(RGB(FR, FG, FB));

	SelectObject(device_context, brush);

	POINT vertices[] = { {(x1+x2)/2, y1}, {x2, (y1+y2)/2}, {(x1+x2)/2, y2}, {x1,(y1+y2)/2} };
	Polygon(device_context, vertices, sizeof(vertices) / sizeof(vertices[0]));
	ReleaseDC(console_handle, device_context);
	DeleteObject(brush);
	DeleteObject(pen);
}


void myRect(int x1, int x2, int y1, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB)); //Fill color is passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, x2, y1, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}


void myRect2(int x1, int x2, int y1, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 5, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB)); //Fill color is passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, x2, y1, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}


void myTriangle(int x1, int y1, int x2, int y2,int R, int G, int B,int FR,int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID, 2, RGB(R,G,B)); 
	SelectObject(device_context,pen);

	HBRUSH brush = ::CreateSolidBrush(RGB(FR,FG,FB));
	SelectObject(device_context,brush);
	
	int center=(x1+x2)/2, centerY=(y1+y2)/2;
	
	
	FloodFill(device_context,center,centerY,(RGB(R,G,B)));
	ReleaseDC(console_handle, device_context);

	DeleteObject(pen);
	DeleteObject(brush);
}






void Digit1(int a)
{
		myLine3(100+a*1.25,100,100+a*1.25,150,255,0,0);
		myLine3(80+a*1.25,120,100+a*1.25,100,255,0,0);
		myLine3(80+a*1.25,150,110+a*1.25,150,255,0,0);
}
void Digit2(int a) //use three 3 integers if you want colored lines.
{
	myLine3(100+a,100,150+a,100,255,0,0);
	myLine3(150+a,100,150+a,125,255,0,0);
	myLine3(100+a,125,150+a,125,255,0,0);
	myLine3(100+a,125,100+a,150,255,0,0);
	myLine3(100+a,150,150+a,150,255,0,0);
}
void Digit3(int a) //use three 3 integers if you want colored lines.
{
	myLine3(100+a,100,150+a,100,255,0,0);
	myLine3(150+a,100,150+a,125,255,0,0);
	myLine3(100+a,125,150+a,125,255,0,0);
	myLine3(150+a,125,150+a,150,255,0,0);
	myLine3(100+a,150,150+a,150,255,0,0);
	
}
void Digit4(int a)
{
		myLine3(150+a,100,150+a,150,255,0,0);
		myLine3(100+a,125,150+a,125,255,0,0);
		myLine3(100+a,100,100+a,125,255,0,0);
}
void Digit5(int a)
{
	myLine3(100+a,100,150+a,100,255,0,0);
	myLine3(100+a,100,100+a,125,255,0,0);
	myLine3(100+a,125,150+a,125,255,00,0);
	myLine3(150+a,125,150+a,150,255,0,0);
	myLine3(100+a,150,150+a,150,255,0,0);
}
void Digit6(int a)
{
	myLine3(100+a,100,150+a,100,255,0,0);
	myLine3(100+a,100,100+a,125,255,0,0);
	myLine3(100+a,125,150+a,125,255,0,0);
	myLine3(150+a,125,150+a,150,255,0,0);
	myLine3(100+a,150,150+a,150,255,0,0);
	myLine3(100+a,125,100+a,150,255,0,0);
}
void Digit7(int a)
{
	myLine3(150+a,100,150+a,150,255,0,0);
	myLine3(100+a,100,150+a,100,255,0,0);
}
void Digit8(int a)
{
	myLine3(100+a,100,150+a,100,255,0,0);
	myLine3(100+a,100,100+a,125,255,0,0);
	myLine3(100+a,125,150+a,125,255,0,0);
	myLine3(150+a,125,150+a,150,255,0,0);
	myLine3(100+a,150,150+a,150,255,0,0);
	myLine3(100+a,125,100+a,150,255,0,0);
	myLine3(150+a,100,150+a,125,255,0,0);
}
void Digit9(int a)
{
	myLine3(100+a,100,150+a,100,255,0,0);
	myLine3(100+a,100,100+a,125,255,0,0);
	myLine3(100+a,125,150+a,125,255,0,0);
	myLine3(150+a,125,150+a,150,255,0,0);
	myLine3(100+a,150,150+a,150,255,0,0);
	
	myLine3(150+a,100,150+a,125,255,0,0);
}
void Digit0(int a)
{
	myRect2(100+a,100,155+a,150,255,0,0,0,0,0);
}

void Box ()
{
	myLine2(450,50,900,50,0,255,255);//--
	myLine2(450,450,900,450,0,255,255);//_
	myLine2(450,50,450,450,0,255,255);//|
	myLine2(900,50,900,450,0,255,255); //  |
}