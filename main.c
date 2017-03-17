#include <stdio.h>
#include "lua.h"
#include <lauxlib.h>
#include <lualib.h>

int main(int argc, char** argv) {
	lua_State* lua = luaL_newstate();
	luaL_openlibs(lua);

	int res = luaL_dostring(lua,
"function main ()\n"
"	print(\"bar\")\n"
"	return \"foo\"\n"
"end\n"
"return main()");

	printf("res: %d %d\n", res, lua_gettop(lua));

	size_t len = 0;
	const char* value = lua_tolstring(lua, lua_gettop(lua), &len);

	printf("l %d\n", len);
	printf("%s", value);

	lua_close(lua);

	return 0;
}