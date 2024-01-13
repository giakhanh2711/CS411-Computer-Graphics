//#include <GL/glut.h>
//#include <iostream>
//#include <chrono>
//#include <fstream>
//#include <string>
//#include <sstream>
//#include <vector>
//
//#include "Shape.h"
//#include "Ellipse.h"
//#include "Parabola.h"
//#include "Line.h"
//#include "Circle.h"
//#include "Rectangle.h"
//#include "Square.h"
//#include "Menu.h"
//#include "Painter.h"
//#include "EquiPolygon.h"
//#include "Right_Equal_Triangle.h"
//#include "Arrow.h"
//#include "Star.h"
//#include "Subtract.h"
//#include "Plus.h"
//#include "Multiply.h"
//#include "Divide.h"
//#include <Windows.h>
//
//using namespace std::chrono;
//using namespace std;
//
//void init()
//{
//    glClearColor(1.0, 1.0, 1.0, 0.0);  // Background color
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, WIDTH, HEIGHT, 0.0);
//}
//
//
//void renderScene()
//{ 
//    ifstream fileData;
//    fileData.open("Input.txt");
//    if (!fileData.is_open()) {
//        cout << "Can not open file";
//    }
//    else {
//        string s;
//        string number;
//
//        while (getline(fileData, s)) {
//            istringstream ss(s);
//            vector<int> params;
//            Shape* object = NULL;
//            string objectName;
//
//            while (ss >> number)
//                params.push_back(stoi(number));
//
//            switch (params[0]) {
//            case 0:
//                object = new Line(params[1], params[2], params[3], params[4], params[0]);
//                objectName = "line DDA";
//                break;
//            case 1:
//                object = new Line(params[1], params[2], params[3], params[4], params[0]);
//                objectName = "line Bresenham";
//                break;
//            case 2:
//                object = new Circle(params[1], params[2], params[3]);
//                objectName = "Circle";
//                break;
//            case 3:
//                object = new Ellipsee(params[1], params[2], params[3], params[4]);
//                objectName = "Ellipse";
//                break;
//            case 4:
//                object = new Parabola(params[1], params[2], params[3]);
//                objectName = "Parabola";
//                break;
//            case 5:
//                //Shape * object = new Hyperbola(params[1], params[2], params[3], params[4]);
//                objectName = "Hyperbola";
//                break;
//            }
//
//            float totalIm = 0, totalGL = 0;
//            for (int i = 0; i < 10; ++i) {
//                glClear(GL_COLOR_BUFFER_BIT);  // Clear buffer to remove the last drawing from window
//                glColor3f(1.0, 0.0, 0.0);
//
//                // DRAW BY IMPLEMENTATION
//                auto start = high_resolution_clock::now();
//                object->draw();
//                glFlush();
//                auto stop = high_resolution_clock::now();
//                auto duration = duration_cast<microseconds>(stop - start);
//                totalIm += duration.count();
//
//                if (params[0] != 3) {
//                    // DRAW BY OPENGL
//                    glClear(GL_COLOR_BUFFER_BIT);  // Clear buffer to remove the last drawing from window
//                    glColor3f(1.0, 0.0, 0.0);
//
//                    start = high_resolution_clock::now();
//                    object->drawByOpenGL();
//                    glFlush();
//                    stop = high_resolution_clock::now();
//                    duration = duration_cast<microseconds>(stop - start);
//                    totalGL += duration.count();
//                }
//            }
//
//            delete object;
//
//            cout << "Execution time of " << objectName << " by implementation is: " << (totalIm / 10.0) / 1000.0 << " milliseconds" << endl;
//            cout << "Execution time of " << objectName << " by OpenGL function is: " << (totalGL / 10.0) / 1000.0 << " milliseconds" << endl;
//            cout << endl;
//
//            Sleep(4000);
//        }
//        fileData.close();
//
//        cout << endl << "Already read all input file." << endl;
//    }
//}
//
//
//void displayWindow() {
//   /* glClear(GL_COLOR_BUFFER_BIT);
//    Menu* m = new Menu();
//    m->createMenu();
//
//    delete m;*/
//}
//
//RGBColor B_Color = { 0,0,0 };
//RGBColor F_Color = { 255,105,180 };
//
//void drawRec() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0.0, 0.0, 1.0);
//    Shape* s = new Rectanglee(100, 100, 100, 70);
//    s->draw();
//
//    delete s;
//}
//
//
//int xS = 100, xF = 400, yS = 200, yF = 500;
//
//void clearScr(){
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0.0, 0.0, 0.0);
//}
//
//void drawTriangle() {
//    clearScr();
//    glPointSize(5.0);
//    glBegin(GL_POINTS);
//    glVertex2i(500, 500);
//    glEnd();
//    glFlush();
//    glColor3f(1.0, 0.0, 0.0);
//    Shape* s = new Right_Equal_Triangle(500, 500, 200);
//    s->draw();
//
//    delete s;
//}
//
//void drawArrow() {
//    clearScr();
//    Shape* s = new Arrow(500, 100, 900, 350);
//    s->draw();
//
//    delete s;
//}
//
//void drawPoly() {
//    clearScr();
//    Shape* s = new EquiPolygon(500, 300, 4, 50);
//    s->draw();
//
//    delete s;
//}
//
//void drawStar() {
//    clearScr();
//    Shape* s = new Star(500, 300);
//    s->draw();
//
//    delete s;
//}
//
//void drawSubtract() {
//    clearScr();
//    Shape* s = new Subtract(300, 300, 300);
//    s->draw();
//
//    delete s;
//}
//
//void drawPlus() {
//    clearScr();
//    Shape* s = new Plus(500, 300, 200);
//    s->draw();
//
//    delete s;
//}
//
//
//void drawMul() {
//    clearScr();
//    Shape* s = new Multiply(500, 300, 200);
//    s->draw();
//
//    delete s;
//}
//
//void drawDivide() {
//    clearScr();
//    Shape* s = new Divide(200, 300, 500);
//    s->draw();
//
//    delete s;
//}
//
