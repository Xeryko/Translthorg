#include <iostream>
#include <locale>

#include <rapidjson/rapidjson.h>

// rapidjson/example/simpledom/simpledom.cpp`
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <iostream>

#include <translathorg.h>

int main()
{
    std::wcout << "User-preferred locale setting is " << std::locale("").name().c_str() << '\n';
    // on startup, the global locale is the "C" locale
    std::wcout << 1000.01 << '\n';
    // replace the C++ global locale as well as the C locale with the user-preferred locale
    std::locale::global(std::locale(""));
    // use the new global locale for future wide character output
    std::wcout.imbue(std::locale());
    // output the same number again
    std::wcout << 1000.01 << '\n';

    // 1. Parse a JSON string into DOM.
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    rapidjson::Document d;
    d.Parse(json);

    // 2. Modify it by DOM.
    rapidjson::Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);

    // 3. Stringify the DOM
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    d.Accept(writer);

    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;

    th::StringPuller *translater = th::StringPuller::GetInstance();
    std::cout << "Application Name : " << translater->GetStringByName(std::string("/APPLICATION_NAME")) << std::endl;
    std::cout << "Language Name : " << translater->GetStringByName(std::string("/LANGUAGE_NAME")) << std::endl;
    return 0;
}
