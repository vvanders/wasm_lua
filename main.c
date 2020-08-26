#include <stdio.h>
#include "lua.h"
#include <lauxlib.h>
#include <lualib.h>
#include "demolib.c"

int run_lua(const char* script) {
	lua_State* lua = luaL_newstate();

	/* register demo library written in C, and call javascript */
	lua_register(lua,"alert",lua_alert); // lua_alert function defined in demolib.c

	luaL_openlibs(lua);

	int res = luaL_dostring(lua, script);

	size_t len = 0;
	const char* value = lua_tolstring(lua, lua_gettop(lua), &len);

	printf("return value: %s\n", value);

	lua_close(lua);

	return 0;
}