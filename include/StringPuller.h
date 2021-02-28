#ifndef TRANSLATHORG_STRING_PULLER_H
#define TRANSLATHORG_STRING_PULLER_H

#include <string>
#include <rapidjson/document.h>

namespace th
{

class StringPuller
{
public:
    const std::string GetStringByName(const char *name);
    const std::string GetStringByName(const std::string &name);

    static StringPuller *GetInstance();
private:
    StringPuller();
    rapidjson::Document m_loadedLang;
};

}

#endif // TRANSLATHORG_STRING_PULLER_H
