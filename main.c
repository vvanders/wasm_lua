#include "lua.h"
#include <lauxlib.h>
#include <lualib.h>

int run_lua(const char* script) {
	size_t len;
	const char* value;
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	(void)luaL_dostring(L, script);

	value = lua_tolstring(L, lua_gettop(L), &len);
	lua_writestring(value, len);
	lua_writeline();

	lua_close(L);
	return 0;
}
