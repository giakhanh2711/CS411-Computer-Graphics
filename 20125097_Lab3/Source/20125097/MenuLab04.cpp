#include "MenuLab04.h"

enum shape_types04 {
	TRIANGLE_RIGHT_ANGLE,
	TRIANGLE_EQUI,
	REC,
	SQUARE,
	FIVE_EQUI,
	SIX_EQUI,
	TRIANGLE,
	RIGHT_TRIANGLE,
	FIVE_POLY,
	SIX_POLY,
	DM,
};

string MENU_TITLE04[] = {
	"Right triangle",
	"Equilateral triangle",
	"Rectangle",
	"Square",
	"Equilateral pentagon",
	"Equilateral hexagon",
	"Triangle",
	"Right equal Triangle",
	"Pentagon",
	"Hexagon",
	"Diamond",
};

MenuLab04* MenuLab04::MENU04 = NULL;

MenuLab04* MenuToHandle;

void handleClick(int value) {
	cout << "Handle click called" << endl;
	MenuToHandle = MenuLab04::getInstance();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	MenuToHandle->setCurrentShape(value);
}


void MenuLab04::setCurrentShape(int value) {
	Shape* currentShape = NULL;
	switch (value) {
	case TRIANGLE_EQUI:
		currentShape = new EquiPolygon(0, 0, EQUAL);
		currentShape->setNumOfEdges(3);
		break;
	case RIGHT_TRIANGLE:
		currentShape = new Right_Equal_Triangle(0, 0, RIGHT_EQUAL);
		break;
	case TRIANGLE_RIGHT_ANGLE:
		currentShape = new Right_Equal_Triangle(0, 0, RIGHT);
		break;
	case TRIANGLE:
		currentShape = new EquiPolygon(0, 0, NORMAL);
		currentShape->setNumOfEdges(3);
		break;
	case FIVE_EQUI:
		currentShape = new EquiPolygon(0, 0, EQUAL);
		currentShape->setNumOfEdges(5);
		break;
	case FIVE_POLY:
		currentShape = new EquiPolygon(0, 0, NORMAL);
		currentShape->setNumOfEdges(5);
		break;
	case SIX_EQUI:
		currentShape = new EquiPolygon(0, 0, EQUAL);
		currentShape->setNumOfEdges(6);
		break;
	case SIX_POLY:
		currentShape = new EquiPolygon(0, 0, NORMAL);
		currentShape->setNumOfEdges(6);
		break;
	case REC:
		currentShape = new Rectanglee(0, 0);
		break;
	case SQUARE:
		currentShape = new Square(0, 0);
		break;
	case DM:
		currentShape = new EquiPolygon(0, 0, NORMAL);
		currentShape->setNumOfEdges(4);
		break;
	case -1:
		currentShape = new MyPolygon(0, 0);
		break;
	default:
		return;
	}

	shapeType = value;
	shapes.push_back(currentShape);
}

MenuLab04::MenuLab04() {
	int triangle = glutCreateMenu(handleClick);
	glutAddMenuEntry(MENU_TITLE04[TRIANGLE_EQUI].c_str(), TRIANGLE_EQUI);
	glutAddMenuEntry(MENU_TITLE04[RIGHT_TRIANGLE].c_str(), RIGHT_TRIANGLE);
	glutAddMenuEntry(MENU_TITLE04[TRIANGLE_RIGHT_ANGLE].c_str(), TRIANGLE_RIGHT_ANGLE);
	glutAddMenuEntry(MENU_TITLE04[TRIANGLE].c_str(), TRIANGLE);

	int fivePoly = glutCreateMenu(handleClick);
	glutAddMenuEntry(MENU_TITLE04[FIVE_EQUI].c_str(), FIVE_EQUI);
	glutAddMenuEntry(MENU_TITLE04[FIVE_POLY].c_str(), FIVE_POLY);

	int sixPoly = glutCreateMenu(handleClick);
	glutAddMenuEntry(MENU_TITLE04[SIX_EQUI].c_str(), SIX_EQUI);
	glutAddMenuEntry(MENU_TITLE04[SIX_POLY].c_str(), SIX_POLY);

	int mainMenu = glutCreateMenu(handleClick);
	glutAddSubMenu(MENU_TITLE04[TRIANGLE].c_str(), triangle);
	glutAddMenuEntry(MENU_TITLE04[REC].c_str(), REC);
	glutAddMenuEntry(MENU_TITLE04[SQUARE].c_str(), SQUARE);
	glutAddMenuEntry("Diamond", DM);
	glutAddSubMenu(MENU_TITLE04[FIVE_POLY].c_str(), fivePoly);
	glutAddSubMenu(MENU_TITLE04[SIX_POLY].c_str(), sixPoly);

	glutAddMenuEntry("Polygon", -1);

	glutAttachMenu(GLUT_MIDDLE_BUTTON);

	this->shapeType = -1;
}


MenuLab04* MenuLab04::getInstance() {
	if (MENU04 == NULL)
		MENU04 = new MenuLab04();

	return MENU04;
}

MenuLab04::~MenuLab04() {
	for (int i = 0; i < shapes.size(); ++i)
		if (shapes[i]) {
			delete shapes[i];
			shapes[i] = NULL;
		}

	shapes.clear();
}

Shape* MenuLab04::getCurrentShape() {
	if (!shapes.empty())
		return shapes[shapes.size() - 1];
	return NULL;
}

int MenuLab04::getShapeType() {
	return shapeType;
}


void MenuLab04::resetInstance() {
	if (MENU04) {
		delete MENU04;
		MENU04 = NULL;
	}
}


