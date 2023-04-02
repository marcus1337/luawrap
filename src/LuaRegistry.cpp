#include "LuaRegistry.h"
#include <fstream>
#include <sstream>

void LuaRegistry::addScript(const std::string& scriptPath) {
    loadScript(scriptPath);
    scriptPaths.insert(scriptPath);
}

void LuaRegistry::reloadScripts() {
    for (const auto& scriptPath : scriptPaths) {
        loadScript(scriptPath);
    }
}

void LuaRegistry::loadScript(const std::string& scriptPath) {
    auto codeStr = getScriptCode(scriptPath);
    auto result = lua.safe_script(codeStr, sol::script_pass_on_error);
    if (!result.valid()) {
        const sol::optional<sol::error>& err = result;
        std::cerr << "Error loading script: " << err->what() << std::endl;
    }
}

sol::state& LuaRegistry::getState() {
    return lua;
}

std::string LuaRegistry::getScriptCode(const std::string& scriptPath) {
    std::ifstream file(scriptPath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
