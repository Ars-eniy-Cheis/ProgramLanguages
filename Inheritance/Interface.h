#pragma once
#include "Table.h"
#include "CompTable.h"
#include "CompTableWithPC.h"


using namespace std;

class Interface
{
public:
	int Run();
	void MENU();
	void Show_CompTableWithPC(CompTableWithPC CTWP);
	void Enter_CompTableWithPC(CompTableWithPC &CTWP);
};

