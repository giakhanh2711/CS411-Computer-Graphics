#include "Menu.h"

enum shape_types {
	LINE,
	TRIANGLE_EQUI,
	TRIANGLE_RIGHT_ANGLE,
	REC,
	SQUARE,
	CIRCLE,
	ELLIPSE,
	FIVE_EQUI,
	SIX_EQUI,
	ARROW,
	STAR,
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	GREEN,
	RED,
	YELLOW
};

string MENU_TITLE[] = {
	"Duong thang",
	"Vuong can",
	"Deu",
	"Hinh chu nhat",
	"Hinh vuong",
	"Hinh tron",
	"Ellipse",
	"Ngu giac deu",
	"Luc giac deu",
	"Mui ten",
	"Ngoi sao",
	"Cong",
	"Tru",
	"Nhan",
	"Chia",
	"Xanh",
	"Do",
	"Vang"
};

struct Duongthang {
	int x1, y1, x2, y2;
}line = { 50, 20, 200, 100 };

struct VC {
	int xTop, yTop, edgeLength;
}vc = { 250, 70, 150 };

struct Deu {
	int xT, yT, numOfLength, edgeLength;
};
const struct Deu deu = { 450, 100, 3, 150 };
const struct Deu NGD = { 550, 250, 5, 100 };
const struct Deu LGD = { 800, 350, 6, 100 };

struct HCN {
	int xTL, yTL, w, h;
}hcn = { 650, 50, 200, 150 };

struct HV {
	int xTL, yTL, a;
}hv = { 900, 50, 50 };

struct HTron {
	int xT, yT, r;
}htron = { 50, 200, 50 };

struct Elip {
	int xT, yT, a, b;
}elip = { 250, 250, 100, 50 };

struct MuiTen {
	int length, width, xS, yS;
}muiten = { 200, 50, 300, 600 };

struct NgoiSao {
	int xT, yT;
}ngoisao = { 200, 400 };

struct Cong {
	int xT, yT, length1In4;
}cong = { 450, 350, 70 };

struct Tru {
	int xS, yS, length;
}tru = { 850, 500, 100 };

struct Nhan {
	int xT, yT, length1In4;
}nhan = { 500, 600, 100 };

struct Chia {
	int xS, yS, lengthHorizon;
}chia = { 800, 600, 100 };

/// <summary>
/// //////////////////////////////////////////////////////////////////////
/// </summary>

Menu* Menu::MENU = NULL;

Menu* MENU1 = NULL; // Used for function menu to called functions of Menu

Menu::Menu() {
	createMenu();
}

Menu* Menu::getInstance() {
	if (MENU == NULL)
		MENU = new Menu();
	return MENU;
}

Menu::~Menu() {
	for (Shape* shape : shapes)
		delete shape;
}

void menu(int a) {
	MENU1 = Menu::getInstance();
	MENU1->setCurrentShape(a);

	MENU1->isDrawing = true;

	MENU1->HandleAfterChoose();
	MENU1->draw();
}

void Menu::setCurrentShape(int a) {
	this->currentShape = a;
}

