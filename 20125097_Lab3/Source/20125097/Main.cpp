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
#include "MenuLab04.h"
#include "Transformer.h"
#include "Polygon.h"
using namespace std;

Menu* MENU = NULL;
Painter* PAINTER = NULL;
MenuLab04* MENU04 = NULL;
Transformer* TRANSFORMER = NULL;
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


//////////////////////////////////////// Lab 04 //////////////////////////////////////////

void mouse_func(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (MENU04->getCurrentShape()) {
            if (MENU04->getShapeType() == -1 && MENU04->getCurrentShape()->getIsTransform()) {
                cout << "Handle click called" << endl;
                clearScr();
                MENU04->setCurrentShape(-1);
            }

            MENU04->getCurrentShape()->setStart(x, y);

            // Chấm điểm tiếp theo cho vẽ any polygon
            if (MENU04->getCurrentShape()->getPoints().size() >= 2)
                glutPostRedisplay();
        }
    }
    
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        cout << "Right down" << endl;
        if (MENU04->getShapeType() == -1 && MENU04->getCurrentShape()) {
            MENU04->getCurrentShape()->setFinish();
            MENU04->getCurrentShape()->setStart(x, y);
            glutPostRedisplay();
        }
    }
   
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        // Xử lý cho vẽ any polygon
        if (MENU04->getCurrentShape() && MENU04->getShapeType() == -1) {
            if (MENU04->getCurrentShape()->getPoints().size() == 2)
                MENU04->getCurrentShape()->clearPoints();
            else
                MENU04->getCurrentShape()->popPoint();
        }
    }
    
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        cout << "Right up" << endl;
        if (MENU04->getShapeType() == -1 && MENU04->getCurrentShape())
            MENU04->getCurrentShape()->setStartTransform();
    }
}


void motion(int x, int y) {
    if (MENU04->getCurrentShape()) {
        MENU04->getCurrentShape()->clearPoints();
        MENU04->getCurrentShape()->setEnd(x, y);

        glutPostRedisplay();
    }
}


void handleKeyboard(unsigned char key, int x, int y) {
    if (!MENU04->getCurrentShape())
        return;

    vector<vector<float>> points = MENU04->getCurrentShape()->getPoints();

    if (points.empty())
        return;

    if (toupper(key) == 'L' || toupper(key) == 'R') {
        MENU04->getCurrentShape()->setStartTransform();
        TRANSFORMER->transform(points, ROTATE, key);
    }

    else if (key == '+' || key == '-') {
        MENU04->getCurrentShape()->setStartTransform();
        TRANSFORMER->transform(points, SCALE, key);
    }

    MENU04->getCurrentShape()->updatePoints(points);

    glutPostRedisplay();
}


void handleSpecialKey(int key, int x, int y) {
    if (!MENU04->getCurrentShape())
        return;

    vector<vector<float>> points = MENU04->getCurrentShape()->getPoints();

    if (points.empty())
        return;

    if (key == GLUT_KEY_UP ||
        key == GLUT_KEY_DOWN ||
        key == GLUT_KEY_LEFT ||
        key == GLUT_KEY_RIGHT) {

        MENU04->getCurrentShape()->setStartTransform();
        TRANSFORMER->transform(points, TRANSLATE, key);
        MENU04->getCurrentShape()->updatePoints(points);
        glutPostRedisplay();
    }
}


void displayLab04() {
    cout << "Display called" << endl;
    clearScr();

    if (MENU04->getCurrentShape())
        MENU04->getCurrentShape()->drawSE();
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
    MENU04 = MenuLab04::getInstance();
    TRANSFORMER = Transformer::getInstance();

    glutMouseFunc(mouse_func);
    glutMotionFunc(motion);
    glutKeyboardFunc(handleKeyboard);
    glutSpecialFunc(handleSpecialKey);
    glutDisplayFunc(displayLab04);

    glutMainLoop();
    
    MenuLab04::resetInstance();
    delete MENU;
    delete PAINTER;
    delete TRANSFORMER;
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

/*
 * Code của mình có dùng hàm glutPostRedisplay() ở các chỗ, thì sẽ chạy là:
 * Cứ mỗi khi chuột di chuyển thì vẽ lại (cứ motion xong thì display lại), khi có glut up thì hàm mouse đc gọi.
*/