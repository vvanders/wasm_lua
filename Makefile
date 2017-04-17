
LUA_RELEASE=5.3.4
LUA_SRC=lua-$(LUA_RELEASE)/src
LUA_LIB=$(LUA_SRC)/liblua.a

all: main.wasm

main.wasm: main.c $(LUA_LIB)
	emcc -I$(LUA_SRC) main.c $(LUA_LIB) -s WASM=1 -O2 -o main.js -s EXPORTED_FUNCTIONS="['_run_lua']"

$(LUA_LIB):
	make -C $(LUA_SRC) liblua.a CC="emcc -s WASM=1"
