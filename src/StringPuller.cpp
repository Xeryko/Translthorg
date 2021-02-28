#include "StringPuller.h"

#include <iostream>
#include <rapidjson/filereadstream.h>
#include <rapidjson/pointer.h>

namespace th
{

static StringPuller *s_instance = nullptr;

StringPuller::StringPuller()
{
    char buffer[2048];
    const char filePath[] = "lang/fr-fr.json";
    FILE *fp = fopen(filePath, "r");
    if (!fp)
    {
        std::cout << "Error retrieving : " << filePath << std::endl;
    }
    else
    {
        rapidjson::FileReadStream fs(fp, buffer, sizeof(buffer));
        m_loadedLang.ParseStream(fs);
    }
}

const std::string StringPuller::GetStringByName(const char *name)
{
    if (rapidjson::Value *targetValue = rapidjson::Pointer(name).Get(m_loadedLang))
    {
        return targetValue->GetString();
    }
    return "";
}

const std::string StringPuller::GetStringByName(const std::string &name)
{
    return GetStringByName(name.c_str());
}

StringPuller *StringPuller::GetInstance()
{
    if (s_instance == nullptr)
        s_instance = new StringPuller;
    return s_instance;
}

}
