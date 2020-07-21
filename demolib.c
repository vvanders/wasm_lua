#include <lauxlib.h>
/* use emscripten to execute javascript */
#include "emscripten.h"

EM_JS(void, js_alert, (const char* message), {
    alert(UTF8ToString(message));
});

static int lua_alert(lua_State* L) {
    size_t len = 0;
    const char * message = lua_tolstring(L, 1, &len);
    js_alert(message);
    return 0;
}