#ifndef LUAREGISTRY_H
#define LUAREGISTRY_H
#include <sol/sol.hpp>
#include <vector>
#include <string>
#include <set>

class LuaRegistry {
    sol::state lua;
    std::set<std::string> scriptPaths;
    void loadScript(const std::string& scriptPath);
    std::string getScriptCode(const std::string& scriptPath);
public:
    LuaRegistry();
    sol::state& getState();
    void addScript(const std::string& scriptPath);
    void reloadScripts();

    template <typename T, typename... Args>
    T get(const std::string& functionName, Args&&... args) {
        sol::function luaFunction = lua[functionName];
        sol::protected_function_result result = luaFunction(std::forward<Args>(args)...);
        if (!result.valid()) {
            sol::error err = result;
            std::cerr << "Lua error: " << err.what() << std::endl;
            return T();
        }
        sol::optional<T> returnValue = result.get<sol::optional<T>>();
        if (!returnValue || !returnValue.value().valid()) {
            std::cerr << "Lua function return value not of the correct type" << std::endl;
            return T();
        }
        return returnValue.value();
    }

    template <typename T = void, typename... Args>
    void execute(const std::string& functionName, Args&&... args) {
        sol::function luaFunction = lua[functionName];
        sol::protected_function_result result = luaFunction(std::forward<Args>(args)...);
        if (!result.valid()) {
            sol::error err = result;
            std::cerr << "Lua error: " << err.what() << std::endl;
        }
    }

};

#endif // !LUAREGISTRY_H
