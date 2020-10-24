#include "detail.h"

Detail::Detail(string context, bool cleared)
{
	this->context = context;
	this->cleared = cleared;
}

void Detail::setContext(string context) { this->context = context; }
void Detail::setCleared(bool cleared) { this->cleared = cleared; }
string Detail::getContext() { return context; }
bool Detail::is_Cleared() { return cleared; }