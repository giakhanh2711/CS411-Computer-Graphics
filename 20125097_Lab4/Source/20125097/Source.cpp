//#include<vector>
//using namespace std;
//
//void motion(int x, int y) {
//    cout << "Motion called" << endl;
//
//    if (MENU04->getCurrentShape() != NULL) {
//        MENU04->getCurrentShape()->clearPoints();
//        MENU04->getCurrentShape()->setEnd(x, y);
//        glutPostRedisplay();
//    }
//}
//
//
//void mouse_func(int button, int state, int x, int y) {
//    cout << "Mouse called" << endl;
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//        if (MenuLab04::isChoose == false) {
//            if (preStatus == true) {
//                cout << "CLEARRRRRRRRRRRRRRRRRRRRRRRRRRR" << endl;
//                MENU04->getCurrentShape()->clearPoints();
//            }
//
//            if (MENU04->getCurrentShape() && MENU04->getCurrentShape()->getPoints().size() >= 2) {
//                cout << " SIZEEEEEEEEEEEEE" << MENU04->getCurrentShape()->getPoints().size() << endl;
//                MENU04->getCurrentShape()->setEnd(x, y);
//                glutPostRedisplay();
//            }
//            else {
//                MENU04->setCurrentShape(-1);
//                MENU04->getCurrentShape()->setStart(x, y);
//            }
//        }
//        else {
//            MENU04->getCurrentShape()->setStart(x, y);
//        }
//    }
//    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
//        preStatus = MENU04->isChoose;
//        MENU04->isChoose = false;
//    }
//
//    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
//        if (MenuLab04::isChoose == false) {
//            preStatus = false;
//
//            if (MENU04->getCurrentShape()) {
//                MENU04->getCurrentShape()->setEnd(x, y);
//                MENU04->getCurrentShape()->drawSE();
//
//                float xS = MENU04->getCurrentShape()->getPoints()[0][0];
//                float yS = MENU04->getCurrentShape()->getPoints()[0][1];
//
//                MENU04->getCurrentShape()->setEnd(xS, yS);
//                MENU04->getCurrentShape()->drawSE();
//            }
//        }
//    }
//}
//
//void handleKeyboard(unsigned char key, int x, int y) {
//    vector<vector<float>> points;
//    if (MENU04->getCurrentShape())
//        points = MENU04->getCurrentShape()->getPoints();
//    if (points.empty())
//        return;
//
//    clearScr();
//    if (toupper(key) == 'L' || toupper(key) == 'R') {
//        TRANSFORMER->transform(points, ROTATE, key);
//    }
//    else if (key == '+' || key == '-') {
//        TRANSFORMER->transform(points, SCALE, key);
//    }
//
//    MENU04->getCurrentShape()->updatePoints(points);
//
//    glutPostRedisplay();
//}
//
//void handleSpecialKey(int key, int x, int y) {
//    vector<vector<float>> points;
//    if (MENU04->getCurrentShape())
//        points = MENU04->getCurrentShape()->getPoints();
//
//    if (points.empty()) {
//        return;
//    }
//
//    if (key == GLUT_KEY_UP || key == GLUT_KEY_DOWN
//        || key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT)
//        TRANSFORMER->transform(points, TRANSLATE, key);
//
//    MENU04->getCurrentShape()->updatePoints(points);
//
//    clearScr();
//    glutPostRedisplay();
//}
//
//
//void displayLab04() {
//    cout << "Display called" << endl;
//
//    clearScr();
//
//    if (MENU04->getCurrentShape()) {
//        MENU04->getCurrentShape()->drawSE();
//    }
//    else
//        cout << NULL << endl;
//
//}