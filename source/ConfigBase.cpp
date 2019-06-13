#include "ConfigBase.h"

namespace CppConfig {

ConfigBase *ConfigBase::_instance = nullptr;

// ────────────────────────────────────────────────────────────────────────────────────────────── //
ConfigBase::ConfigBase() {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
ConfigBase::~ConfigBase() {
    if ( _instance ) {
        delete _instance;
    }
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                             Methods                                            //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ConfigBase::_setUpInstance() {
    if ( !isFileExist ( _instance->absoluteFilePath() ) ) {
        std::cout << "Config file not exist. Try to create default" << std::endl;
        _instance->saveConfig();
        return;
    }
    std::cout << "Try to load config file.." << std::endl;
    _instance->loadConfig();
    if ( _instance->isConfigChanged() ) {
        std::cout << "Config structure changed, need to override !";
        _instance->saveConfig();
    }
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ConfigBase::isFileExist ( const std::string &path ) {
    std::ifstream file ( path );
    if ( !file.is_open() ) {
        return false;
    }
    file.close();
    return true;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ConfigBase::loadConfig () {
    auto configContent = _loadFileToStr();
    if ( configContent.empty() ) {
        return false;
    }
    auto json = _buildJsonValueFromStr ( configContent );
    _rootGroup()->fromJson ( json );
    return true;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
std::string ConfigBase::_loadFileToStr () {
    std::ifstream file ( absoluteFilePath() );
    if ( !file.is_open() ) {
        std::cout << "Can't load file: '" << absoluteFilePath() << "'. Probably file not exist" << std::endl;
        return std::string();
    }
    std::stringstream fileContent;
    fileContent << file.rdbuf();
    return fileContent.str();
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
Json::Value ConfigBase::_buildJsonValueFromStr ( const std::string &str ) {
    auto builder = Json::CharReaderBuilder();
    auto *reader = builder.newCharReader();
    auto json = Json::Value();
    auto errors = std::string();
    auto parsingSuccessful = reader->parse ( str.c_str(), str.c_str() + str.size(), &json, &errors );
    delete reader;
    if ( !parsingSuccessful ) {
        std::cout << "Failed to parse the JSON, errors:" << errors << std::endl;
        return Json::Value();
    }
    return json;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ConfigBase::isConfigChanged() {
    auto fileContent = _loadFileToStr();
    auto rootContent = _rootGroup()->toJson().toStyledString();
    auto fileCrc = _calculateCrc ( fileContent );
    auto rootCrc = _calculateCrc ( rootContent );
    return fileCrc != rootCrc;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
uint32_t ConfigBase::_calculateCrc ( const std::string &data ) {
    uint32_t crc = 0;
    for ( auto sign : data ) {
        crc += static_cast<uint8_t> ( sign );
    }
    return crc;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ConfigBase::saveConfig () {
    std::ofstream file;
    file.open ( absoluteFilePath() );
    if ( !file.is_open() ) {
        std::cout << "Can't save file: '" << absoluteFilePath() << std::endl;
        return false;
    }
    std::string json = _rootGroup()->toJson().toStyledString();
    file.write ( &json[0], static_cast<long> ( json.size() ) );
    file.close();
    return true;
}


} // CppConfig
