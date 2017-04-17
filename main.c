#include <stdio.h>
#include "lua.h"
#include <lauxlib.h>
#include <lualib.h>

int run_lua(const char* script) {
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	int res = luaL_dostring(L, script);

	size_t len = 0;
	const char* value = lua_tolstring(L, lua_gettop(L), &len);

	printf("%s\n", value);

	lua_close(L);

	return 0;
}