void Menu::createMenu() {
	int triangle = glutCreateMenu(menu);
	glutAddMenuEntry(MENU_TITLE[TRIANGLE_EQUI].c_str(), TRIANGLE_EQUI);
	glutAddMenuEntry(MENU_TITLE[TRIANGLE_RIGHT_ANGLE].c_str(), TRIANGLE_RIGHT_ANGLE);

	int quad = glutCreateMenu(menu);
	glutAddMenuEntry(MENU_TITLE[REC].c_str(), REC);
	glutAddMenuEntry(MENU_TITLE[SQUARE].c_str(), SQUARE);

	int oval = glutCreateMenu(menu);
	glutAddMenuEntry(MENU_TITLE[CIRCLE].c_str(), CIRCLE);
	glutAddMenuEntry(MENU_TITLE[ELLIPSE].c_str(), ELLIPSE);

	int polygon = glutCreateMenu(menu);
	glutAddMenuEntry(MENU_TITLE[FIVE_EQUI].c_str(), FIVE_EQUI);
	glutAddMenuEntry(MENU_TITLE[SIX_EQUI].c_str(), SIX_EQUI);

	int other = glutCreateMenu(menu);
	glutAddMenuEntry(MENU_TITLE[ARROW].c_str(), ARROW);
	glutAddMenuEntry(MENU_TITLE[STAR].c_str(), STAR);

	int sign = glutCreateMenu(menu);
	glutAddMenuEntry(MENU_TITLE[ADD].c_str(), ADD);
	glutAddMenuEntry(MENU_TITLE[SUBTRACT].c_str(), SUBTRACT);
	glutAddMenuEntry(MENU_TITLE[MULTIPLY].c_str(), MULTIPLY);
	glutAddMenuEntry(MENU_TITLE[DIVIDE].c_str(), DIVIDE);

	int color = glutCreateMenu(menu);
	glutAddMenuEntry(MENU_TITLE[GREEN].c_str(), GREEN);
	glutAddMenuEntry(MENU_TITLE[RED].c_str(), RED);
	glutAddMenuEntry(MENU_TITLE[YELLOW].c_str(), YELLOW);

	int chooseShape = glutCreateMenu(menu);

	int mainMenu = glutCreateMenu(menu);
	glutAddMenuEntry(MENU_TITLE[LINE].c_str(), LINE);
	glutAddSubMenu("Tam giac", triangle);
	glutAddSubMenu("Tu giac", quad);
	glutAddSubMenu("Oval", oval);
	glutAddSubMenu("Da giac deu", polygon);
	glutAddSubMenu("Hinh khac", other);
	glutAddSubMenu("Dau", sign);
	glutAddSubMenu("Color", color);
	glutAddMenuEntry("Chon hinh", chooseShape);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Menu::HandleAfterChoose() {
	Shape* shape = NULL;
	RGBColor color;

	switch (this->currentShape) {
	case LINE:
		shape = new Line(line.x1, line.y1, line.x2, line.y2, 0);
		break;
	case TRIANGLE_RIGHT_ANGLE:
		shape = new Right_Equal_Triangle(vc.xTop, vc.yTop, vc.edgeLength);
		break;
	case TRIANGLE_EQUI:
		shape = new EquiPolygon(deu.xT, deu.yT, deu.numOfLength, deu.edgeLength);
		break;
	case REC:
		shape = new Rectanglee(hcn.xTL, hcn.yTL, hcn.w, hcn.h);
		break;
	case SQUARE:
		shape = new Square(hv.xTL, hv.yTL, hv.a);
		break;
	case CIRCLE:
		shape = new Circle(htron.xT, htron.yT, htron.r);
		break;
	case ELLIPSE:
		shape = new Ellipsee(elip.xT, elip.yT, elip.a, elip.b);
		break;
	case FIVE_EQUI:
		shape = new EquiPolygon(NGD.xT, NGD.yT, NGD.numOfLength, NGD.edgeLength);
		break;
	case SIX_EQUI:
		shape = new EquiPolygon(LGD.xT, LGD.yT, LGD.numOfLength, LGD.edgeLength);
		break;
	case ARROW:
		shape = new Arrow(muiten.length, muiten.width, muiten.xS, muiten.yS);
		break;
	case STAR:
		shape = new Star(ngoisao.xT, ngoisao.yT);
		break;
	case ADD:
		shape = new Plus(cong.xT, cong.yT, cong.length1In4);
		break;
	case SUBTRACT:
		shape = new Subtract(tru.xS, tru.yS, tru.length);
		break;
	case MULTIPLY:
		shape = new Multiply(nhan.xT, nhan.yT, nhan.length1In4);
		break;
	case DIVIDE:
		shape = new Divide(chia.xS, chia.yS, chia.lengthHorizon);
		break;
	case GREEN:
		curColor = { 0, 204, 0 };
		break;
	case RED:
		curColor = { 255, 0, 0 };
		break;
	case YELLOW:
		curColor = { 255, 255, 0 };
		break;
	}

	if (this->currentShape >= 0 && this->currentShape <= 14) {
		shapes.push_back(shape);
	}
}

void Menu::draw() {
	for (int i = 0; i < shapes.size(); ++i) {
		shapes[i]->draw();
	}
}

RGBColor Menu::getCurColor() {
	return curColor;
}
