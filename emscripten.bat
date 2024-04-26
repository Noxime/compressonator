IF EXIST build (rmdir build /s /q)
mkdir build

call emcmake cmake -DLIB_BUILD_CORE=ON -DLIB_BUILD_COMPRESSONATOR_SDK=ON . -B build/ -G "Unix Makefiles"
cd build
call make -j12

call emcc -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=134217728 -sASSERTIONS=1 -pthread -O3 -g lib/libCMP_Compressonator.a ../wasm-target.cpp -o lib/project.html

cd ..
call caddy run