#ifndef NamespaceH
#define NamespaceH

namespace bg
{
	const std::string GAME_NAME = "Ballistic Game";

	const std::string file_images = "C:\\Users\\user\\Documents\\CourseWork\\BallisticGame\\Debug\\Pictures\\";
	const std::string backgrd_menu1 = "Catapault_backgr.jpg";
	const std::string backgrd_menu2 = "catapult_bck.jpg";
	const std::string file_catapult = "catapult.png";
	const std::string file_stone = "stone.png";
	const std::string file_backgrd = "high_mountain.png";

	const std::string file_fonts = "C:\\Users\\user\\Documents\\CourseWork\\BallisticGame\\BallisticGame\\";
	const std::string file_font_word = "BERNIER.ttf";
	const std::string file_font_vict = "Casanova.ttf";
	const std::string file_font_menu1 = "Carmen.ttf";
	const std::string file_font_menu2 = "Usual.ttf";

	const std::string STR_ANGLE = "Angle: 0";
	const std::string STR_SPEED = "Speed: 0";
	const std::string STR_MASS = "Stone mass: 30";
	const std::string STR_HEALTH = "Health: 100";
	const std::string STR_VICT = "Victory!";
	
	const std::string RULES = "���� ���������� �� ���� �������. ������ ����� �� �������.\n� ������������ ������ ���� �����������"
		" ���������� ������ ������\n30 ��, 3 ����� ������ 50 �� � ���� - 80��. ��������� ����� ������\n30 �� �������� 30 ������"
		" � ����������, 50 �� - 50 ������,\n80 �� - 80 ������. �������� �����, ������� ������� ��� �����\n������ ���������.";
	
	const std::string CONTROL = "R - ���������� ���� ��� ������� �����, Q - ����������.\n"
		"X - ���������� ��������� �������� �����, Z - ����������.\n1 - ���������� ����� ����� 30 ��, 2 - 50 ��, 3 - 80 ��\n"
		"W (����������) - ������ ����� 1-�� ����������,\nUp (����������) - ������ ����� 2-�� ����������.\n";

	const int MASS1 = 30;
	const int MASS2 = 50;
	const int MASS3 = 80;
	const int HP = 100;

	const unsigned int W = 1200;
	const unsigned int H = 780;

	const double PI = 3.14159265;
	const double G = 9.81;

	const double X_F_CT = 259.0;
	const double Y_F_CT = 12.0;
	const double X_F_BCT = 139.0;
	const double Y_F_BCT = 118.0;

	const double X_S_CT = 264.0;
	const double Y_S_CT = 12.0;
	const double X_S_BCT = 404.0;
	const double Y_S_BCT = 118.0;

	const double W_CT = 126.0;
	const double H_CT = 93.0;
	const double W_BCT = 106.0;
	const double H_BCT = 112.0;

	const double S_CT_CR = 560.0;
	const double SB_CT_CR = 541.0;

	const double XF_ST = 19.0;
	const double YF_ST = 17.0;
	const double X_ST1 = 97.0;
	const double X_ST2 = 1075.0;
	const double Y_ST = 560.0;

	const double X_BACKGRD = 800.0;
	const double Y_BACKGRD = 600.0;
}

#endif