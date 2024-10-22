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
    name = General::format_string(name);
    mail = General::format_string(mail);
}
