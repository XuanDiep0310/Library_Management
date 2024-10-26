#include "People.h"

People::People()
{
    //ctor
}

People::~People()
{
    //dtor
}
void People::format()
{
    name = General::format(name);
    mail = General::format(mail);
}
