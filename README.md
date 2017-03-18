# wasm_lua
Lua VM running in your browser!

Open [here](https://cdn.rawgit.com/vvanders/wasm_lua/d68f46a8/main.html), if it works you should see "Hello Lua!".

Each update is executed in a unique VM instance via WASM + emscripten.

# Why?
[Lua](https://en.wikipedia.org/wiki/Lua_(programming_language)) is a fast, highly embeddable VM that boasts a wide set of features allowing it to be adapted to a diverse set of domains and platforms.

* It can be run in 400kb of memory or less.
* Multi-paradigm via metatables, closures and coroutines.
* Robust, proven VM that's shipped on platforms including MIPS, x86, ARM and many others(and now WASM!).
* Small, easy to understand language.
* Extensible debugger hooks for easy on-target debugging.

Thanks to [rawgit](http://rawgit.com/) for hosting.
