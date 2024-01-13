#include <GL/glut.h>
#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Shape.h"
#include "Ellipse.h"
#include "Parabola.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Menu.h"
#include "Painter.h"
#include "EquiPolygon.h"
#include "Right_Equal_Triangle.h"
#include "Arrow.h"
#include "Star.h"
#include "Subtract.h"
#include "Plus.h"
#include "Multiply.h"
#include "Divide.h"
#include <Windows.h>
using namespace std;

Menu* MENU = NULL;
Painter* PAINTER = NULL;
RGBColor B_Color = { 0, 0, 0 };

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);  // Background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WIDTH, HEIGHT, 0.0);
}

void clearScr() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
}


void MouseToColor(int button, int state, int x, int y) {
    cout << "Mouse to Color is called" << endl;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        RGBColor curColor = MENU->getCurColor();
        cout << "Left received\n";
        if (curColor.r != 255 || curColor.b != 255 || curColor.g != 255) {
            cout << "Is coloring" << endl;
            //Painter* p = new Painter(HEIGHT, WIDTH);
            PAINTER->setColor(curColor, B_Color);
            PAINTER->BoundaryFill(x, y);
        }
    }
    cout << "Finish coloring" << endl;
}


void display() {
    cout << "display is called" << endl;
    if (MENU->isDrawing == false) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 0.0);
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Lab 03");

    init();

    MENU = Menu::getInstance();
    PAINTER = Painter::getInstance();
   
    glutMouseFunc(MouseToColor);
    glutDisplayFunc(display);

    glutMainLoop();
   

    delete MENU;
    delete PAINTER;
    return 0;
}

/*Hàm để trong function glutDisplayFunc là callback bởi vì: nó sẽ liên tục được gọi lại ngay sau khi có 1 sự kiện nào đó đến với màn hình.
    - Callback này sẽ đc gọi ngay khi chạy chtrinh lần đầu để mở cửa sổ.
    - Nếu ta tạo sự kiện để mở menu (click chuột trái, phải,...) thì sẽ không làm gọi lại callback.
    - Ngoài ra khi ta làm bất kỳ sự kiện nào lên cửa sổ:
        + Nếu có hàm để xử lý sự kiện đó (như callback đặt trong glutMouseFunc) thì hàm để xử lý sự kiện này sẽ đc chạy xong hoàn thành
          thì hàm callback trong display này sẽ đc gọi lại.
        + Nếu không có hàm nào để xử lý sự kiện đó, thì hàm callback trong display sẽ được gọi lại ngay.
*/